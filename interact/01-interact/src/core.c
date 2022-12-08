// core.c - core module implementation (01-interact)

#include <stdio.h>
#include "core.h"

int core_LED_SET(int i, int on)
{
  printf("core: LED.SET(%d,%d)\n",i,on);
  return 0; // no error
}
