#pragma once

#include <iostream>

struct Node {
    Node* next;
    int value;
};

struct LinkedList {
    Node* base;
    std::size_t size;
};

Node* create_node(int value);

Node* init_head();
LinkedList* init_list();

void insert_at_head(LinkedList* list, Node*& head, int value);
void insert_at_tail(LinkedList* list, Node*& head, int value);

void delete_at_head(LinkedList* list, Node*& head);
void delete_at_tail(LinkedList* list, Node*& head);
void destroy_list(LinkedList* list, Node*& head);

void print_list(Node* head);

void view_metadata(LinkedList* list, Node* head);