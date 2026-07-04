#include "stack.hpp"

#include <iostream>

/*
struct Node {
    Node* next;
    int value;
};

struct Stack {
    Node* top;
    std::size_t size;
};

Node* create_node(int value);

void init_stack(Stack* stack);
void push(Stack* stack, int value);

void pop(Stack* stack);
void pop_all(Stack* stack);

void peek(Stack* stack);
void peek_all(Stack* stack);

bool is_empty(Stack* stack);
std::size_t stack_size(Stack* stack);
*/

Node* create_node(int value){
    Node* new_node{ new Node };

    new_node->next = nullptr;
    new_node->value = value;

    return new_node;
}

void init_stack(Stack* stack){
    stack->top = nullptr;
    stack->size = 0;
}

void push(Stack* stack, int value){
    Node* new_node{ create_node(value) };

    if (stack->top == nullptr){
        stack->top = new_node;
        ++(stack->size);
        return;
    }

    stack->top = new_node;
}

void peek(Stack* stack){
    if(stack->top == nullptr){
        std::cout << "nullptr\n";

    } else {
        std::cout << stack->top->value << '\n';
    }
}