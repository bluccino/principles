// app.h - hardware core module (03-interact)
#ifndef __APP_H__
#define __APP_H__

#include "interface.h"

typedef struct
{
  struct { _LED_ *LED; } out;
} App;

extern App app;
void invoke(void);  // invoking a module interaction

#endif // __APP_H__
