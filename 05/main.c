#include <stdio.h>
/* HW05 - Kresleni (ASCII art) */

int main() {
    int width;
    int height = 0;
    int fence;
    int input_amount = 0;
    int squere = 0;

    /* Input check */
    if (scanf("%d",&width) == 0){
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }
    input_amount++;
    if (scanf("%d",&height) == 0){
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }
    if (height == 0){
        squere = 1;
        height = width;
    }
    if (width > 69 || height > 69 || width < 3 || height < 3){
        fprintf(stderr, "Error: Vstup mimo interval!\n");
        return 101;
    }

    if (width %2 == 0 && squere == 0) {
        fprintf(stderr, "Error: Sirka neni liche cislo!\n");
        return 102;
    }
    if (squere == 0){
        if (scanf("%d",&fence) == 0){   
        }
        else{
            if (fence > height || height < 0){
                fprintf(stderr, "Error: Neplatna velikost plotu!\n");
                return 103;
            }
        }
    }

    /* Strecha */
    if (squere == 0){
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
    }

    /* Dum */
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j > 0 && j < (width - 1) && i > 0 && i < (height - 1)){
                if (width == height && squere == 0){
                    if (i%2 == 0){
                        if (j%2 == 0){
                            printf("o");
                        }
                        else{
                            printf("*");
                        }
                    }
                    else {
                        if (j%2 == 0){
                            printf("*");
                        }
                        else {
                            printf("o");
                        }
                    }
                }
                else
                    printf(" ");
            }
            else
                printf("X");
        }
        /* Plot */
        if (squere == 0){
            if (i >= (height - fence)){
                if (fence%2 == 0){
                    if ((height - 1) == i || i == (height - fence)){
                        for (int q = 0; q < fence; q++){
                            if (q%2 == 0){
                                printf("-");
                            }
                            else{ 
                                printf("|");
                            }
                        }
                    }
                    else{
                        for (int q = 0; q < fence; q++){
                            if (q%2 == 0)
                                printf(" ");
                            else
                                printf("|");
                        }
                    }
                }
                else{
                    if ((height - 1) == i || i == (height - fence)){
                        for (int q = 0; q < fence; q++){
                            if (q%2 == 0)
                                printf("|");
                            else
                                printf("-");
                        }
                    }
                    else{
                        for (int q = 0; q < fence; q++){
                            if (q%2 == 0)
                                printf("|");
                            else
                                printf(" ");
                        }
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}
