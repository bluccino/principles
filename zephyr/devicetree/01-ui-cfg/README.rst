# Sample 02-blinker

## Description

* sample application to demonstrate cntrol of a GPIO pin on very deep level
* control is implemented by utilizing `GPIO` driver API
* parameters for gpio pin control are retrieved from devicetree
* the sample needs to provide an overlay file for each support to contribute
  to the specific DTS
* in addition a binding (file: ./dts/bindings/blinker-parameters.yaml) has to be
  provided for a devicetree node with compatibility "blinker-parameters"


## Supported Boards

The sample has support for the following boards:
```
     1) nrf52dk_nrf52832         (Nordic 832 DK)
     2) nrf52840dk_nrf52840      (Nordic 840 DK)
     3) nrf52840dongle_nrf52840  (Nordic 840 dongle)
     4) nucleo_l053r8            (ST Nucleo L053 DK)
```

## 1) Defining a C/C++ Structure for UI-configuration Parameter Set

```
   struct ui_cfg {         // UI config structure
     const char* ui_type;  // type of configuration
     int nmb_mono_leds;    // number of mono colored LEDs
     int nmb_rgb_leds;     // number of RGB LEDs
     int nmb_buttons;      // number of buttons
   };
```

## 2) Creating a Binding File (ui-cfg.yaml)

```
description: user interface configuration
compatible: "ui-config"
properties:
   ui-type:
      type: string
      description: type of UI configuration
   nmb-mono-leds:
      type: int
      description: number of mono colored LEDs
   nmb-rgb-leds:
      type: int
      description: number of RGB LEDs
   nmb-buttons:
      type: int
      description: blink period in ms
```

## 3) Providing an Overlay File for Noordic 840 DK and Nordic 840 Dongle

```
// nrf52840dk_nrf52840.overlay

/ {
    ui: ui {
       compatible = "ui-config";
       ui-type = "Multi-Button UI (4 Mono-LEDs)";
       nmb-mono-leds = <4>;
       nmb-rgb-leds = <0>;
       nmb-buttons = <4>;
    };
  };
```

```
// nrf52840dongle_nrf52840.overlay

/ {
    ui: ui {
       compatible = "ui-config";
       ui-type = "Single-Button UI (1 Mono-LED + 1 RGB-LED)";
       nmb-mono-leds = <1>;
       nmb-rgb-leds = <1>;
       nmb-buttons = <1>;
    };
  };
```


## 4) Declaring an Initialized `struct ui_cfg` Variable

```
#define UI_NID DT_NODELABEL(ui)

struct ui_cfg cfg = {
   .ui_type = DT_PROP(UI_NID,ui_type),
   .nmb_mono_leds = DT_PROP(UI_NID,nmb_mono_leds),
   .nmb_rgb_leds = DT_PROP(UI_NID,nmb_rgb_leds),
   .nmb_buttons = DT_PROP(UI_NID,nmb_buttons),
};
```

## A Header File Defining a UI configurationn API

```
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
```

## Sample Program Demonstrating UI Configuration

```
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
```
