#ifndef _STACK_H_INCLUDED_
#define _STACK_H_INCLUDED_
#include <string>

template<typename T> class Stack {
    private:
        std::size_t _capacity;
        std::size_t _top;
        T* arr;
    public:
        Stack(std::size_t);
        ~Stack();
        T top() const;
        Stack* setTop(std::size_t);
        bool empty() const;
        bool full() const;
        std::size_t size() const;
        std::size_t capacity() const;
        Stack* push(T);
        Stack* pop();
        Stack* swap(Stack<T>*);
        std::string toString() const;
        Stack* reverse();
};

#endif