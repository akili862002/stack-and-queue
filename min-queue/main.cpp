#include <iostream>
#include "./min-queue.cpp"

int main() {
    MinQueue<int>* queue = new MinQueue<int>();
    std::cout << queue->toString() << "; min = " << queue->min() << std::endl;
    std::cout << queue->enqueue(2)->toString() << "; min = " << queue->min() << std::endl;
    std::cout << queue->enqueue(3)->toString() << "; min = " << queue->min() << std::endl;
    std::cout << queue->enqueue(1)->toString() << "; min = " << queue->min() << std::endl;
    std::cout << queue->enqueue(4)->toString() << "; min = " << queue->min() << std::endl;
    std::cout << queue->enqueue(5)->toString() << "; min = " << queue->min() << std::endl;
    while(!queue->empty()) {
        std::cout << queue->dequeue()->toString() << "; min = " << queue->min() << std::endl;
    }
    delete queue;
    std::cout << "ok";
    return 0;
}