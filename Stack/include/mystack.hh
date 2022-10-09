#pragma once
#include <iostream>
#include <climits>
#include <cmath>


namespace my_stack
{

template <typename T> 
class MyStack
{
    public:

        MyStack();
        explicit MyStack(size_t);
        MyStack(const MyStack&);
        MyStack(MyStack&&);
        ~MyStack();

        const MyStack& operator=(const MyStack&);
        const MyStack& operator=(MyStack&&);

        T top() const;
        void push(T);
        void pop();

        bool is_empty() const;
        bool is_full() const;

        size_t get_size() const;
        size_t get_capacity() const;

    public:

        const size_t DEFAULT_STACK_SIZE = 1;
        static constexpr int RESIZE_COEFF = 2;

    private:

        size_t capacity_;
        size_t size_;
        T* data_;
};


// MyStack specialization for bool type
template <> 
class MyStack<bool>
{
    public:

        MyStack();
        explicit MyStack(size_t);
        MyStack(const MyStack&);
        MyStack(MyStack&&);
        ~MyStack();

        const MyStack& operator=(const MyStack&);
        const MyStack& operator=(MyStack&&);

        bool top() const;
        void push(bool);
        void pop();

        bool is_empty() const;
        bool is_full() const;

        size_t get_size() const;
        size_t get_capacity() const;

    public:

        const size_t DEFAULT_STACK_SIZE = 8;
        static constexpr int RESIZE_COEFF = 2;

    private:

        size_t capacity_;
        size_t size_;
        unsigned char* data_;
};

} // namespace my_stack



#include "mystack_impl.hh"
#include "mystack_bool_impl.hh"