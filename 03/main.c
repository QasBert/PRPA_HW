#include <stdio.h>
/* HW 03 - Prvni cyklus */

float percent(int amountA, int amountB);

int main() {
    int num;
    int amount = 0;
    int amount_positive = 0;
    int amount_negative = 0;
    int amount_even = 0;
    int amount_odd = 0;
    int sum = 0;
    int max = -10000;
    int min = 10000;


    while(scanf("%d", &num) == 1){
        if(amount == 0)
            printf("");
        else {
            if (num < -10000 || num > 10000)
                break;
            else
                printf(", ");
        }

        if(num >= -10000 && num <= 10000)
            printf("%d", num);
        else
            break;

        amount++;
        sum = sum + num;
        if(num > 0)
            amount_positive++;
        else if(num < 0)
            amount_negative++;
        if(num % 2 == 0)
            amount_even++;
        else if(num % 2 != 0)
            amount_odd++;
        if(num > max)
            max = num;
        if(num < min)
            min = num; 
    }

    if(num < -10000 || num > 10000) {
        printf("\nError: Vstup je mimo interval!\n");
        return 100;
    }

    /* Hlavni vystup */
    printf("\nPocet cisel: %d\n", amount);
    printf("Pocet kladnych: %d\n", amount_positive);
    printf("Pocet zapornych: %d\n", amount_negative);
    printf("Procento kladnych: %.2f\n", percent(amount_positive, amount));
    printf("Procento zapornych: %.2f\n", percent(amount_negative, amount));
    printf("Pocet sudych: %d\n", amount_even);
    printf("Pocet lichych: %d\n", amount_odd);
    printf("Procento sudych: %.2f\n", percent(amount_even, amount));
    printf("Procento lichych: %.2f\n", percent(amount_odd, amount));
    printf("Prumer: %.2f\n", (float)sum/(float)amount);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

}

float percent (int amountA, int amountB) {
    return ((float)amountA/(float)amountB)*100;
}