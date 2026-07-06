#include "linkedList.hpp"

#include <iostream>

int main(){
    Node* head{ create_node(10) };
    LinkedList* main_list{ init_list() };

    insert_at_head(main_list, head, 20);
    insert_at_head(main_list, head, 30);
    insert_at_head(main_list, head, 40);
    std::cout << head->next;

    return 0;
}