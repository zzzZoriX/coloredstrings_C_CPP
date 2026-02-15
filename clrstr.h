#ifndef CLRSTR_H
#define CLRSTR_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__linux__)

#elif defined(WIN32) || defined(WIN64)
#include <windows.h>    // in the future I want to replace this
// lib with something which don't need
// this lib

typedef unsigned color_n;

typedef enum : color_n {
    RED =       FOREGROUND_RED | FOREGROUND_INTENSITY,
    GREEN =     FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    BLUE =      FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    WHEEL =     FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    PURPLE =    FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY,
    YELLOW =    FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    WHITE =     FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
} color;

typedef struct {
    color clr;
    char *txt;
} clr_txt_t;

#ifdef __cplusplus
}
#endif

#endif // defined(__linux__)
#endif //CLRSTR_H
