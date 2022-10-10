#include <gtest/gtest.h>
#include "mystack.hh"

using namespace my_stack;


template <typename T>
class MyStackTest: public ::testing::Test {};

typedef testing::Types<bool, char, signed char, unsigned char, 
wchar_t, short, unsigned short, int, unsigned int, long, unsigned long, 
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
    MyStack<TypeParam> stack_1;
    MyStack<TypeParam> stack_2(10);
    stack_1 = stack_2;
    EXPECT_EQ(stack_1.get_capacity(), 10);
    EXPECT_EQ(stack_1.get_size(), 0);
}

TYPED_TEST(MyStackTest, MoveConstructorTest)
{
    
}

TYPED_TEST(MyStackTest, AssignmentOperatorTest)
{

}

TYPED_TEST(MyStackTest, MoveAssignmentOperatorTest)
{

}

TYPED_TEST(MyStackTest, PushTest)
{

}

TYPED_TEST(MyStackTest, PopTest)
{

}

TYPED_TEST(MyStackTest, TopTest)
{

}

TYPED_TEST(MyStackTest, IsEmptyTest)
{

}

TYPED_TEST(MyStackTest, IsFullTest)
{

}

TYPED_TEST(MyStackTest, GetSizeTest)
{

}
TYPED_TEST(MyStackTest, GetCapacityTest)
{

}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}