#ifndef _STACK_H_INCLUDED_
#define _STACK_H_INCLUDED_
#include <string>
#include "./node.h"

template<class T> class Queue {
    private:
        Node<T>* _front;
        Node<T>* _rear;
    public:
        Queue();
        Queue(Node<T>*);
        Queue(Node<T>*, Node<T>*);
        ~Queue();
        T front() const;
        T rear() const;
        bool empty() const;
        std::size_t size() const;
        Queue* enqueue(T);
        Queue* dequeue();
        Queue* swap(Queue<T>*);
        std::string toString() const;
};

#endif