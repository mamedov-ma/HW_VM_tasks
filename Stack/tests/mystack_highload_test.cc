#include <cassert>
#include "mystack.hh"

int main()
{
    const size_t DATA_SIZE = 1000000;

    my_stack::MyStack<int> test_stack;

    for (int i = 0; i < DATA_SIZE; ++i)
    {
        test_stack.push(i);
        assert(test_stack.top() == i);
    }
 
    assert(test_stack.get_size() == DATA_SIZE);

    return 0;
}

