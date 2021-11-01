#include <string>
#include "./queue.h"
#include "./node.cpp"

template<typename T> Queue<T>::Queue() {
    this->_size = 0;
    this->_front = nullptr;
    this->_rear = nullptr;
}

template<typename T> Queue<T>::Queue(Node<T>* front) {
    this->_size = 1;
    this->_front = front;
    this->_rear = nullptr;
    for(Node<T>* i = this->_front->getNext(); i != nullptr; i = i->getNext()) {
        this->_rear = i;
        ++this->_size;
    }
}

template<typename T> Queue<T>::~Queue() {
    Node<T>* temp;
    for(Node<T>* i = this->_front; i != nullptr; i = temp) {
        temp = i->getNext();
        delete i;
    }
}

template<typename T> T Queue<T>::front() const {
    if(this->_front == nullptr) {
        return T();
    }
    return this->_front->getValue();
}

template<typename T> T Queue<T>::rear() const {
    if(this->_rear == nullptr) {
        return T();
    }
    return this->_rear->getValue();
}

template<typename T> Queue<T>* Queue<T>::setFront(Node<T>* node) {
    if(this->_front != nullptr) {
        node->setNext(this->_front);
    }
    this->_front = node;
    return this;
}

template<typename T> Queue<T>* Queue<T>::setRear(Node<T>* node) {
    if(this->_rear != nullptr) {
        this->_rear->setNext(node);
    }
    this->_rear = node;
    return this;
}

template<typename T> bool Queue<T>::empty() const {
    return this->_front == nullptr;
}

template<typename T> std::size_t Queue<T>::size() const {
    return this->_size;
}

template<typename T> Queue<T>* Queue<T>::enqueue(T value) {
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
    ++this->_size;
    return this;
}

template<typename T> Queue<T>* Queue<T>::dequeue() {
    if(this->_front == nullptr) {
        throw std::runtime_error("dequeue an empty queue");
    }
    Node<T>* temp = this->_front;
    this->_front = this->_front->getNext();
    delete temp;
    --this->_size;
    return this;
}

template<typename T> Queue<T>* Queue<T>::swap(Queue<T>* queue) {
    Node<T>* temp = this->_front;
    this->_front = queue->_front;
    queue->_front = temp;

    temp = this->_rear;
    this->_rear = queue->_rear;
    queue->_rear = temp;
    return this;
}

template<typename T> std::string Queue<T>::toString() const {
    std::string output = "";
    for(Node<T>* i = this->_front; i != nullptr; i = i->getNext()) {
        output += std::to_string(i->getValue()) + " ";
    }
    output += (this->empty() ? ("(empty)") : ("(size " + std::to_string(this->size()) + ")"));
    return output;
}

template<typename T> void __reverse(Node<T>* node, Node<T>* prev) {
    if(node->getNext() != nullptr) {
        __reverse(node->getNext(), node);
    }
    node->setNext(prev);
}

template<typename T> Queue<T>* Queue<T>::reverse() {
    __reverse<T>(this->_front, nullptr);
    Node<T>* temp;
    temp = this->_front;
    this->_front = this->_rear;
    this->_rear = temp;
    return this;
}