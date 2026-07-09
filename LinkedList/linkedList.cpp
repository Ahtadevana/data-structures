#include "linkedList.hpp"

#include <iostream>

/*
Node* create_node(int value);

Node* init_head();
LinkedList* init_list();

void insert_at_head(LinkedList* list, Node*& head, int value);
void insert_at_tail(LinkedList* list, Node*& head, int value);

void delete_at_head(LinkedList* list, Node*& head);
void delete_at_tail(LinkedList* list, Node*& head);
void destroy_list(LinkedList* list, Node*& head);

void print_list(Node* head);
bool search_node_value(Node* head, int key);
bool search_node_index(Node* head, int index);

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

void insert_at_head(LinkedList* list, Node*& head, int value){
    Node* new_node{ create_node(value) };

    new_node->next = head;
    head = new_node;

    list->base = new_node;
    ++(list->size);
}

void insert_at_tail(LinkedList* list, Node*& head, int value){
    Node* new_node{ create_node(value) };

    if(head == nullptr){
        head = new_node;

        list->base = new_node;
        ++(list->size);
        return;
    }
    
    Node* curr{ head };
    while(curr->next != nullptr){
        curr = curr->next;
    }

    curr->next = new_node;
    ++(list->size);
}

void delete_at_head(LinkedList* list, Node*& head){
    if(head == nullptr){
        std::cout << "delete_at_head(): List is empty\n";
        return;
    }

    Node* temp{ head };
    list->base = head->next;
    head = head->next;
    --(list->size);

    delete temp;
}


void delete_at_tail(LinkedList* list, Node*& head){
    if(head == nullptr){
        std::cout << "delete_at_tail(): List is empty\n";
        return;
    }

    if(head->next == nullptr){
        list->base = head->next;
        list->size = 0;

        Node* temp{ head };
        head = head->next;

        delete temp;
        return;
    }

    Node* curr{ head };
    while(curr->next->next != nullptr){
        curr = curr->next;
    }

    Node* temp{ curr };
    temp = temp->next;
    --(list->size);

    delete temp;

    curr->next = nullptr;
}

void destroy_list(LinkedList* list, Node*& head){
    if(head == nullptr){
        std::cout << "destroy_list(): List is empty\n";
        return;
    }

    Node* curr{ head };
    while(curr->next != nullptr){
        Node* temp = curr;
        curr = curr->next;

        delete temp;
    }

    head = nullptr;
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

bool search_node_value(Node* head, int key){
    // std::size_t index{};

    Node* curr{ head };
    while (curr != nullptr){
        if (curr->value == key){
            // std::cout << "Found at index: " << index << '\n';
            return true;
        }
        curr = curr->next;
        // ++index;
    }

    // std::cout << "search_node_value(): Node not found\n";
    return false;
}

Node* search_node_index(LinkedList* list, Node* head, std::size_t index){
    if(index > list->size - 1){
        std::cout << "search_node_index(): Out of bounds\n";
        return nullptr;
    }

    Node* curr{ head };
    std::size_t it{ 0 };
    while(it < index && curr != nullptr){
        ++it;
        curr = curr->next;
    }

    return curr;
}

void view_metadata(LinkedList* list, Node* head){

    std::cout 
        << "==========" << '\n'
        << "Head addr: " << list->base << '\n'
        << "Size: " << list->size << '\n';

    if(head == nullptr){
        std::cout 
            << "Head: " << nullptr << '\n'
            << "==========\n";
        return;
    }

    std::cout
        << "Next of head: " << head->next << '\n' 
        << "Head value: " << head->value << '\n'
        << "==========" << '\n';
}