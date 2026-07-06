#pragma once

#include <iostream>

struct Node {
    Node* next;
    int value;
};

struct LinkedList {
    Node* head;
    std::size_t size;
};

Node* allocate(int value);
void deallocate(int value);

void link_node(Node* first, Node* second);
void unlink_node(Node* first, Node* second);

void print_list(Node* head);

bool search_value(Node* head, int value);
Node* get_node_ptr(Node* head, int value);

void destroy_list(Node* head);