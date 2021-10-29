#include <string>
#include <algorithm>
#include "./queue.h"

template<typename T> Queue<T>::Queue() {
    this->_capacity = 0;
    this->_rear = -1;
    this->arr = nullptr;
}

template<typename T> Queue<T>::Queue(std::size_t capacity) {
    this->_capacity = capacity;
    this->_rear = -1;
    this->arr = new T[capacity];
}

template<typename T> Queue<T>::~Queue() {
    delete this->arr;
}

template<typename T> T Queue<T>::front() const {
    if(this->_rear == -1) {
        return T();
    }
    return *(this->arr + 0);
}

template<typename T> T Queue<T>::rear() const {
    if(this->_rear == -1) {
        return T();
    }
    return *(this->arr + this->_rear);
}

template<typename T> bool Queue<T>::empty() const {
    return this->_rear == -1;
}

template<typename T> std::size_t Queue<T>::size() const {
    return this->_rear + 1;
}

template<typename T> std::size_t Queue<T>::capacity() const {
    return this->_capacity;
}

template<typename T> Queue<T>* Queue<T>::enqueue(T value) {
    if(this->_rear + 1 == this->_capacity) {
        if(this->_capacity == 0) {
            this->_capacity = 1;
        } else {
            this->_capacity <<= 1;
        }
        T* new_arr = new T[this->_capacity];
        if(this->arr != nullptr) {
            std::copy(this->arr, this->arr + this->_rear + 1, new_arr);
            delete this->arr;
        }
        this->arr = new_arr;
    }
    *(this->arr + ++this->_rear) = value;
    return this;
}

template<typename T> Queue<T>* Queue<T>::dequeue() {
    for(std::size_t i = 0; i != this->_rear; ++i) {
        *(this->arr + i) = *(this->arr + i + 1);
    }
    --this->_rear;
    return this;
}

template<typename T> Queue<T>* Queue<T>::swap(Queue<T>* stack) {
    T* arr = this->arr;
    this->arr = stack->arr;
    stack->arr = arr;

    T temp = this->_rear;
    this->_rear = stack->_rear;
    stack->_rear = temp;
    
    temp = this->_capacity;
    this->_capacity = stack->_capacity;
    stack->_capacity = temp;
    return this;
}

template<typename T> std::string Queue<T>::toString() const {
    std::string output = "";
    for(std::size_t i = 0, size = this->_rear + 1; i != size; ++i) {
        output += std::to_string(*(this->arr + i)) + " ";
    }
    output += (this->empty() ? ("(empty)") : ("(size " + std::to_string(this->size()) + ")"));
    return output;
}

template<typename T> Queue<T>* Queue<T>::reverse() {
    T temp;
    for(std::size_t i = 0, size = std::size_t(this->size() / 2); i != size; ++i) {
        temp = *(this->arr + i);
        *(this->arr + i) = *(this->arr + this->_rear - i);
        *(this->arr + this->_rear - i) = temp;
    }
    return this;
}