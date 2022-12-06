// main.c - main entry point for sample 02-interact

#include "app.h"
#include "core.h"

void topology(void)
{
  app_LED_SET = core_LED_SET; // connect
}

int main(void)  // main entry point
{
  topology();   // setup interaction topology
  interact();   // invoke a sample interaction
  return 0;     // no error
}
