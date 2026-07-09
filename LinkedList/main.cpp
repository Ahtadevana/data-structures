#include "linkedList.hpp"

#include <iostream>
#define LOG(X) std::cout << X << '\n'
//ignore this hehe :3c

int main(){
    Node* head{ nullptr };
    LinkedList* main_list{ init_list() };
    insert_at_head(main_list, head, 10);
    insert_at_head(main_list, head, 0);
    insert_at_tail(main_list, head, 20);

    Node* new_node{ search_node_index(main_list, head, 999) };
    LOG(new_node);
    return 0;
}