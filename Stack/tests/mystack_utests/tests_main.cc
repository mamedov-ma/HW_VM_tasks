#include <gtest/gtest.h>
#include "mystack.hh"

using namespace my_stack;


template <typename T>
class MyStackTest: public ::testing::Test {};

typedef testing::Types<bool, char, signed char, unsigned char, 
short, unsigned short, int, unsigned int, long, unsigned long, 
long long, unsigned long long, float, double, long double> TestTypes; 

TYPED_TEST_SUITE(MyStackTest, TestTypes);


TYPED_TEST(MyStackTest, DefaultConstructorTest)
{
    MyStack<TypeParam> stack;
    EXPECT_EQ(stack.get_capacity(), 8);
    EXPECT_EQ(stack.get_size(), 0);
}

TYPED_TEST(MyStackTest, ExplicitConstructorTest)
{
    MyStack<TypeParam> stack(10);
    EXPECT_EQ(stack.get_capacity(), 10);
    EXPECT_EQ(stack.get_size(), 0);
}

TYPED_TEST(MyStackTest, CopyConstructorTest)
{
    MyStack<TypeParam> stack_1(10);
    MyStack<TypeParam> stack_2(stack_1);
    EXPECT_EQ(stack_2.get_capacity(), 10);
    EXPECT_EQ(stack_2.get_size(), 0);
}

TYPED_TEST(MyStackTest, MoveConstructorTest)
{
    
}

TYPED_TEST(MyStackTest, AssignmentOperatorTest)
{
    MyStack<TypeParam> stack_1;
    MyStack<TypeParam> stack_2(10);
    stack_1 = stack_2;
    EXPECT_EQ(stack_1.get_capacity(), 10);
    EXPECT_EQ(stack_1.get_size(), 0);
}

TYPED_TEST(MyStackTest, MoveAssignmentOperatorTest)
{

}

TYPED_TEST(MyStackTest, PushTest)
{
    MyStack<TypeParam> stack;
    stack.push((TypeParam)1);
    EXPECT_EQ(stack.get_size(), 1); 
}

TYPED_TEST(MyStackTest, PopTest)
{
    MyStack<TypeParam> stack;
    stack.push((TypeParam)1);
    std::cout << stack.get_size() << std::endl;
    std::cout << stack.is_empty() << std::endl;
    std::cout << stack.is_full() << std::endl;
    stack.pop();
    EXPECT_EQ(stack.get_size(), 0);
}

TYPED_TEST(MyStackTest, TopTest)
{
    MyStack<TypeParam> stack;
    stack.push((TypeParam)1);
    EXPECT_EQ(stack.top(), (TypeParam)1);
}

TYPED_TEST(MyStackTest, IsEmptyTest)
{
    MyStack<TypeParam> stack;
    EXPECT_EQ(stack.is_empty(), true);
    stack.push((TypeParam)1);
    EXPECT_EQ(stack.is_empty(), false); 
}

TYPED_TEST(MyStackTest, IsFullTest)
{
    MyStack<TypeParam> stack(1);
    EXPECT_EQ(stack.is_full(), false);
    stack.push((TypeParam)1);
    EXPECT_EQ(stack.is_full(), true); 
}

TYPED_TEST(MyStackTest, GetSizeTest)
{
    MyStack<TypeParam> stack(100);
    EXPECT_EQ(stack.get_size(), (size_t)0); 
}
TYPED_TEST(MyStackTest, GetCapacityTest)
{
    MyStack<TypeParam> stack(100);
    EXPECT_EQ(stack.get_capacity(), (size_t)100); 
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}