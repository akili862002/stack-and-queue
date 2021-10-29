#include <iostream>
#include "./stack.cpp"

int main() {
    Stack<int>* stackA = new Stack<int>(5);
    Stack<int>* stackB = new Stack<int>();

    stackB->top();
    stackB->empty();
    stackB->size();

    stackA->push(1);
    stackA->push(2);
    stackA->push(3);
    stackA->push(4);
    stackA->push(5);

    stackB->push(7);
    stackB->push(8);
    stackB->push(9);
    stackB->push(10);

    stackA->top();
    stackA->empty();
    stackA->size();

    std::cout << "Stack A: " << stackA->toString() << std::endl;
    std::cout << "Stack B: " << stackB->toString() << std::endl;
    stackA->swap(stackB);
    std::cout << "Stack A: " << stackA->toString() << std::endl;
    std::cout << "Stack B: " << stackB->toString() << std::endl;
    std::cout << "Stack A: " << stackA->reverse()->toString() << std::endl;
    std::cout << "Stack B: " << stackB->reverse()->toString() << std::endl;

    delete stackA;
    delete stackB;
    return 0;
}