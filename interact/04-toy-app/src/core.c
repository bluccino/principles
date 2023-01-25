// core.c - core module implementation (04-toy-app)

#include <stdio.h>
#include "core.h"

static int SYS_INIT(void)
{
  printf("  core: SYS.INIT()\n");
  core.out.SYS[0]->INIT();
  core.out.SYS[1]->INIT();
  return 0;
}

static int LED_SET(int i, int on)
{
  printf("  core: LED.SET(%d,%d)\n",i,on);
  return core.out.LED->SET(i,on);
}

static int LED_OFF(void)
{
  printf("  core: LED.OFF()\n");
  return core.out.LED->OFF();
}

static int BUTTON_CLICK(int i, int n)
{
  printf("  core: BUTTON.CLICK(%d,%d)\n",i,n);
  return core.out.BUTTON->CLICK(i,n);
}

static int BUTTON_HOLD(int i, int ms)
{
  printf("  core: BUTTON.HOLD(%d,%d)\n",i,ms);
  return core.out.BUTTON->HOLD(i,ms);
}

Core core =
     {
       .in = {
               .SYS = {.INIT=SYS_INIT},
               .LED = {.SET=LED_SET, .OFF=LED_OFF},
               .BUTTON = {.CLICK=BUTTON_CLICK, .HOLD=BUTTON_HOLD},
             },
     };  // module instance
