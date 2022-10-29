#include "StackArray.h"
#include "Persona.h"
#include "Profesor.h"
#include "Alumno.h"
#include <assert.h>
#include <iostream>
template<typename T>
StackArray<T>::StackArray(int s){
  assert(s > 0);
  size = s;
  data = new T[s];
  sp = data;
  assert(data != nullptr);
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
int StackArray<T>::length(){
  return sp-data;
}
template<typename T>
void StackArray<T>::resize(){
  //num elemeentos dbe ser igua a size
  assert(sp-data == size);

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
  //postcondicion
  //no se empiezsa en cero sino desde indice del utlimo elemento que se copio
  assert(sp == newData + numElem);

};
template<typename T>
void StackArray<T>::print(){
  int numElem = sp -data;
  for(int i=0;i<numElem;i++)
    std::cout<<data[i]<<"--->";
  std::cout<<"\n";
}

#include <gtest/gtest.h>
// Demonstrate some basic assertions.
/*TEST(Stack,StackEMpty) {
  Stack<Persona*>* stack = new StackArray<Persona*>(2);
  ASSERT_EQ(stack->empty(), false);
  ASSERT_EQ(stack->empty(), false);

}
TEST(Stack,StackNotEMpty) {
  Stack<Persona*>* stack = new StackArray<Persona*>(2);
  stack->push(new Alumno);
  stack->push(new Profesor);
  // Expect equality.
  EXPECT_EQ(stack->empty(),true);
  EXPECT_EQ(stack->empty(),true);

}*/


class StackTest : public ::testing::Test {
 protected:
  void SetUp() override {
     stack1->push(new Alumno);
     stack2->push(new Profesor);
     stack3->push(new Alumno);
  }

  // void TearDown() override {}
  void TearDown() override {
    std::cout<< "DELETING MY POINTERS\n";
    delete stack1;
    delete stack2;
    delete stack3;
  }
  Stack<Persona*>* stack1 = new StackArray<Persona*>(2); 
  Stack<Persona*>* stack2 = new StackArray<Persona*>(2); 
  Stack<Persona*>* stack3 = new StackArray<Persona*>(2); 
  Stack<Persona*>* stack4 = new StackArray<Persona*>(2); 
};

TEST_F(StackTest,StackEmpty) {
  //EMPTY(PUSH(s.i)=false
  EXPECT_EQ(stack1->empty(), false);
  stack1->pop();
  EXPECT_EQ(stack1->length(), 0);

}
TEST_F(StackTest,StackSize) {
  stack1->push(new Alumno);
  stack2->push(new Alumno);
  stack3->push(new Profesor);
  EXPECT_EQ(stack1->length(),2);
  stack2->pop();
  EXPECT_EQ(stack2->length(),1);
  stack3->pop();
  stack3->pop();
  EXPECT_EQ(stack3->length(),0);

}
TEST_F(StackTest, StackPop){
  stack3->pop();
  Alumno* al1 = new Alumno;
  Alumno* al2 = new Alumno;
  stack3->push(al1);
  stack3->push(al2);
  stack3->pop();
  EXPECT_EQ(stack3->top(), al1);

}

TEST_F(StackTest, StackTopNewStack){
  EXPECT_ANY_THROW({
    //top(newstack) ) undefined
    stack4->top(); 
  });
}
TEST_F(StackTest, StackTopStack){
  Alumno* al1 = new Alumno;
  stack1->push(al1);
  //top(push(S,I)=I
  EXPECT_EQ(stack1->top(), al1);
  
}








/*int main(){
  Stack<Persona*>* stack = new StackArray<Persona*>(2);
  stack->push(new Alumno);
  stack->top()->hablar();
  stack->push(new Profesor);
  stack->top()->hablar();
  //stack->print();
  StackArray<Persona&> stack1(2);
  stack1.push(*(new Alumno));
  stack1.top().hablar();
  stack1.push(*(new Profesor));
  stack1.top().hablar();
  stack1.print();
}*/
