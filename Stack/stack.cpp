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
    new_node->next = stack->top;
    stack->top = new_node;
    
    ++(stack->size);
}

void pop(Stack* stack){
    if (stack->top == nullptr){
        std::cout << "pop(): Stack is empty\n";
        return;
    }

    Node* temp{ stack->top };
    stack->top = stack->top->next;

    --(stack->size);
    delete temp;
}

void pop_all(Stack* stack){
    if (stack->top == nullptr){
        std::cout << "pop_all(): Stack is empty\n";
        return;
    }
    Node* curr{ stack->top };

    while(curr != nullptr){
        Node* temp{ curr };
        curr = curr->next;

        delete temp;
    }

    stack->top = nullptr;
    stack->size = 0;
}

void peek(Stack* stack){
    if (stack->top == nullptr){
        std::cout << "nullptr\n";

    } else {
        std::cout << stack->top->value << '\n';
    }
}

void peek_all(Stack* stack){
    Node* curr{ stack->top };

    while(curr != nullptr){
        std::cout << curr->value << " <- ";
        curr = curr->next;
    }

    std::cout << "nullptr\n";
}

bool is_empty(Stack* stack){
    if (stack->top == nullptr){
        return true;

    } else {
        return false;
    }
}

std::size_t stack_size(Stack* stack){
    return stack->size;
}