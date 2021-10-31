#ifndef _DEQUEUE_H_INCLUDED 
#define _DEQUEUE_H_INCLUDED 
#include <string>

template<class T> class Dequeue {
    private:
        inline void __resize();
    protected:
        std::size_t _front;
        std::size_t _rear;
        std::size_t _capacity;
        T* arr;
    public:
        Dequeue();
        Dequeue(std::size_t);
        ~Dequeue();
        T front() const;
        T rear() const;
        bool empty() const;
        std::size_t size() const;
        std::size_t capacity() const;
        Dequeue* pushFront(T);
        Dequeue* pushRear(T);
        Dequeue* popFront();
        Dequeue* popRear();
        Dequeue* dequeue();
        Dequeue* swap(Dequeue<T>*);
        std::string toString() const;
        Dequeue* reverse();
};

#endif