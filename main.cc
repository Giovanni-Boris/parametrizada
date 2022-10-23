#include "StackArray.h"

int main(){
  StackArray<int> c(1);
  //c.top();
  c.push(1);
  c.push(2);
  /*c.push(3);
  c.push(4);
  c.print();
  /*std::cout<<"top: "<<c.top()<<"\n";
  c.pop();*/
  c.print();
}
