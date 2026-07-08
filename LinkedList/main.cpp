#include "linkedList.hpp"

#include <iostream>

int main(){
    Node* head{ nullptr };
    LinkedList* main_list{ init_list() };
    insert_at_head(main_list, &head, 10);
    insert_at_head(main_list, &head, 20);
    insert_at_head(main_list, &head, 30);
    view_metadata(main_list, head);

    destroy_list(main_list, &head);

    print_list(head);
    return 0;
}