#include "stack.hpp"

#include <iostream>

int main(){
    Stack stack;
    Stack* main_stack{ &stack };

    init_stack(main_stack);
    push(main_stack, 10);
    push(main_stack, 20);
    push(main_stack, 30);

    peek(main_stack);

    return 0;
}