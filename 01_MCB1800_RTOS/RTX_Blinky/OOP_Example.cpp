#include "OOP_Example.h"



void Foo::set_value_private(int value){
  value_private = value;
}

int Foo::get_value_private(void){
  return value_private;
}

Foo::Foo(){
  value_private = 1;
}