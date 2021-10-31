#include <iostream>
#include <string>
#include <algorithm>
#include "./stack.h"

template<typename T> Stack<T>::Stack() {
    this->_capacity = 0;
    this->_top = -1;
    this->arr = nullptr;
}

template<typename T> Stack<T>::Stack(std::size_t capacity) {
    this->_capacity = capacity;
    this->_top = -1;
    this->arr = new T[capacity];
}

template<typename T> Stack<T>::~Stack() {
    delete this->arr;
}

template<typename T> T Stack<T>::top() const {
    if(this->_top == -1) {
        return T();
    }
    return *(this->arr + this->_top);
}

template<typename T> bool Stack<T>::empty() const {
    return this->_top == -1;
}

template<typename T> std::size_t Stack<T>::size() const {
    return this->_top + 1;
}

template<typename T> std::size_t Stack<T>::capacity() const {
    return this->_capacity;
}

template<typename T> Stack<T>* Stack<T>::push(T value) {
    if(this->_top + 1 == this->_capacity) {
        if(this->_capacity == 0) {
            this->_capacity = 1;
        } else {
            this->_capacity <<= 1;
        }
        T* new_arr = new T[this->_capacity];
        if(this->arr != nullptr) {
            std::copy(this->arr, this->arr + this->_top + 1, new_arr);
            delete this->arr;
        }
        this->arr = new_arr;
    }
    this->arr[++this->_top] = value;
    return this;
}

template<typename T> Stack<T>* Stack<T>::pop() {
    if(this->_top == -1) {
        throw std::runtime_error("pop an empty stack");
    }
    --this->_top;
    return this;
}

template<typename T> Stack<T>* Stack<T>::swap(Stack<T>* stack) {
    T* temp = this->arr;
    this->arr = stack->arr;
    stack->arr = temp;

    std::size_t temp2 = this->_capacity;
    this->_capacity = stack->_capacity;
    stack->_capacity = temp2;

    temp2 = this->_top;
    this->_top = stack->_top;
    stack->_top = temp2;
    return this;
}

template<typename T> std::string Stack<T>::toString() const {
    std::string output = "";
    for(std::size_t i = this->_top; i != -1; --i) {
        output += std::to_string(*(this->arr + i)) + " ";
    }
    output += (this->empty() ? ("(empty)") : ("(size " + std::to_string(this->size()) + ")"));
    return output;
}

template<typename T> Stack<T>* Stack<T>::reverse() {
    if(this->_top == -1) {
        return this;
    }

    T temp;
    for(std::size_t i = 0, size = std::size_t((this->_top + 1) / 2); i != size; ++i) {
        temp = *(this->arr + i);
        *(this->arr + i) = *(this->arr + this->_top - i);
        *(this->arr + this->_top - i) = temp;
    }
    return this;
}