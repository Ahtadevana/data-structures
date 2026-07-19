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

    void peek() const;
    void print() const;
    std::size_t size() const;
    bool is_empty() const;

    Node* get_top() const;
};
