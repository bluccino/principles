// ldrv.h - LED driver module (04-toy-app)
#ifndef __LDRV_H__
#define __LDRV_H__

#include "interface.h"

typedef struct
{
  struct { _SYS_ SYS; _LED_ LED; } in;
} Ldrv;

extern Ldrv ldrv;

#endif // __LDRV_H__
