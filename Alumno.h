#ifndef ALUMNO_H
#define ALUMNO_H
#include "Persona.h"
using namespace std;
#include <string>

class Alumno: public Persona{
  public:
    void hablar();
    string tostring();

};


#endif 
