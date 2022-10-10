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

        void push(T);
        void pop();
        T top() const;
        
        bool is_empty() const;
        bool is_full() const;

        size_t get_size() const;
        size_t get_capacity() const;

    public:

        static constexpr size_t DEFAULT_CAPACITY = 8;
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

        void push(bool);
        void pop();
        bool top() const;
        
        bool is_empty() const;
        bool is_full() const;

        size_t get_size() const;
        size_t get_capacity() const;

    public:

        const size_t DEFAULT_CAPACITY = 8;
        static constexpr int RESIZE_COEFF = 2;

    private:

        size_t capacity_;
        size_t size_;
        unsigned char* data_;
};

} // namespace my_stack



#include "mystack_impl.hh"
#include "mystack_bool_impl.hh"