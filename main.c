#include <stdio.h>
#include <stdlib.h>
/* HW08 - Zpracovani ciselne rady */

int main(){
    /* Input */
    int histogram_size = 0;
    int maximal_size = 1;
    int current_size = 0;
    int number_quantity = 0;
    int *numbers = (int *)malloc(maximal_size * sizeof(int));

    /* Histogram loading */
    if (scanf("%d", &histogram_size) != 1){
        fprintf(stderr, "Histogram size error (line 15)\n");
        return 100;
    }
    if (histogram_size <= 0){
        fprintf(stderr, "Histogram size error (line 19)\n");
    }

    /* Number loading */
    current_size = maximal_size;
    int current_number;
    while ((current_number = getchar()) != "\n"){
        if (scanf("%d", &current_number) != 0)
            break;
        number_quantity++;
        
    }

    return 0;
}