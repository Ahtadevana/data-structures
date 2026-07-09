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
    insert_at_tail(main_list, head, 30);

    delete_at_head(main_list, head);
    delete_at_tail(main_list, head);

    print_list(head);
    view_metadata(main_list, head);

    destroy_list(main_list, head);
    LOG(main_list);
    LOG(head);
    return 0;
}