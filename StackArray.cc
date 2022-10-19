#include "StackArray.h"
#include <assert.h>
template<typename T>
void StackArray<T>::push(T e){
  int numElem = sp - data;
  if(numElem == size){
    resize();
  }
  *sp = e;
  sp++;
}
template<typename T>
void StackArray<T>::pop(){
  if(empty())
    return;
  sp--;
}
template<typename T>
T StackArray<T>::top(){
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
  T newData[] = new T[newSize];
  int numElem = sp - data;
  for(int i=0;i<size;i++){
    newData[i] = data[i];
  }
  T oldData[] = data;

  data = newData;
  size = newSize;
  sp = newData + numElem;

  delete[] oldData;
}


