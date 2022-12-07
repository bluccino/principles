// core.h - hardware core module (03-interact)
#ifndef __CORE_H__
#define __CORE_H__

#include "interface.h"

typedef struct
{
  struct { _SYS_ SYS; _LED_ LED; _BUTTON_ BUTTON; } in;
  struct { _SYS_ *SYS[2]; _LED_ *LED; _BUTTON_ *BUTTON; } out;
} Core;

extern Core core;

#endif // __CORE_H__
