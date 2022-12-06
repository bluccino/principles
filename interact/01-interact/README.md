# 01-interact

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

The coding style is standard C-conding style with the drawback, that
implementation files (here: app.c) must be consulted to identify which modules
initiate interactions.
