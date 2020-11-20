#include <stdio.h>
#include <stdlib.h>
/* HW07 - Maticove vypocty */

typedef enum {f, t} bool;

void matrix_addition    ();
void matrix_substraction();
void matrix_multiple    ();
void matrix_division    ();
bool matrix_loading     ();
void loading_error      ();

int main(){
    /* Input */
    int matrixA_row     = 0;
    int matrixA_column  = 0;
    int matrixB_row     = 0;
    int matrixB_column  = 0;
    char math_operation;

    /* Matrix A loading */
    if (scanf("%d", &matrixA_row) != 1){
        loading_error();
        return 100;
    }
    if (scanf("%d", &matrixA_column) != 1){
        loading_error();
        return 100;
    }
    int *matrixA[matrixA_row];
    for (int i = 0; i < matrixA_row; i++){
        matrixA[i] = (int *)malloc(matrixA_column * sizeof(int));
    }
    if (matrix_loading () == f){
        fprintf (stderr, "Error: Chybny vstup! (function matrix_loading returned value 'f')");
        memfree(matrixA, matrixA_row);
        return 100;
    }

    return 0;
}