#include "OOP_Example.h"



void Foo::SetValue(int value){
  this->value = value;
}

int Foo::GetValue(void){
  return value;
}

// Default Constructor
Foo::Foo(void){
  value = 1;
}
