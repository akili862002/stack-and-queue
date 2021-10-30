#ifndef _MIN_QUEUE_H_INCLUDED_
#define _MIN_QUEUE_H_INCLUDED_
#include "../queue-dynamic/queue.h"

template<typename T> class MinQueue : public Queue<T> {
    protected:
        Queue<T>* min_queue;
    public:
        MinQueue();
        MinQueue(std::size_t);
        ~MinQueue();
        MinQueue* enqueue(T);
        MinQueue* dequeue();
        T min();
};

#endif
