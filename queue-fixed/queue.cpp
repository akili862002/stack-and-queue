#include <string>
#include "./queue.h"

template<typename T> Queue<T>::Queue(std::size_t capacity) {
    this->_capacity = capacity;
    this->_front = -1;
    this->_rear = -1;
    this->_size = 0;
    this->arr = new T[capacity]{T()};
}

template<typename T> Queue<T>::~Queue() {
    delete this->arr;
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
    return this->_rear == -1;
}

template<typename T> bool Queue<T>::full() const {
    return (this->_size == this->_capacity);
}

template<typename T> std::size_t Queue<T>::size() const {
    return this->_size;
}

template<typename T> std::size_t Queue<T>::capacity() const {
    return this->_capacity;
}

template<typename T> Queue<T>* Queue<T>::enqueue(T value) {
    if(this->_size == this->_capacity) {
        throw std::overflow_error("enqueue a full queue");
    } else {
        if(this->_rear == -1) {
            this->_front = 0;
            this->_rear = 0;
        } else {
            this->_rear = (this->_rear + 1) % this->_capacity;
        }
        *(this->arr + this->_rear) = value;
        ++this->_size;
    }
    return this;
}

template<typename T> Queue<T>* Queue<T>::dequeue() {
    if(this->_size == 0) {
        throw std::runtime_error("dequeue an empty queue");
    }
    *(this->arr + this->_front) = T();
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
        // for(std::size_t i = this->_front, size = (this->_rear + 1) % this->_capacity; ;) {
        //     output += std::to_string(*(this->arr + i)) + " ";
        //     i = (i + 1) % this->_capacity;
        //     if(i == size) break;
        // }
        output += "(size " + std::to_string(this->size()) + ")";
    }
    return output;
}

template<typename T> Queue<T>* Queue<T>::reverse() {
    T temp;
    for(std::size_t i = 0, size = std::size_t(this->size() / 2); i != size; ++i) {
        temp = *(this->arr + ((i + this->_front) % this->_capacity));
        *(this->arr + ((i + this->_front) % this->_capacity)) = *(this->arr + (this->_rear - i) % this->_capacity);
        *(this->arr + (this->_rear - i) % this->_capacity) = temp;
    }
    return this;
}