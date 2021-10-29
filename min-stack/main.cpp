#include <iostream>
#include "./min-stack.cpp"

int main() {
    MinStack<int>* stack = new MinStack<int>();
    std::cout << stack->push(4)->toString() << "; min = " << stack->min() << std::endl;
    std::cout << stack->push(6)->toString() << "; min = " << stack->min() << std::endl;
    std::cout << stack->push(2)->toString() << "; min = " << stack->min() << std::endl;
    std::cout << stack->push(3)->toString() << "; min = " << stack->min() << std::endl;
    std::cout << stack->push(1)->toString() << "; min = " << stack->min() << std::endl;
    while(!stack->empty()) {
        std::cout << stack->pop()->toString() << "; min = " << stack->min() << std::endl;
    }
    delete stack;
    std::cout << "ok";
    return 0;
}