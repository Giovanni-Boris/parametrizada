#ifndef PROFESOR_H
#define PROFESOR_H
#include <string>
#include "Persona.h"
class Profesor: public Persona{
  public:
    void hablar();
    string toString();
};

#endif
