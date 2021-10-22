#include "./node.h"

template<class T> Node<T>::Node() {
    this->value = 0;
    this->prev = nullptr;
}

template<class T> Node<T>::Node(T value) {
    this->value = value;
    this->prev = nullptr;
}

template<class T> Node<T>::Node(T value, Node* prev) {
    this->value = value;
    this->prev = prev;
}

template<class T> T Node<T>::getValue() const {
    return this->value;
}

template<class T> Node<T>* Node<T>::getPrev() const {
    return this->prev;
}

template<class T> Node<T>* Node<T>::setValue(T value) {
    this->value = value;
    return this;
}

template<class T> Node<T>* Node<T>::setPrev(Node* prev) {
    this->prev = prev;
    return this;
}
