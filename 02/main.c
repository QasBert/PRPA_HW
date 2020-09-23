#include <stdio.h>
/* HW 02 - Nacitani vstupu, vypocet a vystup */

int main() {
    int cisloA = 0;
    int cisloB = 0;

    /* Nacteni cisel */
    scanf("%d", &cisloA);
    scanf("%d", &cisloB);

    /* Obe cisla musi lezet v intervalu <-10.000;10.000> */
    if (cisloA > 10000 || cisloA < -10000 || cisloB > 10000 || cisloB < -10000) {
        printf("Vstup je mimo interval!\n");
        return 0;
    }

    /* Hlavni vystup */
    printf("Desitkova soustava: %d %d\n", cisloA, cisloB);
    printf("Sestnactkova soustava: %x %x\n", cisloA, cisloB);
    printf("Soucet: %d + %d = %d\n", cisloA, cisloB, cisloA+cisloB);
    printf("Rozdil: %d - %d = %d\n", cisloA, cisloB, cisloA-cisloB);
    printf("Soucin: %d * %d = %d\n", cisloA, cisloB, cisloA*cisloB);
    if (cisloB == 0)
        printf("Nedefinovany vysledek!\n");
    else
        printf("Podil: %d / %d = %d\n", cisloA, cisloB, cisloA/cisloB);
    printf("Prumer: %.1f\n", (float)(cisloA+cisloB)/2);

    return 0;
}