# 02-interact

## Description

This sample demonstrates the C-implementation of a simple *module interaction*

```
   app >> LED.SET(i,on) >> core
```

between module `app` (interaction source module) and module `core` (interaction
destination module) as displayed in figure 1.

```
             +---(app)----+                   +---(core)---+
             |            |   LED.SET(i,on)   |            |
             |         LED|------------------>|LED         |
             |            |                   |            |
             +------------+                   +------------+
                 source                         destination
                 module                           module

                     Figure 1: simple interaction
```

With this coding style module implementations do not define an implicit module
interconnections. The coding style supports pluggable module architecture
avoiding the drawback, that implementation files must be consulted to identify
which modules initiate interactions.

The module interconnection topology is define explicitly in module main
by function topology().

```
   // main.c

   void topology(void)
   {
     app_LED_SET = core_LED_SET; // connect
   }
```
