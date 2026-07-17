#include "stack.hpp"

#include <iostream>

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

    if( is_empty(stack) ){
        stack->top = new_node;
        ++(stack->size);
        return;
    }
    new_node->next = stack->top;
    stack->top = new_node;

    ++(stack->size);
}

void pop(Stack* stack){
    if( is_empty(stack) ){
        std::cout << "pop(): Stack is empty\n";
        return;
    }
    Node* temp{ stack->top };
    stack->top = stack->top->next;

    delete temp;
    --(stack->size);
}

void pop_all(Stack* stack){
    if( is_empty(stack) ){
        std::cout << "pop_all(): Stack is empty\n";
        return;
    }
    Node* curr{ stack->top };

    while (curr != nullptr){
        Node* temp{ curr };
        curr = curr->next;

        delete temp;
    }
    stack->top = nullptr;
    stack->size = 0;
}

void peek(Stack* stack){
    if ( is_empty(stack) ){
        std::cout << "nullptr\n";
    } else {
        std::cout << stack->top->value << '\n';
    }
}

void peek_all(Stack* stack){
    Node* curr{ stack->top };

    while (curr != nullptr){
        std::cout << curr->value << " <- ";
        curr = curr->next;
    }
    std::cout << "nullptr\n";
}

bool is_empty(Stack* stack){
    return stack->top == nullptr;
}

std::size_t stack_size(Stack* stack){
    return stack->size;
}
