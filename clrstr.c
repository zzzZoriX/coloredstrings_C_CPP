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