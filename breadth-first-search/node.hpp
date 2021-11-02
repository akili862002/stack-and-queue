#ifndef _NODE_HPP_INCLUDED_
#define _NODE_HPP_INCLUDED_
#include <iostream>
#include <string>

template<typename T> class Node {
	private:
		T _value;
		Node<T>** _adjacency;
		std::size_t _size;
		std::size_t _capacity;
	public:
		Node() : _value(T()), _adjacency(nullptr), _size(0), _capacity(0) {}
		Node(T value) : _value(value), _adjacency(nullptr), _size(0), _capacity(0) {}
		Node<T>** const adjacency() const { return this->_adjacency; }
		Node<T>* addAdjacency(Node<T>* const value) {
			if(this->_adjacency == nullptr) {
				this->_adjacency = new Node<T>*[1]{nullptr};
				this->_capacity = 1;
			} else if(this->_size == this->_capacity) {
				std::size_t old = this->_capacity;
				this->_capacity <<= 1;
				Node<T>** new_arr = new Node<T>*[this->_capacity]{nullptr};
				for(std::size_t i = 0; i != old; ++i) {
					*(new_arr + i) = *(this->_adjacency + i);
				}
				delete this->_adjacency;
				this->_adjacency = new_arr;
			}
			*(this->_adjacency + this->_size++) = value;
			return this;
		}
		std::size_t size() const { return this->_size; }
		std::size_t capacity() const { return this->_capacity; }
		const T value() const { return this->_value; }
		Node<T>* value(T const value) { this->_value = value; return this; }
};

#endif
