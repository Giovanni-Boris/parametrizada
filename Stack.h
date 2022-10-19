#ifndef STACK_H
#define STACK_H
template<typename T>
//=0 solo derivdfadas pueden implmentar todos son virtuales
class Stack{
  public:
    virtual void push(T)=0;
    virtual void pop()=0;
    virtual T top()=0;
    virtual bool empty()=0;
};






#endif
