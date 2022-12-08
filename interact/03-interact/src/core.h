// core.h - hardware core module (03-interact)
#ifndef __CORE_H__
#define __CORE_H__

#include "interface.h"

typedef struct
{
  struct { _LED_ LED; } in;
} Core;

extern Core core;

#endif // __CORE_H__
