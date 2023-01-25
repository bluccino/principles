// app.c - implementation of module app (04-toy-app)

#include <stdio.h>
#include "app.h"

int state[5] = {0,0,0,0,0};  // only state[1..4] in use

static int SYS_INIT(void)
{
  printf("app: SYS.INIT()\n");
  return 0;
}

static int BUTTON_CLICK(int i, int n)
{
  printf("app: BUTTON.CLICK(%d,%d)\n",i,n);
  int on = state[i] = !state[i];
  return app.out.LED->SET(i,on);
}

static int BUTTON_HOLD(int i, int ms)
{
  printf("app: BUTTON.HOLD(%d,%d)\n",i,ms);
  state[1] = state[2] = state[3] = state[4] = 0;
  return app.out.LED->OFF();
}

App app =
    {
      .in = {
              .SYS = {.INIT=SYS_INIT},
              .BUTTON = {.CLICK=BUTTON_CLICK, .HOLD=BUTTON_HOLD},
             }
    };  // module instance
