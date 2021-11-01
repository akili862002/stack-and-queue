#ifndef _STACK_H_INCLUDED_
#define _STACK_H_INCLUDED_
#include <string>
#include "./node.h"

template<typename T> class Stack {
    private:
        Node<T>* _top;
        std::size_t _size;
    public:
        Stack();
        Stack(Node<T>*);
        ~Stack();
        T top() const;
        Stack* setTop(Node<T>*);
        bool empty() const;
        std::size_t size() const;
        Stack* push(T);
        Stack* pop();
        Stack* swap(Stack<T>*);
        std::string toString() const;
        Stack* reverse();
};

#endif