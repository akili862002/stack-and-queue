#ifndef _STACK_H_INCLUDED_
#define _STACK_H_INCLUDED_
#include <string>
#include "./node.h"

template<class T> class Stack {
    private:
        Node<T>* _top;
    public:
        Stack();
        Stack(Node<T>*);
        ~Stack();
        T top() const;
        bool empty() const;
        std::size_t size() const;
        Stack* push(T);
        Stack* pop();
        Stack* swap(Stack<T>*);
        std::string toString() const;
};

#endif