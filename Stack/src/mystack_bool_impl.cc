
namespace my_stack
{

MyStack<bool>::MyStack(): capacity_(DEFAULT_CAPACITY), size_(0), data_(new unsigned char[(size_t)std::ceil(capacity_ / CHAR_BIT)]) {}

MyStack<bool>::MyStack(size_t capacity): capacity_(capacity), size_(0), data_(new unsigned char[(size_t)std::ceil(capacity_ / CHAR_BIT)]) {}

MyStack<bool>::MyStack(const MyStack& other): capacity_(other.capacity_), size_(other.size_)  
{
    data_ = new unsigned char[(size_t)std::ceil(capacity_ / CHAR_BIT)];    
    std::copy(other.data_, other.data_ + (size_t)std::ceil(size_ / CHAR_BIT), data_);
}

MyStack<bool>::MyStack(MyStack<bool>&& other) noexcept
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
    data_ = new unsigned char[(size_t)std::ceil(capacity_ / CHAR_BIT)];    
    std::copy(other.data_, other.data_ + (size_t)std::ceil(size_ / CHAR_BIT), data_);
    return *this;
}

const MyStack<bool>& MyStack<bool>::operator=(MyStack<bool>&& other) noexcept
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

void MyStack<bool>::push(bool elem)
{
    if (is_full())
    {
        capacity_ = std::ceil(capacity_ * RESIZE_COEFF);
        unsigned char* allocated_memory = new unsigned char[(size_t)std::ceil(capacity_ / CHAR_BIT)];
        std::copy(data_, data_ + (size_t)std::ceil(size_ / CHAR_BIT), allocated_memory);
        delete[] data_;
        data_ = allocated_memory;  
    }
    if (elem)
    {
        data_[(size_t)std::ceil(size_ / CHAR_BIT)] |= elem << ((size_ - 1) % CHAR_BIT);
    }
    else
    {
        data_[(size_t)std::ceil(size_ / CHAR_BIT)] &= elem << ((size_ - 1) % CHAR_BIT);
    }
    size_++;
}

void MyStack<bool>::pop()
{
    if (!is_empty())
    {
        size_--;
    }
    else
    {
        std::cout << "CALLING POP FOR EMPTY STACK!!!"<<std::endl;
        exit(EXIT_FAILURE);
    }
}

bool MyStack<bool>::top() const
{
    if (!is_empty()) 
    {
        return (data_[(size_t)std::ceil(size_ / CHAR_BIT) - 1] & (1 << ((size_ - 1) % CHAR_BIT))) >> ((size_ - 1) % CHAR_BIT); //?????????????
    }
    std::cout << "CALLING TOP FOR EMPTY STACK!!!"<<std::endl;
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

size_t MyStack<bool>::get_size() const
{
    return size_;
}

size_t MyStack<bool>::get_capacity() const
{
    return capacity_;
}

MyStack<bool>::~MyStack()
{
    delete[] data_;
}

} // namespace my_stack
