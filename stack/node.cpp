#include "./node.h"

template<typename T> Node<T>::Node() {
    this->value = 0;
    this->prev = nullptr;
}

template<typename T> Node<T>::Node(T value) {
    this->value = value;
    this->prev = nullptr;
}

template<typename T> Node<T>::Node(T value, Node* prev) {
    this->value = value;
    this->prev = prev;
}

template<typename T> T Node<T>::getValue() const {
    return this->value;
}

template<typename T> Node<T>* Node<T>::getPrev() const {
    return this->prev;
}

template<typename T> Node<T>* Node<T>::setValue(T value) {
    this->value = value;
    return this;
}

template<typename T> Node<T>* Node<T>::setPrev(Node* prev) {
    this->prev = prev;
    return this;
}
