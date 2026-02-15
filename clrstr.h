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

typedef unsigned color;

typedef struct {
    color clr;
    char* txt;
} clr_txt_t;

#ifdef __cplusplus
}
#endif

#endif // defined(__linux__)
#endif //CLRSTR_H