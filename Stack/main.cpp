#include "stack.hpp"

#include <iostream>
#define LOG(x) std::cout << x << '\n';

int main(){
    Stack stack;
    Stack* main_stack{ &stack };

    init_stack(main_stack);
    peek_all(main_stack);

    push(main_stack, 10);
    push(main_stack, 20);
    push(main_stack, 30);

    peek_all(main_stack);
    pop_all(main_stack);

    LOG( is_empty(main_stack) );

    return 0;
}