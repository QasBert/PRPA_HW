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
        free_memory(matrixA, matrixA_row);
        return 100;
    }

    /* Choose matchematical operation */
    do {
        scanf("%c", &math_operation);
    }
    while (math_operation == ' ' || math_operation == '\n');

    /* Matrix B loading */
    if (scanf("%d", &matrixB_row) != 1){
        loading_error();
        return 100;
    }
    if (scanf("%d", &matrixB_column) != 1){
        loading_error();
        return 100;
    }
    int *matrixB[matrixB_row];
    for (int i = 0; i < matrixB_row; i++){
        matrixB[i] = (int *)malloc(matrixB_column * sizeof(int));
    }
    if (matrix_loading () == f){
        fprintf (stderr, "Error: Chybny vstup! (function matrix_loading returned value 'f')");
        free_memory(matrixA, matrixA_row);
        free_memory(matrixB, matrixB_row);
        return 100;
    }

    /* Output */
    switch (math_operation){
        case '+':
            break;
        case '-':
            break;
        case '*':
            break;
        default:
            fprintf(stderr, "Error: Chybny vstup! (switch function set default case)");
            break;
    }
    free_memory(matrixA, matrixA_row);
    free_memory(matrixB, matrixB_row);
    return 0;
}