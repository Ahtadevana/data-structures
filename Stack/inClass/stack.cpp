#include "stack.hpp"

#include <iostream>

[[nodiscard]]
Stack::Node* Stack::create_node(int data){
  Node* new_node{ new Node };
  new_node->next = nullptr;
  new_node->data = data;

  return new_node;
}

Stack::Stack(){
  top_ = nullptr;
  size_ = 0 ;
}

Stack::~Stack(){
  if( is_empty() )
    return;

  Node* curr{ top_ };
  while (curr != nullptr){
    Node* temp{ curr };
    curr = curr->next;

    delete temp;
  }
}

void Stack::push(int data){
  Node* new_node{ create_node(data) };

  new_node->next = top_;
  top_ = new_node;

  ++(size_);
}

void Stack::pop(){
  if( is_empty() ){
    std::cout << "pop(): stack is empty\n";
    return;
  }
  if( top_->next == nullptr ){
    delete top_;
    top_ = nullptr;

    size_ = 0;
    return;
  }
  Node* temp{ top_ };
  top_ = top_->next;

  delete temp;
  --(size_);
}

void Stack::peek(){
  if( is_empty() ){
    std::cout << "nullptr\n";
    return;
  }
  std::cout << top_->data <<'\n';
}

void Stack::print(){
  if( is_empty() ){
    std::cout << "nullptr\n";
    return;
  }
  Node* curr{ top_ };
  while(curr != nullptr){
    std::cout << curr->data << " <- ";
    curr = curr->next;
  }
  std::cout << "nullptr\n";
}

[[nodiscard]]
std::size_t Stack::size(){
  return size_;
}

[[nodiscard]]
bool Stack::is_empty(){
  if (top_ == nullptr){
    return true;
  } else {
    return false;
  }
}

[[nodiscard]]
Stack::Node* Stack::get_top(){
  return top_;
}

[[nodiscard]]
std::size_t Stack::get_size(){
  return size_;
}
