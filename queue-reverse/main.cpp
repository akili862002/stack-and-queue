#include <iostream>
#include "../queue/queue.cpp"

int main() {
    Queue<int>* queue = new Queue<int>();
    queue->enqueue(1)->enqueue(2)->enqueue(3)->enqueue(4);

    std::cout << queue->dequeue()->toString() << std::endl;
    std::cout << queue->reverse()->dequeue()->toString() << std::endl;
    return 0;
}