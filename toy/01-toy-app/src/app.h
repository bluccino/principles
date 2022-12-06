// app.h - hardware core module (03-interact)
#ifndef __APP_H__
#define __APP_H__

#include "interface.h"

void interact(void);  // invoking a module interaction

typedef struct
{
  struct { _LED_ *LED; } out;
} App;

extern App app;

#endif // __APP_H__
