#include <iostream>
#include "./queue.cpp"

int main() {
    Queue<int>* queueA = new Queue<int>();
    Queue<int>* queueB = new Queue<int>();

    queueA->enqueue(1);
    queueA->enqueue(2);
    queueA->enqueue(3);
    queueA->enqueue(4);
    queueA->enqueue(5);

    queueB->enqueue(7);
    queueB->enqueue(8);
    queueB->enqueue(9);

    queueA->dequeue();

    std::cout << "queue A: " << queueA->toString() << std::endl;
    std::cout << "queue B: " << queueB->toString() << std::endl;
    queueA->swap(queueB);
    std::cout << "queue A: " << queueA->toString() << std::endl;
    std::cout << "queue B: " << queueB->toString() << std::endl;

    delete queueA;
    delete queueB;
    return 0;
}