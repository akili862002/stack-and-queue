#ifndef _NODE_H_INCLUDED_
#define _NODE_H_INCLUDED_

template <typename T> class Node {
    private:
        T value;
        Node* prev;
    public:
        Node();
        Node(T);
        Node(T, Node*);
        T getValue() const;
        Node* getPrev() const;
        Node* setValue(T);
        Node* setPrev(Node*);
};

#endif