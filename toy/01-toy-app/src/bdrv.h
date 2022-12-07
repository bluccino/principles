// bdrv.h - button driver module (01-toy-app)
#ifndef __BDRV_H__
#define __BDRV_H__

#include "interface.h"

typedef struct
{
  struct { _SYS_ SYS; } in;
  struct { _BUTTON_ *BUTTON; } out;
} Bdrv;

extern Bdrv bdrv;

#endif // __BDRV_H__
