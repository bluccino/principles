// ldrv.c - LED driver implementation (01-toy-app)

#include <stdio.h>
#include "ldrv.h"

static int SYS_INIT(void)
{
  printf("    ldrv: SYS.INIT()\n");
  return 0; // no error
}

static int LED_SET(int i, int on)
{
  printf("    ldrv: LED.SET(%d,%d)\n",i,on);
  return 0; // no error
}

static int LED_OFF(void)
{
  printf("    ldrv: LED.OFF()\n");
  return 0; // no error
}

Ldrv ldrv =
     {
       .in = {
               .SYS = {.INIT=SYS_INIT},
               .LED = {.SET=LED_SET, .OFF=LED_OFF},
             },
     };  // module instance
