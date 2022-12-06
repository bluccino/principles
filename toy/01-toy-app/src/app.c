// app.c - implementation of module app (03-interact)

#include "app.h"

void interact(void)       // invoking a module interaction
{
  int i = 1, on = 0;      // sample values
  app.out.LED->SET(i,on); // app >> LED.SET(i,n) >> ...
}

App app; // module instance
