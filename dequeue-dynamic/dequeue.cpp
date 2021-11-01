#include <string>
#include <algorithm>
#include "./dequeue.h"

template<typename T> inline void Dequeue<T>::__resize() {
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

template<typename T> Dequeue<T>::Dequeue() {
    this->_capacity = 0;
    this->_front = -1;
    this->_rear = 0;
    this->arr = nullptr;
}

template<typename T> Dequeue<T>::Dequeue(std::size_t capacity) {
    this->_capacity = capacity;
    this->_front = -1;
    this->_rear = 0;
    this->arr = new T[capacity]{T()};
}

template<typename T> Dequeue<T>::~Dequeue() {
    delete this->arr;
}

template<typename T> T Dequeue<T>::front() const {
    if(this->_front == -1) {
        return T();
    }
    return *(this->arr + this->_front);
}

template<typename T> T Dequeue<T>::rear() const {
    if(this->_rear == -1) {
        return T();
    }
    return *(this->arr + this->_rear);
}

template<typename T> bool Dequeue<T>::empty() const {
    return (this->_front == -1);
}

template<typename T> std::size_t Dequeue<T>::size() const {
    return (this->_capacity - this->_front + this->_rear) % this->_capacity + 1;
}

template<typename T> std::size_t Dequeue<T>::capacity() const {
    return this->_capacity;
}

template<typename T> Dequeue<T>* Dequeue<T>::pushFront(T value) {
    if((this->_front ? this->_front : this->_capacity) - 1 == this->_rear) {
        this->__resize();
    }
    if(this->_front == -1) {
        this->_front = 0;
        this->_rear = 0;
    } else {
        this->_front = (this->_front ? this->_front : this->_capacity) - 1;
    }
    *(this->arr + this->_front) = value;
    return this;
}

template<typename T> Dequeue<T>* Dequeue<T>::pushRear(T value) {
    if((this->_front ? this->_front : this->_capacity) - 1 == this->_rear) {
        this->__resize();
    }
    if(this->_front == -1) {
        this->_front = 0;
        this->_rear = 0;
    } else {
        this->_rear = (this->_rear + 1) % this->_capacity;
    }
    *(this->arr + this->_rear) = value;
    return this;
}

template<typename T> Dequeue<T>* Dequeue<T>::popFront() {
    *(this->arr + this->_front) = T();
    if(this->_front == this->_rear) {
        this->_front = -1;
        this->_rear = -1;
    } else {
        this->_front = (this->_front + 1) % this->_capacity;
    }
    return this;
}

template<typename T> Dequeue<T>* Dequeue<T>::popRear() {
    *(this->arr + this->_rear) = T();
    if(this->_front == this->_rear) {
        this->_front = -1;
        this->_rear = -1;
    } else {
        this->_rear = (this->_rear ? this->_rear : this->_capacity) - 1;
    }
    return this;
}

template<typename T> Dequeue<T>* Dequeue<T>::swap(Dequeue<T>* stack) {
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

template<typename T> std::string Dequeue<T>::toString() const {
    std::string output = "[" + std::to_string(this->_front) + ", " + std::to_string(this->_rear) + "] ";
    if(this->empty()) {
        output = "(empty)";
    } else {
        for(std::size_t i = 0; i != this->_capacity; ++i) {
            output += std::to_string(*(this->arr + i)) + " ";
        }
        // for(std::size_t i = this->_front, size = this->_rear - 1; i != size; i = (i ? i : this->_capacity) - 1) {
        //     output += std::to_string(*(this->arr + i)) + " ";
        // }
        output += "(size " + std::to_string(this->size()) + ")";
        if((this->_front ? this->_front : this->_capacity) - 1 == this->_rear) {
            output += " -> full";
        }
    }

    return output;
}

template<typename T> Dequeue<T>* Dequeue<T>::reverse() {
    T temp;
    for(std::size_t i = 0, size = std::size_t(this->size() / 2); i != size; ++i) {
        temp = *(this->arr + i);
        *(this->arr + i) = *(this->arr + this->_rear - i);
        *(this->arr + this->_rear - i) = temp;
    }
    return this;
}