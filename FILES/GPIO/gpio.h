#ifndef GPIO_H
#define GPIO_H 

#include <xc.h>
/*============================= Macros to pinout =============================*/
#define PIN_LOW        0x00
#define PIN_HIGH       0x01

#define OUTPUT_PIN     0x00
#define INPUT_PIN      0x01

#define ANALOG_ENABLE  0x01
#define ANALOG_DISABLE 0x00
/*============================================================================*/
/*======================= Functions for joining macros =======================*/
/*============================================================================*/

#define PASTE2B(a, b)       a##b
#define PASTE2(a, b)        PASTE2B(a, b)
#define PASTE3B(a, b, c)    a##b##c
#define PASTE3(a, b, c)     PASTE3B(a, b, c)

/*============================================================================*/
/*=======================   Functions for set pinout   =======================*/
/*============================================================================*/

    #define CONFIGURE_PIN_DIGITAL(type, port, mask)                            \
                if(type == OUTPUT_PIN){                                        \
                    PASTE3(TRIS, port, CLR) = mask;                            \
                }                                                              \
                else if(type == INPUT_PIN)                                     \
                    PASTE3(TRIS, port, SET) = mask;
/*============================================================================*/
    #define DIGITAL_PIN_WRITE(value, port, mask)                               \
                if(value == PIN_HIGH)                                          \
                    PASTE3(LAT , port, SET) = mask;                           \
                else if(value == PIN_LOW )                                     \
                    PASTE3(LAT , port, CLR) = mask;

/*============================================================================*/
    #define DIGITAL_PIN_READ(port, bit)                                        \
                ((PASTE2(PORT, port) >> bit) & 0x00000001)

/*============================================================================*/
    #define DIGITAL_PIN_TOGGLE( port, mask )                                   \
                PASTE3(LAT , port, INV) = mask;

#endif/*GPIO_H*/