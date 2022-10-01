#include <stdio.h>



namespace my_stack
{

template <typename T>
class MyStack
{

    public:
        const int DEFAULT_STACK_SIZE = 100;

        MyStack();
        MyStack(const MyStack& other);
        MyStack(MyStack&& other);
        ~MyStack();

        const MyStack& operator=(const MyStack& other);
        const MyStack& operator=(MyStack&& other);

        const T& top() const;

        bool is_empty() const;
        bool is_full() const;

        void push(T);
        void pop();

        




    private:

        int size;
        T* data;

};






} // namespace my_stack