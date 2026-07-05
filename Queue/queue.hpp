#include <iostream>

struct Node {
    Node* next;
    int value;
};

struct Queue {
    Node* front;
    Node* rear;
    std::size_t size;
};

Node* create_node(int value);
void init_queue(Queue* queue);
void enqueue(Queue* queue, int value);
void dequeue(Queue* queue);
void print_queue(Queue* queue);
Node* search(Queue* queue, int key);