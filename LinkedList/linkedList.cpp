#include "linkedList.hpp"

#include <iostream>

/*
Node* create_node(int value);

void init_list(LinkedList* list);

void insert_at_head(LinkedList* list, Node* head, int value);
void destroy_list(LinkedList* list, Node* head);

void print_list(Node* head);

void view_metadata(LinkedList* list, Node* head);
*/

Node* create_node(int value){
    Node* new_node{ new Node };

    new_node->next = nullptr;
    new_node->value = value;

    return new_node;
}

LinkedList* init_list(){
    LinkedList* list{ new LinkedList };

    list->base = nullptr;
    list->size = 0;

    return list;
}

void insert_at_head(LinkedList* list, Node** head, int value){
    Node* new_node{ create_node(value) };

    new_node->next = *head;
    *head = new_node;

    list->base = new_node;
    ++(list->size);
}

void destroy_list(LinkedList* list, Node** head){
    if(*head == nullptr){
        std::cout << "destroy_list(): List is empty\n";
        return;
    }

    Node* curr{ *head };
    while(curr->next != nullptr){
        Node* temp = curr;
        curr = curr->next;

        delete temp;
    }

    *head = nullptr;
    list->base = nullptr;
    list->size = 0;
}

void print_list(Node* head){
    Node* curr{ head };

    while(curr != nullptr){
        std::cout << curr->value << " -> ";
        curr = curr->next;
    }

    std::cout << "nullptr\n";
}

void view_metadata(LinkedList* list, Node* head){

    std::cout 
        << "==========" << '\n'
        << "Head addr: " << list->base << '\n'
        << "Size: " << list->size << '\n';

    if(head == nullptr){
        std::cout << "Head: " << nullptr << '\n';
        return;
    }

    std::cout
        << "Next of head: " << head->next << '\n' 
        << "Head value: " << head->value << '\n'
        << "==========" << '\n';
}