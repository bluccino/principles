// bdrv.c - button driver implementation (04-toy-app)

#include <stdio.h>
#include "bdrv.h"

static int SYS_INIT(void)
{
  printf("    bdrv: SYS.INIT()\n");
  return 0; // no error
}

Bdrv bdrv =
     {
       .in = {
               .SYS = {.INIT=SYS_INIT},
             },
     };  // module instance
