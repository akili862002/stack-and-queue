#include <iostream>
#include <string>
#include "./stack.h"
#include "./node.cpp"

template<typename T> Stack<T>::Stack() {
    this->_top = nullptr;
}

template<typename T> Stack<T>::Stack(Node<T>* top) {
    this->_top = top;
}

template<typename T> Stack<T>::~Stack() {
    Node<T>* temp;
    for(Node<T>* i = this->_top; i != nullptr; i = temp) {
        temp = i->getPrev();
        delete i;
    }
}

template<typename T> T Stack<T>::top() const {
    if(this->_top == nullptr) {
        return T();
    }
    return this->_top->getValue();
}

template<typename T> Stack<T>* Stack<T>::setTop(Node<T>* node) {
    if(this->_top != nullptr) {
        node->setPrev(this->_top);
    }
    this->_top = node;
    return this;
}

template<typename T> bool Stack<T>::empty() const {
    return this->_top == nullptr;
}

template<typename T> std::size_t Stack<T>::size() const {
    std::size_t cnt = 0;
    if(this->_top != nullptr) {
        for(Node<T>* i = this->_top; i != nullptr; i = i->getPrev()) {
            cnt++;
        }
    }
    return cnt;
}

template<typename T> Stack<T>* Stack<T>::push(T value) {
    Node<T>* node = new Node<T>(value);
    if(this->_top != nullptr) {
        node->setPrev(this->_top);
    }
    this->_top = node;
    return this;
}

template<typename T> Stack<T>* Stack<T>::pop() {
    if(this->_top == nullptr) {
        throw std::runtime_error("pop an empty stack");
    }
    Node<T>* temp = this->_top;
    this->_top = this->_top->getPrev();
    delete temp;
    return this;
}

template<typename T> Stack<T>* Stack<T>::swap(Stack<T>* stack) {
    Node<T>* temp = this->_top;
    this->_top = stack->_top;
    stack->_top = temp;
    return this;
}

template<typename T> std::string Stack<T>::toString() const {
    std::string output = "";
    for(Node<T>* i = this->_top; i != nullptr; i = i->getPrev()) {
        output += std::to_string(i->getValue()) + " ";
    }
    output += (this->empty() ? ("(empty)") : ("(size " + std::to_string(this->size()) + ")"));
    return output;
}

template<typename T> void __reverse(Stack<T>* stack, Node<T>* node, Node<T>* next) {
    if(node->getPrev() != nullptr) {
        __reverse(stack, node->getPrev(), node);
    } else {
        stack->setTop(node);
    }
    node->setPrev(next);
}

template<typename T> Stack<T>* Stack<T>::reverse() {
    if(this->_top == nullptr) {
        return this;
    }

    __reverse<T>(this, this->_top, nullptr);
    return this;
}