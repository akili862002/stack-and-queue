#include <string>
#include "./queue.h"
#include "./node.cpp"

template<class T> Queue<T>::Queue() {
    this->_front = nullptr;
    this->_rear = nullptr;
}

template<class T> Queue<T>::Queue(Node<T>* front) {
    this->_front = front;
    this->_rear = nullptr;
}

template<class T> Queue<T>::Queue(Node<T>* front, Node<T>* rear) {
    this->_front = front;
    this->_rear = rear;
}

template<class T> Queue<T>::~Queue() {
    Node<T>* temp;
    for(Node<T>* i = this->_front; i != nullptr; i = temp) {
        temp = i->getNext();
        delete i;
    }
}

template<class T> T Queue<T>::front() const {
    return this->_front;
}

template<class T> bool Queue<T>::empty() const {
    return this->_front == nullptr;
}

template<class T> std::size_t Queue<T>::size() const {
    std::size_t cnt = 0;
    if(this->_front != nullptr) {
        for(Node<T>* i = this->_front; i != nullptr; i = i->getNext()) {
            cnt++;
        }
    }
    return cnt;
}

template<class T> Queue<T>* Queue<T>::enqueue(T value) {
    Node<T>* node = new Node<T>(value);
    if(this->_front == nullptr) {
        this->_front = node;
    } else {
        if(this->_rear == nullptr) {
            this->_rear = node;
            this->_front->setNext(this->_rear);
        } else {
            this->_rear->setNext(node);
            this->_rear = node;
        }
    }
    return this;
}

template<class T> Queue<T>* Queue<T>::dequeue() {
    if(this->_front != nullptr) {
        Node<T>* temp = this->_front;
        this->_front = this->_front->getNext();
        delete temp;
    }
    return this;
}

template<class T> Queue<T>* Queue<T>::swap(Queue<T>* stack) {
    Node<T>* temp = this->_front;
    this->_front = stack->_front;
    stack->_front = temp;
    return this;
}

template<class T> std::string Queue<T>::toString() const {
    std::string output = "";
    for(Node<T>* i = this->_front; i != nullptr; i = i->getNext()) {
        output += std::to_string(i->getValue()) + " ";
    }
    output += (this->empty() ? ("(empty)") : ("(size " + std::to_string(this->size()) + ")"));
    return output;
}
