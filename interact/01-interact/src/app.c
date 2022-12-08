// app.c - implementation of module app (01-interact)

#include "app.h"
#include "core.h"

void invoke(void)        // invoking a module interaction
{
  int i = 1, on = 0;     // sample values
  core_LED_SET(i,on);    // app >> LED.SET(i,n) >> core
}
