#include "clrstr.h"

void __cdecl
clrstr_print_single(clr_txt_t clrtxto) {
    if (!clrtxto.txt || strlen(clrtxto.txt) == 0) {
        printf("\n");
        return;
    }

    if (clrtxto.clr == RAINBOW) {
#ifdef CLRTXTRNBWIMPL
        clrstr_print_rainbow(clrstr_print_rainbow(clrtxto.txt));
#else
        #warning "Define the CLRTXTRNBWIMPL macro"
#endif
        return;
    }

    SETCMDCLR(clrtxto.clr);
    printf("%s", clrtxto.txt);
    SETCMDCLR(WHITE);
}

void __cdecl
clrstr_print(clr_txt_t* clrtxtos, size_t count) {
    for (size_t iterator = 0; iterator != count; ++iterator) {
        if (clrtxtos[iterator].clr == RAINBOW) {
#ifdef CLRTXTRNBWIMPL
            clrstr_print_rainbow(clrstr_print_rainbow(clrtxtos[iterator].txt));
#else
            #warning "Define the CLRTXTRNBWIMPL macro"
#endif
            continue;
        }
        clrstr_print_single(clrtxtos[iterator]);
    }
}

void __cdecl
clrstr_print_rainbow(const char* text) {
    const color rainbow_color_sequence[] = {
        RED, ORANGE, YELLOW, GREEN, WHEEL, BLUE, PURPLE
    };
    size_t  text_iterator = 0,
            text_length = strlen(text);
    unsigned char color_iterator = 0;

    while (text_iterator != text_length) {
        if (color_iterator == 7 /* colors array length */)
            color_iterator = 0;

        SETCMDCLR(rainbow_color_sequence[color_iterator++]);
        printf("%c", text[text_iterator++]);
    }

    SETCMDCLR(WHITE);
}