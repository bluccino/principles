// main.c - main entry point for sample 04-toy-app

#include <stdio.h>
#include "app.h"
#include "core.h"
#include "ldrv.h"
#include "bdrv.h"

static void topology(void)
{
  app.out.LED = &core.in.LED;

  core.out.SYS[0] = &ldrv.in.SYS;
  core.out.SYS[1] = &bdrv.in.SYS;

  core.out.LED = &ldrv.in.LED;
  core.out.BUTTON = &app.in.BUTTON;

  bdrv.out.BUTTON = &core.in.BUTTON;
}

static void init(void)
{
  printf("Init_Sequence\n");
  core.in.SYS.INIT();  // init low-level layer
  app.in.SYS.INIT();   // init high-level layer
}

int main(void)  // main entry point
{
  topology();   // setup interaction topology
  init();       // init all layers

    // invoke some interaction sequences

  printf("\nToggle_Sequence\n");
  bdrv.out.BUTTON->CLICK(1,1);

  printf("\nOff_Sequence\n");
  bdrv.out.BUTTON->HOLD(1,500);

  return 0;     // no error
}
