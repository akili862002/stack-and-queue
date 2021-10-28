#include "./node.h"

template<typename T> Node<T>::Node() {
    this->value = 0;
    this->next = nullptr;
}

template<typename T> Node<T>::Node(T value) {
    this->value = value;
    this->next = nullptr;
}

template<typename T> Node<T>::Node(T value, Node* next) {
    this->value = value;
    this->next = next;
}

template<typename T> T Node<T>::getValue() const {
    return this->value;
}

template<typename T> Node<T>* Node<T>::getNext() const {
    return this->next;
}

template<typename T> Node<T>* Node<T>::setValue(T value) {
    this->value = value;
    return this;
}

template<typename T> Node<T>* Node<T>::setNext(Node* next) {
    this->next = next;
    return this;
}
