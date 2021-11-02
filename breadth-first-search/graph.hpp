#ifndef _GRAPH_HPP_INCLUDED_
#define _GRAPH_HPP_INCLUDED_
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "node.hpp"
#include "../queue-dynamic/queue.cpp"

template<typename T> class Graph {
	private:
		Node<T>** nodes;
		std::size_t _capacity;
		std::size_t _size;
	public:
		Graph() : nodes(nullptr), _capacity(0), _size(0) {}
		Graph(std::string input) : nodes(nullptr), _capacity(0), _size(0) {
			std::stringstream stream(input);
			std::string line;
			std::map<T, Node<T>*> node;
			T value;
			T adjacency;
			while(std::getline(stream, line) && !line.empty()) {
				std::stringstream s(line);
				s >> value;
				if(node.count(value) == 0) {
					node[value] = new Node<T>(value);
				}
				for(; !s.eof();) {
					s >> adjacency;
					if(node.count(adjacency) == 0) {
						node[adjacency] = new Node<T>(adjacency);
					}
					node[value]->addAdjacency(node[adjacency]);
				}
				if(this->nodes == nullptr) {
					this->nodes = new Node<T>*[1]{nullptr};
					this->_capacity = 1;
				} else if(this->_size == this->_capacity) {
					std::size_t old = this->_capacity;
					this->_capacity <<= 1;
					Node<T>** new_nodes = new Node<T>*[this->_capacity]{nullptr};
					for(std::size_t i = 0; i != old; ++i) {
						*(new_nodes + i) = *(this->nodes + i);
					}
					delete this->nodes;
					this->nodes = new_nodes;
				}
				*(this->nodes + this->_size++) = node[value];
			}
		}
		std::string traverseToString() {
			std::string result = "";
			std::map<Node<T>*, bool> visited;
			Queue<Node<T>*>* queue = new Queue<Node<T>*>();
			for(std::size_t i = 0; i != this->_size; ++i) {
				if(visited.count(*(this->nodes + i)) == 1) continue;
				queue->enqueue(*(this->nodes + i));
				while(!queue->empty()) {
					Node<T>* node = queue->front();
					queue->dequeue();
					if(visited.count(node) == 1) continue;
					visited[node] = true;
					result += std::to_string(node->value()) + " ";
					for(std::size_t j = 0; j != node->size(); ++j) {
						if(visited.count((*(node->adjacency() + j))) == 1) continue;
						queue->enqueue((*(node->adjacency() + j)));
					}
				}
				result += "\n";
			}
			return result;
		}
};

#endif
