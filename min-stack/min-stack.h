#ifndef _MIN_STACK_H_INCLUDED_
#define _MIN_STACK_H_INCLUDED_
#include "../stack-dynamic/stack.h"

template<typename T> class MinStack : public Stack<T> {
    protected:
        Stack<T>* min_stack;
    public:
        MinStack();
        MinStack(std::size_t);
        ~MinStack();
        MinStack* push(T value);
        MinStack* pop();
        T min();
};

#endif