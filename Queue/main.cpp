#include "queue.hpp"

#include <iostream>
#define LOG(x) std::cout << x << '\n';

int main(){
    Queue queue;
    Queue* main_queue{ &queue };

    init_queue(main_queue);
    enqueue(main_queue, 10);
    print_queue(main_queue);

    enqueue(main_queue, 20);
    print_queue(main_queue);
    
    enqueue(main_queue, 30);
    print_queue(main_queue);

    dequeue(main_queue);
    print_queue(main_queue);

    dequeue(main_queue);
    print_queue(main_queue);

    dequeue(main_queue);

    LOG(main_queue->size);
    LOG(main_queue->front);
    LOG(main_queue->rear);

    return 0;
}