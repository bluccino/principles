// main.c - main entry point for sample 03-interact

#include "app.h"
#include "core.h"

void topology(void)
{
  app.out.LED = &core.in.LED; // connect
}

int main(void)  // main entry point
{
  topology();   // setup interaction topology
  interact();   // invoke a sample interaction
  return 0;     // no error
}
