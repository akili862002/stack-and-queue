#include <iostream>
#include "./queue.cpp"

int main() {
    Queue<int>* queueA = new Queue<int>();

    std::cout << "queue A: " << queueA->enqueue(1)->toBeautifulString() << std::endl;
    std::cout << "queue A: " << queueA->enqueue(2)->toBeautifulString() << std::endl;
    std::cout << "queue A: " << queueA->enqueue(3)->toBeautifulString() << std::endl;
    std::cout << "queue A: " << queueA->dequeue()->toBeautifulString() << std::endl;
    std::cout << "queue A: " << queueA->dequeue()->toBeautifulString() << std::endl;
    std::cout << "queue A: " << queueA->dequeue()->toBeautifulString() << std::endl;
    std::cout << "queue A: " << queueA->enqueue(4)->toBeautifulString() << std::endl;
    std::cout << "queue A: " << queueA->enqueue(5)->toBeautifulString() << std::endl;
    std::cout << "queue A: " << queueA->enqueue(6)->toBeautifulString() << std::endl;
    std::cout << "queue A: " << queueA->enqueue(7)->toBeautifulString() << std::endl;
    std::cout << "queue A: " << queueA->dequeue()->toBeautifulString() << std::endl;
    std::cout << "queue A: " << queueA->dequeue()->toBeautifulString() << std::endl;
    std::cout << "queue A: " << queueA->dequeue()->toBeautifulString() << std::endl;
    std::cout << "queue A: " << queueA->dequeue()->toBeautifulString() << std::endl;

    delete queueA;
    return 0;
}
