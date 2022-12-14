#ifndef STACKARRAY_H
#define STACKARRAY_H
#define RESIZEFACTOR 20
#include "Stack.h"
template<typename T> class StackArray: public Stack<T>{
  private:
    int size;//memory size
    T* sp;
    void resize();
    T* data ;

  public:
    StackArray(int s);
    ~StackArray(){delete[] data;}
    void push(T e);
    void pop();
    T top();
    bool empty();
    void print();
    int length();
};
#endif


