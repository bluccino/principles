// app.h - hardware core module (02-interact)
#ifndef __APP_H__
#define __APP_H__

  void interact(void);  // invoking a module interaction

  int (*app_LED_SET)(int i, int on); // turn LED @i on/off

#endif // __APP_H__
