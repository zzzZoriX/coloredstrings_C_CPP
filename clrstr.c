#include "clrstr.h"

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