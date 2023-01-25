// 01-ui-cfg (main.c)
#include <zephyr/kernel.h>
#include "ui_cfg.h"

#define UI_NID  DT_NODELABEL(ui)     // node ID
struct ui_cfg cfg = UI_CFG(UI_NID);  // UI cfg parameter set

void main(void)
{
  printk("01-ui-cfg (UI config sample @ board %s)\n",CONFIG_BOARD);
  printk("   configuration type: %s\n", cfg.ui_type);
  printk("   number of mono-LEDs: %d\n", cfg.nmb_mono_leds);
  printk("   number of RGB-LEDs: %d\n", cfg.nmb_rgb_leds);
  printk("   number of buttons: %d\n", cfg.nmb_buttons);
}
