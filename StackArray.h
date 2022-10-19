#ifndef STACKARRAY_H
#define STACKARRAY_H
#define RESIZEFACTOR  20
#include "Stack.h"
template<typename T>
class StackArray: public Stack<T>{
  private:
    T data[];
    int size;//memory size
    T* sp;
    void resize();
  public:
    StackArray(int s):size{s},data{new T[s]},sp{data}{};
    ~StackArray(){delete[]data;};
    void push (T e);
    void pop();
    T top();
    bool empty();
};
#endif


