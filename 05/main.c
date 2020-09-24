#include <stdio.h>
/* HW05 - Kresleni (ASCII art) */

/*  1. input - nejprve sirka, potom vyska (BONUS: pokud je vyska a sirka stejna -> nacte se treti cislo - velikost plotu)
    2. input check - na vstupu musi byt cisla <3;69>, sirka musi byt liche cislo
*/

int main() {
    int width = 0;
    int height = 0;
    int fence = 0;

    /* Input check */
    if (scanf("%d", &width) == 0 || scanf("%d", &height) == 0) {
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }
    if (width > 69 || height > 69 || width < 3 || height < 3) {
        fprintf(stderr, "Error: Vstup mimo interval!\n");
        return 101;
    }
    if (width %2 == 0) {
        fprintf(stderr, "Error: Sirka neni liche cislo!\n");
        return 102;
    }

    return 0;
}