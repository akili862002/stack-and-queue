#ifndef _QUEUE_H_INCLUDED 
#define _QUEUE_H_INCLUDED 
#include <string>
#include "./node.h"

template<class T> class Queue {
    private:
        Node<T>* _front;
        Node<T>* _rear;
        std::size_t _size;
    public:
        Queue();
        Queue(Node<T>*);
        ~Queue();
        T front() const;
        T rear() const;
        Queue<T>* setFront(Node<T>*);
        Queue<T>* setRear(Node<T>*);
        bool empty() const;
        std::size_t size() const;
        Queue* enqueue(T);
        Queue* dequeue();
        Queue* swap(Queue<T>*);
        std::string toString() const;
        Queue* reverse();
};

#endif