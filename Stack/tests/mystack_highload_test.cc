#include <cassert>
#include "mystack.hh"

using namespace my_stack;

int main()
{
    size_t data_size = 0;
    std::cin >> data_size;

    MyStack<float> test_stack;
    float elem;

    for (size_t i = 0; i < data_size; ++i)
    {
        std::cin >> elem;
        test_stack.push(elem);
    }
    
    assert(test_stack.get_size() == data_size);

    return 0;
}

