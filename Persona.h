#ifndef PERSONA_H
#define PERSONA_H
using namespace std;
#include <string>
class Persona{
  public: 
    virtual void hablar()=0;
    virtual string toString()=0;
};

#endif
