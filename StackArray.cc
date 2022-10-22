#include "StackArray.h"
#include <assert.h>
#include <iostream>
template<typename T>
StackArray<T>::StackArray(int s){
  size = s;
  data = new T[s];
  sp = data;
  //1 pop(newstack) = newstack
  pop();
  assert(sp == data);
  //3 top(newstack) = undefined
  //top()
  //sp++;
  assert((sp - data) == 0);
  //5. assert empty(newstack) = true
  //sp++;
  assert(empty()==true);
}
template<typename T>
void StackArray<T>::push(T e){
  int numElem = sp - data;
  //std::cout<<sp<<" : " <<data<<"\n";
  if(numElem == size){
    resize();
  }
  *sp = e;
 
  sp++;

  //2 pop(push(S,I)) = s
  //pop no elimina  solo retrocede el punteroo
  pop();
  std::cout<<"sp :"<<*sp<<" : e="<< e<<"\n";
  assert(*sp == e);
  //sp++ debido a que prueba solo en la asercion
  sp++;
  //e = 12;
  //4 top(push(S,I) = I)
  std::cout<<"top: "<<top()<<" : e= "<<e<<"\n"; 
  assert(top()==e);
  //--sp;
  //6 axioma empty(push(S,I)) = false
  std::cout<<"NUm elem: "<<sp-data<<"\n";
  assert(!empty());


}
template<typename T>
void StackArray<T>::pop(){
  if(empty())
    return;
  sp--;
}
template<typename T>
T StackArray<T>::top(){
  //if the stack is empty
  //top(newstack) = undefinedº
  assert(!empty());
  return *(sp-1);
}
template<typename T>
bool StackArray<T>::empty(){
  return sp==data;
}
template<typename T>
void StackArray<T>::resize(){
  int newSize =size + RESIZEFACTOR;
  T* newData= new T[newSize];
  int numElem = sp - data;
  std::cout<<"numElem: "<< numElem<<"\n";
  for(int i=0;i<size;i++){
    newData[i] = data[i];
  }
  T* oldData = data;

  data = newData;
  size = newSize;
  sp = newData + numElem;
  std::cout<<"Size: "<< size<<"\n";
  delete[] oldData;
};
template<typename T>
void StackArray<T>::print(){
  int numElem = sp -data;
  for(int i=0;i<numElem;i++)
    std::cout<<data[i]<<"--->";
  std::cout<<"\n";
}
int main(){
  StackArray<int> c(2);
  //c.top();
  c.push(1);
  /*c.push(2);
  c.push(3);
  c.push(4);
  c.print();
  /*std::cout<<"top: "<<c.top()<<"\n";
  c.pop();
  c.print();
  std::cout<<"top: "<<c.top()<<"\n";*/
}
