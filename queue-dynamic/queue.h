#ifndef _QUEUE_H_INCLUDED 
#define _QUEUE_H_INCLUDED 
#include <string>

template<class T> class Queue {
    protected:
        std::size_t _front;
        std::size_t _rear;
        std::size_t _capacity;
        std::size_t _size;
        T* arr;
    public:
        Queue();
        Queue(std::size_t);
        ~Queue();
        inline void __resize();
        T front() const;
        T rear() const;
        bool empty() const;
        std::size_t size() const;
        std::size_t capacity() const;
        Queue* enqueue(T);
        Queue* dequeue();
        Queue* swap(Queue<T>*);
        std::string toString() const;
        std::string toBeautifulString() const;
        Queue* reverse();
};

#endif