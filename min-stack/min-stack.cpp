#include "./min-stack.h"
#include "../stack-dynamic/stack.cpp"

template<typename T> MinStack<T>::MinStack() : Stack<T>::Stack() {
    this->min_stack = new Stack<T>();
}

template<typename T> MinStack<T>::MinStack(std::size_t capacity) : Stack<T>::Stack(capacity) {
    this->min_stack = new Stack<T>(capacity);
}

template<typename T> MinStack<T>::~MinStack() {
    delete this->min_stack;
}

template<typename T> MinStack<T>* MinStack<T>::push(T value) {
    Stack<T>::push(value);
    if(this->min_stack->empty() || value <= this->min_stack->top()) {
        this->min_stack->push(value);
    }
    return this;
}

template<typename T> MinStack<T>* MinStack<T>::pop() {
    if(!this->empty()) {
        if(*(this->arr + this->_top) == this->min_stack->top()) {
            this->min_stack->pop();
        }
    }
    Stack<T>::pop();
    return this;
}

template<typename T> T MinStack<T>::min() {
    if(this->min_stack->empty()) {
        return T();
    }
    return this->min_stack->top();
}