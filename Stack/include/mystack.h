#include <iostream>



namespace my_stack
{

template <typename T> 
class MyStack
{
    public:
        
        const size_t DEFAULT_STACK_SIZE = 100;

        MyStack();
        MyStack(size_t capacity);
        MyStack(const MyStack& other);
        MyStack(MyStack&& other);

        const MyStack& operator=(const MyStack& other);
        const MyStack& operator=(MyStack&& other);

        const T& top() const;

        void push(T);
        void pop();

        bool is_empty() const;
        bool is_full() const;

        ~MyStack();

    private:

        size_t capacity_;
        size_t size_;
        T* data_;
};


} // namespace my_stack




namespace my_stack
{

template <typename T>
MyStack<T>::MyStack(): capacity_(DEFAULT_STACK_SIZE), size_(0), data_(new T[capacity_]) {}

template <typename T>
MyStack<T>::MyStack(size_t capacity): capacity_(capacity), size_(0), data_(new T[capacity_]) {}

template <typename T>
MyStack<T>::MyStack(const MyStack& other): capacity_(other.capacity_), size_(other.size_)  
{
    data_ = new T[capacity_];    
    std::copy(other.data_, other.data_ + size_, data_);
}

template <typename T>
MyStack<T>::MyStack(MyStack<T>&& other)
{
    capacity_ = other.capacity_;
    size_ = other.size_;
    data_ = other.data_;
    other.data_ = nullptr;
}

template <typename T>
const MyStack<T>& MyStack<T>::operator=(const MyStack<T>& other)
{
    if (data_ == other.data_)
    {
        return *this;
    }
    size_ = other.size_;
    capacity_ = other.capacity_;
    delete[] data_;
    data_ = new T[size_];    
    std::copy(other.data_, other.data_ + size_, data_);
    return *this;
}

template <typename T>
const MyStack<T>& MyStack<T>::operator=(MyStack<T>&& other)
{
 
    size_ = other.size_;
    capacity_ = other.capacity_;
    delete[] data_;
    data_ = other.data_;
    other.data_ = nullptr;
    return *this;
}

template <typename T>
const T& MyStack<T>::top() const
{
    return 0;

}

template <typename T>
void MyStack<T>::push(T)
{

}

template <typename T>
void MyStack<T>::pop()
{

}

template <typename T>
bool MyStack<T>::is_empty() const
{
    return 0;
}
    
template <typename T>
bool MyStack<T>::is_full() const
{
    return 0;
}

template <typename T>
MyStack<T>::~MyStack()
{
    delete[] data_;
}

} // namespace my_stack