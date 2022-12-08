// core.c - core module implementation (03-interact)

#include <stdio.h>
#include "core.h"

static int LED_SET(int i, int on)
{
  printf("core: LED.SET(%d,%d)\n",i,on);
  return 0; // no error
}

Core core = {.in={.LED={.SET=LED_SET}}};  // module instance
