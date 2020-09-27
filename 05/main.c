#include <stdio.h>
/* HW05 - Kresleni (ASCII art) */

/*  1. input - nejprve sirka, potom vyska (BONUS: pokud je vyska a sirka stejna -> nacte se treti cislo - velikost plotu)
    2. input check - na vstupu musi byt cisla <3;69>, sirka musi byt liche cislo
    3. strecha - vaze se na sirku domu -> ta musi byt licha; vyska strechy = (sirka_domu - 1) / 2, tj. sude cislo
    4. dum - 
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

    /* Strecha */
    int k = 0;
    for (int i = 1; i <= (width - 1)/2; i++) {
        printf(" ");
        for (int j = i; j < (width - 1)/2; j++) {
            printf(" ");
        }
        while ( k != (2 * i - 1)) {
            if(k == 0 || k == 2 * i - 2)
                printf("X");
            else 
                printf(" ");
            k++;
        }
        k = 0;
        printf("\n");
    }

    /* Dum */
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j > 0 && j < (width - 1) && i > 0 && i < (height - 1))
                printf(" ");
            else
                printf("X");
        }
        printf("\n");
    }

    return 0;
}