#ifndef _NODE_H_INCLUDED_
#define _NODE_H_INCLUDED_

template <typename T> class Node {
    private:
        T value;
        Node* next;
    public:
        Node();
        Node(T);
        Node(T, Node*);
        T getValue() const;
        Node* getNext() const;
        Node* setValue(T);
        Node* setNext(Node*);
};

#endif