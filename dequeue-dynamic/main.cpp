#include <iostream>
#include "./dequeue.cpp"

int main() {
    Dequeue<int>* queueA = new Dequeue<int>(4);

    std::cout << "queue A: " << queueA->pushFront(1)->toString() << std::endl;
    std::cout << "queue A: " << queueA->pushFront(2)->toString() << std::endl;
    std::cout << "queue A: " << queueA->pushFront(3)->toString() << std::endl;
    std::cout << "queue A: " << queueA->pushFront(4)->toString() << std::endl;
    std::cout << "queue A: " << queueA->pushFront(5)->toString() << std::endl;
    std::cout << "queue A: " << queueA->pushFront(6)->toString() << std::endl;
    std::cout << "queue A: " << queueA->pushFront(7)->toString() << std::endl;
    std::cout << "queue A: " << queueA->pushFront(8)->toString() << std::endl;
    std::cout << "queue A: " << queueA->pushFront(9)->toString() << std::endl;
    std::cout << "queue A: " << queueA->popFront()->toString() << std::endl;
    std::cout << "queue A: " << queueA->popFront()->toString() << std::endl;
    std::cout << "queue A: " << queueA->popFront()->toString() << std::endl;
    std::cout << "queue A: " << queueA->popFront()->toString() << std::endl;
    std::cout << "queue A: " << queueA->popFront()->toString() << std::endl;
    std::cout << "queue A: " << queueA->popFront()->toString() << std::endl;
    std::cout << "queue A: " << queueA->popFront()->toString() << std::endl;
    std::cout << "queue A: " << queueA->popFront()->toString() << std::endl;
    std::cout << "queue A: " << queueA->popFront()->toString() << std::endl;

    delete queueA;
    std::cout << "ok";
    return 0;
}
