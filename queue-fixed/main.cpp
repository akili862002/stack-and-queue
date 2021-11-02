#include <iostream>
#include "./queue.cpp"

int main() {
    Queue<int>* queueA = new Queue<int>(3);

    std::cout << "queue A: " << queueA->enqueue(1)->toString() << std::endl;
    std::cout << "queue A: " << queueA->enqueue(2)->toString() << std::endl;
    std::cout << "queue A: " << queueA->dequeue()->toString() << std::endl;
    std::cout << "queue A: " << queueA->dequeue()->toString() << std::endl;
    std::cout << "queue A: " << queueA->enqueue(3)->toString() << std::endl;
    std::cout << "queue A: " << queueA->enqueue(4)->toString() << std::endl;
    std::cout << "queue A: " << queueA->enqueue(5)->toString() << std::endl;
    std::cout << "queue A: " << queueA->reverse()->toString() << std::endl;
    std::cout << "queue A: " << queueA->dequeue()->toString() << std::endl;
    std::cout << "queue A: " << queueA->dequeue()->toString() << std::endl;
    std::cout << "queue A: " << queueA->dequeue()->toString() << std::endl;

    delete queueA;
    return 0;
}
