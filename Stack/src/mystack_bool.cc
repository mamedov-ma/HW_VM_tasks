#include "mystack.hh"



namespace my_stack
{

template <> 
class MyStack<bool>
{
    public:

        MyStack();
        explicit MyStack(size_t capacity);
        MyStack(const MyStack& other);
        MyStack(MyStack&& other);
        ~MyStack();

        const MyStack& operator=(const MyStack& other);
        const MyStack& operator=(MyStack&& other);

        bool top() const;
        void push(bool);
        void pop();

        bool is_empty() const;
        bool is_full() const;

        size_t get_size() const;
        size_t get_capacity() const;

    public:

        const size_t DEFAULT_STACK_SIZE = 8;
        const int RESIZE_COEFF = 2;

    private:

        size_t capacity_;
        size_t size_;
        unsigned char* data_;
};

} // namespace my_stack

namespace my_stack
{

MyStack<bool>::MyStack(): capacity_(DEFAULT_STACK_SIZE), size_(0), data_(new unsigned char[std::ceil(capacity_ / CHAR_BIT)]) {}

MyStack<bool>::MyStack(size_t capacity): capacity_(capacity), size_(0), data_(new unsigned char[std::ceil(capacity_ / CHAR_BIT)]) {}

MyStack<bool>::MyStack(const MyStack& other): capacity_(other.capacity_), size_(other.size_)  
{
    data_ = new unsigned char[std::ceil(capacity_ / CHAR_BIT)];    
    std::copy(other.data_, other.data_ + std::ceil(size_ / CHAR_BIT), data_);
}

MyStack<bool>::MyStack(MyStack<bool>&& other)   // EQUAL
{
    capacity_ = other.capacity_;
    size_ = other.size_;
    data_ = other.data_;
    other.data_ = nullptr;
}

const MyStack<bool>& MyStack<bool>::operator=(const MyStack<bool>& other)
{
    if (data_ == other.data_)
    {
        return *this;
    }
    size_ = other.size_;
    capacity_ = other.capacity_;
    delete[] data_;
    data_ = new unsigned char[std::ceil(capacity_ / CHAR_BIT)];    
    std::copy(other.data_, other.data_ + std::ceil(size_ / CHAR_BIT), data_);
    return *this;
}

const MyStack<bool>& MyStack<bool>::operator=(MyStack<bool>&& other)    // EQUAL
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

bool MyStack<bool>::top() const
{
    if (!is_empty()) 
    {
        return data_[size_ - 1];
    }
    exit(EXIT_FAILURE);
}

void MyStack<bool>::push(bool elem)
{
    if (is_full())
    {
        capacity_ *= RESIZE_COEFF;
        unsigned char* allocated_memory = new unsigned char[capacity_];
        std::copy(data_, data_ + size_, allocated_memory);
        delete[] data_;
        data_ = allocated_memory;  
    }
    data_[size_] = elem;
    size_++;
}


void MyStack<bool>::pop()
{
    if (!is_empty())
    {
        size_--;
    }
    exit(EXIT_FAILURE);
}

bool MyStack<bool>::is_empty() const
{
    return size_ == 0;
}
    
bool MyStack<bool>::is_full() const
{
    return size_ == capacity_;
}

MyStack<bool>::~MyStack()
{
    delete[] data_;
}

} // namespace my_stack