#include <stdio.h>
#include <stdlib.h>
/* HW08 - Zpracovani ciselne rady */

int main(){
    int max_delka = 1;
    int soucasna_velikost = 0;
    int pocet_cisel = 0;
    int sloupce = 0;
    int *cisla = (int *)malloc(max_delka* sizeof(int));
    int c = 0;
    int i = 0;

    if (scanf("%d", &sloupce) != 1) {
        fprintf(stderr, "Hiistogram size error\n");
        return 100;
    }
    if (sloupce <= 0) {
        fprintf(stderr, "Histogram size error\n");
        return 100;
    }

    soucasna_velikost = max_delka;
    while ((c = getchar()) != '\n') {
        if (scanf("%d", &c) != 1) {
            break;
        }
        pocet_cisel++;
        cisla[i] = c;
        i++;
        if (i == soucasna_velikost) {
            soucasna_velikost = i + max_delka;
            cisla = realloc(cisla, soucasna_velikost * sizeof(int));
        }
    }

    int min = 10000;
    int max = -10000;
    for (int j = 0; j < pocet_cisel; j++) {
        if (cisla[j] > max)
            max = cisla[j];
        if (cisla[j] < min)
            min = cisla[j];
    } 

    float cislaA[pocet_cisel];
    float median = 0;
    float temp = 0;
    for (int k = 0; k < pocet_cisel; k++) {
        cislaA[k] = (float)cisla[k];
    }
    for (int l = 0; l < pocet_cisel - 1; l++) {
        for (int j = 0; j < pocet_cisel - l - 1; j++) {
            if (cislaA[j] < cislaA[j + 1]) {
                temp = cislaA[j];
                cislaA[j] = cislaA[j + 1];
                cislaA[j + 1] = temp;
            }
        }
    }
    median = pocet_cisel%2 == 0 ? (cislaA[(pocet_cisel/2)-1]+cislaA[(pocet_cisel/2)])/2.0:cislaA[(pocet_cisel/2)];

    printf("Median %.02f\n", median);
    printf("Number count: %d\n", pocet_cisel);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);

    printf("Histogram:\n");
    float max_znak = 0;
    int pocet_znaku = 0;
    float lin_skal = 0;
    float velikost = ((float)max - (float)min)/(float)sloupce;
    for (int n = 0; n < sloupce; ++n) {
        for (int j = 0; j < pocet_cisel; ++j) {
            if (cisla[j] >= (float)min+(float)n*velikost && cisla[j] <= (float)min + ((float)n+1)*velikost)
                pocet_znaku++;
            if ((float)pocet_znaku > max_znak)
                max_znak = (float)pocet_znaku;
        }
        pocet_znaku = 0;
    }
    lin_skal = 25/max_znak;
    pocet_znaku = 0;
    for (int m = 0; m < sloupce; m++) {
        printf("%5.01f - %5.01f|", (float)min+(float)m*velikost, (float)min+((float)m+1)*velikost);
        for (int j = 0; j < pocet_cisel; ++j) {
            if (cisla[j] >= (float)min+(float)m*velikost && cisla[j] <= (float)min+((float)m+1)*velikost) {
                    pocet_znaku++;
            }
        }
        for (int j = 0; j < (int)(pocet_znaku*lin_skal); ++j) {
            printf("=");
        }
        printf("\n");
        pocet_znaku = 0;
    }
    free(cisla);
    return 0;
}