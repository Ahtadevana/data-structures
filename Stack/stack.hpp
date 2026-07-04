#pragma once

#include <iostream>

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