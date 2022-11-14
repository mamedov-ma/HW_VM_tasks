#include <gtest/gtest.h>

#include "mystack.hh"
#include <vector>
#include <string>

template <typename T>
class MyStackTest: public ::testing::Test {};

using TestTypes = testing::Types<bool, char, long long, 
unsigned long long, float, double, long double, std::vector<std::string>>; 

TYPED_TEST_SUITE(MyStackTest, TestTypes);

TYPED_TEST(MyStackTest, DefaultConstructorTest)
{
    my_stack::MyStack<TypeParam> stack;
    EXPECT_EQ(stack.get_capacity(), static_cast<size_t>(8));
    EXPECT_EQ(stack.get_size(), static_cast<size_t>(0));
}

TYPED_TEST(MyStackTest, ExplicitConstructorTest)
{
    my_stack::MyStack<TypeParam> stack(static_cast<size_t>(10));
    EXPECT_EQ(stack.get_capacity(), static_cast<size_t>(10));
    EXPECT_EQ(stack.get_size(), static_cast<size_t>(0));
}

TYPED_TEST(MyStackTest, CopyConstructorTest)
{
    my_stack::MyStack<TypeParam> stack_1(static_cast<size_t>(10));
    my_stack::MyStack<TypeParam> stack_2(stack_1);
    EXPECT_EQ(stack_2.get_capacity(), static_cast<size_t>(10));
    EXPECT_EQ(stack_2.get_size(), static_cast<size_t>(0));
}

TYPED_TEST(MyStackTest, MoveConstructorTest)
{
    my_stack::MyStack<TypeParam> stack_1;
    my_stack::MyStack<TypeParam> stack_2(std::move(stack_1));
    EXPECT_EQ(stack_2.get_size(), 0);
}

TYPED_TEST(MyStackTest, AssignmentOperatorTest)
{
    my_stack::MyStack<TypeParam> stack_1;
    my_stack::MyStack<TypeParam> stack_2(10);
    stack_1 = stack_2;
    EXPECT_EQ(stack_1.get_capacity(), 10);
    EXPECT_EQ(stack_1.get_size(), 0);
}

TYPED_TEST(MyStackTest, MoveAssignmentOperatorTest)
{
    my_stack::MyStack<TypeParam> stack_1;
    my_stack::MyStack<TypeParam> stack_2;
    stack_1 = std::move(stack_2);
    EXPECT_EQ(stack_1.get_size(), 0);
}

TYPED_TEST(MyStackTest, PushTest)
{
    my_stack::MyStack<TypeParam> stack;
    stack.push(static_cast<TypeParam>(1));
    EXPECT_EQ(stack.get_size(), 1); 
}

TYPED_TEST(MyStackTest, PopTest)
{
    my_stack::MyStack<TypeParam> stack;
    stack.push(static_cast<TypeParam>(1));
    std::cout << stack.get_size() << std::endl;
    std::cout << stack.is_empty() << std::endl;
    std::cout << stack.is_full() << std::endl;
    stack.pop();
    EXPECT_EQ(stack.get_size(), 0);
}

TYPED_TEST(MyStackTest, TopTest)
{
    my_stack::MyStack<TypeParam> stack;
    stack.push(static_cast<TypeParam>(1));
    EXPECT_EQ(stack.top(), static_cast<TypeParam>(1));
}

TYPED_TEST(MyStackTest, IsEmptyTest)
{
    my_stack::MyStack<TypeParam> stack;
    EXPECT_EQ(stack.is_empty(), true);
    stack.push(static_cast<TypeParam>(1));
    EXPECT_EQ(stack.is_empty(), false); 
}

TYPED_TEST(MyStackTest, IsFullTest)
{
    my_stack::MyStack<TypeParam> stack(1);
    EXPECT_EQ(stack.is_full(), false);
    stack.push(static_cast<TypeParam>(1));
    EXPECT_EQ(stack.is_full(), true); 
}

TYPED_TEST(MyStackTest, GetSizeTest)
{
    my_stack::MyStack<TypeParam> stack(100);
    EXPECT_EQ(stack.get_size(), static_cast<size_t>(0)); 
}
TYPED_TEST(MyStackTest, GetCapacityTest)
{
    my_stack::MyStack<TypeParam> stack(100);
    EXPECT_EQ(stack.get_capacity(), static_cast<size_t>(100)); 
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}