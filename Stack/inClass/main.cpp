#include "stack.hpp"
#include <iostream>

#define LOG(X) std::cout << X << '\n'

int main(){
  Stack mainStack;
  mainStack.push(10);
  mainStack.push(20);
  mainStack.push(30);
  mainStack.peek();
  mainStack.print();

  mainStack.pop();
  mainStack.peek();
  mainStack.print();

  LOG( mainStack.size() );
  return 0;
}
