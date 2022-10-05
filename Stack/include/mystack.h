#include <iostream>



namespace my_stack
{

template <typename T> 
class MyStack
{
    public:

        MyStack();
        explicit MyStack(size_t capacity);
        MyStack(const MyStack& other);
        MyStack(MyStack&& other);
        ~MyStack();

        const MyStack& operator=(const MyStack& other);
        const MyStack& operator=(MyStack&& other);

        const T& top() const;
        void push(T);
        void pop();

        bool is_empty() const;
        bool is_full() const;

        size_t get_size() const;
        size_t get_capacity() const;

    public:

        const size_t DEFAULT_STACK_SIZE = 100;
        const int RESIZE_COEFF = 2;

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
    if (data_ == other.data_)
    {
        return *this;
    }
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
    if (!is_empty()) 
    {
        return data_[size_ - 1];
    }
    exit(EXIT_FAILURE);
}

template <typename T>
void MyStack<T>::push(T node)
{
    if (is_full())
    {
        capacity_ *= RESIZE_COEFF;
        T* allocated_memory = new T[capacity_];
        std::copy(data_, data_ + size_, allocated_memory);
        delete[] data_;
        data_ = allocated_memory;  
    }
    data_[size_] = node;
    size_++;
}

template <typename T>
void MyStack<T>::pop()
{
    if (!is_empty())
    {
        size_--;
    }
    exit(EXIT_FAILURE);
}

template <typename T>
bool MyStack<T>::is_empty() const
{
    return size_ == 0;
}
    
template <typename T>
bool MyStack<T>::is_full() const
{
    return size_ == capacity_;
}

template <typename T>
MyStack<T>::~MyStack()
{
    delete[] data_;
}

} // namespace my_stack