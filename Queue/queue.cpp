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

void init_queue(Queue* queue){
    queue->front = nullptr;
    queue->rear = nullptr;
    queue->size = 0;
}

void enqueue(Queue* queue, int value){
    Node* new_node{ create_node(value) };

    if(queue->front == nullptr){
        queue->front = new_node;
        queue->rear = new_node;
        ++(queue->size);
        return;
    }

    queue->rear->next = new_node;
    queue->rear = new_node;
    ++(queue->size);
}

void dequeue(Queue* queue){
    if (queue->front == nullptr){
        std::cout << "dequeue(): Queue is empty\n";
        return;
    }
    Node* temp{ queue->front };
    queue->front = queue->front->next;
    --(queue->size);

    delete temp;

    if(queue->front == nullptr){
        queue->rear = nullptr;
    }
}

void print_queue(Queue* queue){
    Node* curr{ queue->front };
    while(curr != nullptr){
        std::cout << curr->value << " <- ";
        curr = curr->next;
    }

    std::cout << "nullptr\n";
}