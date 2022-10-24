#include "Alumno.h"
#include <iostream>
using namespace std;
void Alumno::hablar(){
  cout<<"Soy menor de edad\n";
}

/*
StackArray.cc:114:20: error: invalid new-expression of abstract class type 'Alumno'
  114 |   Persona* a = new Alumno;
      |                    ^~~~~~
In file included from StackArray.cc:4:
Alumno.h:7:7: note:   because the following virtual functions are pure within 'Alumno':
    7 | class Alumno: public Persona{
      |       ^~~~~~
In file included from StackArray.cc:2:
Persona.h:8:20: note: 	'virtual std::string Persona::toString()'
    8 |     virtual string toString()=0;
      |                    ^~~~~~~~
*/

