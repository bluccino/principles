// interface.h (interaction interface definitions)
#ifndef __INTERFACE_H__
#define __INTERFACE_H__

//==============================================================================
//                  +--------------------+
//                  |        SYS         | SYS interface
//           INIT --|                    | init module
//                  +--------------------+
//==============================================================================

  typedef int (*_SYS_INIT_)();         // system init, store callback

  typedef struct
          {
            _SYS_INIT_ INIT;
          } _SYS_;

//==============================================================================
//                  +--------------------+
//                  |       BUTTON       | BUTTON interface
//          CLICK --|        @i,n        | button @i n-times clicked
//           HOLD --|        @i,ms       | button @i held over ms
//                  +--------------------+
//==============================================================================

  typedef int (*_BUTTON_CLICK_)(int i, int n); // button @i n-times clicked
  typedef int (*_BUTTON_HOLD_)(int i, int ms); // button @i hold (rel. after ms)

  typedef struct
          {
            _BUTTON_CLICK_ CLICK;
            _BUTTON_HOLD_ HOLD;
          } _BUTTON_;

//==============================================================================
//                  +--------------------+
//                  |        LED         | LED interface
//            SET --|       @i,onoff     | turn LED @i on/off
//            OFF --|                    | turn all LEDs off
//                  +--------------------+
//==============================================================================

  typedef int (*_LED_SET_)(int i, int onoff);  // turn LED @i on/off
  typedef int (*_LED_OFF_)(void);              // turn all LEDs off

  typedef struct
          {
            _LED_SET_ SET;
            _LED_OFF_ OFF;
          } _LED_;

#endif // __INTERFACE_H__
