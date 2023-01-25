// ui_cfg.h
#ifndef __UI_CFG_H__
#define __UI_CFG_H__

#include <zephyr/devicetree.h>

struct ui_cfg {         // UI config structure
  const char* ui_type;  // type of configuration
  int nmb_mono_leds;    // number of mono colored LEDs
  int nmb_rgb_leds;     // number of RGB LEDs
  int nmb_buttons;      // number of buttons
};

#define UI_CFG(nid) {                           \
   .ui_type = DT_PROP(nid,ui_type),             \
   .nmb_mono_leds = DT_PROP(nid,nmb_mono_leds), \
   .nmb_rgb_leds = DT_PROP(nid,nmb_rgb_leds),   \
   .nmb_buttons = DT_PROP(nid,nmb_buttons),     \
};

#endif // __UI_CFG_H__
