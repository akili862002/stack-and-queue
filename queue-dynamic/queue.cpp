#include <iostream>
#include <string>
#include <algorithm>
#include "./queue.h"

template<typename T> Queue<T>::Queue() {
    this->_rear = -1;
    this->_front = -1;
    this->_capacity = 0;
    this->_size = 0;
    this->arr = nullptr;
}

template<typename T> Queue<T>::Queue(std::size_t capacity) {
    this->_rear = -1;
    this->_front = -1;
    this->_capacity = capacity;
    this->_size = 0;
    this->arr = new T[capacity]{T()};
}

template<typename T> Queue<T>::~Queue() {
    delete this->arr;
}

template<typename T> inline void Queue<T>::__resize() {
    std::size_t old = this->_capacity;
    std::size_t iter_front = this->_front;
    if(this->_capacity == 0) {
        this->_capacity = 1;
    } else {
        this->_capacity <<= 1;
    }
    T* new_arr = new T[this->_capacity]{T()};
    if(this->_front > this->_rear) {
        this->_front = (this->_capacity - old + this->_front) % this->_capacity;
    }
    for(std::size_t i = this->_front; i != 1; i = (i + 1) % this->_capacity) {
        *(new_arr + i) = *(this->arr + iter_front);
        iter_front = (iter_front + 1) % old;
    }
    for(std::size_t i = this->_rear; i != 0; --i) {
        *(new_arr + i) = *(this->arr + i);
    }
    delete this->arr;
    this->arr = new_arr;
}

template<typename T> T Queue<T>::front() const {
    if(this->_front == -1) {
        return T();
    }
    return *(this->arr + this->_front);
}

template<typename T> T Queue<T>::rear() const {
    if(this->_rear == -1) {
        return T();
    }
    return *(this->arr + this->_rear);
}

template<typename T> bool Queue<T>::empty() const {
    return this->_size == 0;
}

template<typename T> std::size_t Queue<T>::size() const {
    return this->_size;
}

template<typename T> std::size_t Queue<T>::capacity() const {
    return this->_capacity;
}

template<typename T> Queue<T>* Queue<T>::enqueue(T value) {
    if(this->_capacity == 0) {
        this->_capacity = 1;
        this->arr = new T[1]{T()};
    } else if(this->_size == this->_capacity) {
        this->__resize();
    }
    if(this->_rear == -1) {
        this->_front = 0;
        this->_rear = 0;
    } else {
        this->_rear = (this->_rear + 1) % this->_capacity;
    }
    *(this->arr + this->_rear) = value;
    ++this->_size;
    return this;
}

template<typename T> Queue<T>* Queue<T>::dequeue() {
    if(this->_size == 0) {
        throw std::runtime_error("dequeue an empty queue");
    }
    this->_front = (this->_front + 1) % this->_capacity;
    --this->_size;
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

    temp = this->_size;
    this->_size = stack->_size;
    stack->_size = temp;
    return this;
}

template<typename T> std::string Queue<T>::toString() const {
    std::string output = "";
    if(this->_size == 0) {
        output = "(empty)";
    } else {
        for(std::size_t i = 0; i != this->_capacity; ++i) {
            output += std::to_string(*(this->arr + i)) + " ";
        }
        output += "(size " + std::to_string(this->size()) + ")";
    }
    return output;
}

template<typename T> std::string Queue<T>::toBeautifulString() const {
    std::string output = "";
    if(this->_size == 0) {
        output = "(empty)";
    } else {
        for(std::size_t i = this->_front, size = (this->_rear + 1) % this->_capacity; ;) {
            output += std::to_string(*(this->arr + i)) + " ";
            i = (i + 1) % this->_capacity;
            if(i == size) {
                break;
            }
        }
        output += "(size " + std::to_string(this->size()) + ")";
    }
    return output;
}

template<typename T> Queue<T>* Queue<T>::reverse() {
    T temp;
    for(std::size_t i = 0, size = std::size_t(this->size() / 2); i != size; ++i) {
        temp = *(this->arr + (this->_front + i) % this->_capacity);
        *(this->arr + (this->_front + i) % this->_capacity) = *(this->arr + (this->_rear - i) % this->_capacity);
        *(this->arr + (this->_rear - i) % this->_capacity) = temp;
    }
    return this;
}