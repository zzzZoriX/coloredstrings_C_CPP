#ifndef CLRSTR_H
#define CLRSTR_H

#include <stdio.h>

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

/**
 * @brief print single clr_txt_t structure object
 *
 * @param clrtxto   object which need print
 *
 * @return nothing
 */
void __cdecl
clrstr_print_single(clr_txt_t clrtxto);

/**
 * @brief print each clr_txt_t structre object in given array
 *
 * @param clrtxtos  array of clr_txt_t structure objects
 * @param count     total count of objects in array
 */
void __cdecl
clrstr_print(clr_txt_t* clrtxtos, size_t count);


#define DEFAULT_CLRTXT (clr_txt_t){WHITE, ""};
#define MAKE_CLRTXT(clr, txt) (clr_txt_t){(clr), (txt)}

#define SETCMDCLR(clr) SetConsoleTextAttribute(\
    GetStdHandle(STD_OUTPUT_HANDLE),\
    clr\
)

#ifdef CLRTXTIMPL
    void __cdecl
    clrstr_print_single(clr_txt_t clrtxto) {
        if (!clrtxto.txt || strlen(clrtxto.txt) == 0) {
            printf("\n");
            return;
        }

        SETCMDCLR(clrtxto.clr);
        printf("%s", clrtxto.txt);
        SETCMDCLR(WHITE);
    }

    void __cdecl
    clrstr_print(clr_txt_t* clrtxtos, size_t count) {
        for (size_t iterator = 0; iterator != count; ++iterator) {
            clrstr_print_single(clrtxtos[iterator]);
        }
    }
#endif // CLRTXTIMPL

#endif // defined(__linux__)

#ifdef __cplusplus
}
#endif

#endif //CLRSTR_H