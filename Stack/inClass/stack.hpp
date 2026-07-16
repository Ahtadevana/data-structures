#pragma once

#include <cstddef>

class Stack {
  private:
    struct Node {
      Node* next;
      int data;
    };
    Node* top_;
    std::size_t size_;

    Node* create_node(int data);

  public:
    Stack();
    ~Stack();
    void push(int data);
    void pop();
    void peek();
    void print();
    std::size_t size();
    bool is_empty();

    Node* get_top();
    std::size_t get_size();
};
