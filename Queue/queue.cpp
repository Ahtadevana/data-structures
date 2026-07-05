#include "queue.hpp"

#include <iostream>

/*
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
void* init_queue(Queue* queue);
void enqueue(Queue* queue, int value);
void dequeue(Queue* queue);
void print_queue(Queue* queue);
Node* search(Queue* queue, int key);
*/

Node* create_node(int value){
    Node* new_node{ new Node };

    new_node->next = nullptr;
    new_node->value = value;

    return new_node;
}

void* init_queue(Queue* queue){
    queue->front = nullptr;
    queue->rear = nullptr;
}