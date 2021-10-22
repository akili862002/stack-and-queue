#include <iostream>
#include "../stack/stack.cpp"

int main() {
    Stack<int>* stack = new Stack<int>();
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    stack->push(6);

    std::cout << stack->pop()->toString() << std::endl;
    std::cout << stack->reverse()->pop()->toString() << std::endl;
    return 0;
}