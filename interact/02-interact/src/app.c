// app.c - implementation of module app (02-interact)

#include "app.h"

void invoke(void)        // invoking a module interaction
{
  int i = 1, on = 0;     // sample values
  (*app_LED_SET)(i,on);  // app >> LED.SET(i,n) >> ...
}
