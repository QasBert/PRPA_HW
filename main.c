#include <stdio.h>
#include <stdlib.h>
/* HW07 - Maticove vypocty */

typedef enum {f, t} bool;

void matrix_addition    (int ** matrixA, int ** matrixB, int row, int column);
void matrix_substraction(int ** matrixA, int ** matrixB, int row, int column);
void matrix_multiple    (int ** matrixA, int ** matrixB, int row, int columnA, int columnB);
bool matrix_loading     (int ** matrix, int row, int column);
void free_memory        (int ** matrix, int row);
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
    if (matrix_loading (matrixA, matrixA_row, matrixA_column) == f){
        fprintf (stderr, "Error: Chybny vstup!\n");
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
    if (matrix_loading (matrixB, matrixB_row, matrixB_column) == f){
        fprintf (stderr, "Error: Chybny vstup!\n");
        free_memory(matrixA, matrixA_row);
        free_memory(matrixB, matrixB_row);
        return 100;
    }

    /* Output */
    switch (math_operation){
        case '+':
            if (matrixA_row == matrixB_row && matrixA_column == matrixB_column)
                matrix_addition(matrixA, matrixB, matrixA_row, matrixA_column);
            else {
                fprintf (stderr, "Error: chybny vstup!\n");
                free_memory(matrixA, matrixA_row);
                free_memory(matrixB, matrixB_row);
                return 100;
            }
            break;
        case '-':
            if (matrixA_row == matrixB_row && matrixA_column == matrixB_column)
                matrix_substraction(matrixA, matrixB, matrixA_row, matrixA_column);
            else {
                fprintf (stderr, "Error: Chybny vstup!\n");
                free_memory(matrixA, matrixA_row);
                free_memory(matrixB, matrixB_row);
                return 100;
            }
            break;
        case '*':
            if (matrixA_row == matrixB_column)
                matrix_multiple(matrixA, matrixB, matrixA_row, matrixA_column, matrixB_column);
            else {
                fprintf (stderr, "Error: Chybny vstup!\n");
                free_memory(matrixA, matrixA_row);
                free_memory(matrixB, matrixB_row);
                return 100;
            }                
            break;
        default:
            fprintf(stderr, "Error: Chybny vstup!\n");
            return 100;
            break;
    }
    free_memory(matrixA, matrixA_row);
    free_memory(matrixB, matrixB_row);
    return 0;
}

void matrix_addition        (int ** matrixA, int ** matrixB, int row, int column){
    int add[row][column];
    int temp[row][column];
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            temp[i][j] = 1 * matrixB[i][j];
        }
    }
    printf("%d %d\n", row, column);
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            add[i][j] = matrixA[i][j] + temp[i][j];
            if (j == column - 1)
                printf("%d", add[i][j]);
            else
                printf("%d ", add[i][j]);
        }
        printf("\n");
    }
}
void matrix_substraction    (int ** matrixA, int ** matrixB, int row, int column){
    int sub[row][column];
    int temp[row][column];
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            temp[i][j] = -1 * matrixB[i][j];
        }
    }
    printf ("%d %d\n", row, column);
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            sub[i][j] = matrixA[i][j] + temp[i][j];
            if (i == column - 1)
                printf ("%d", sub[i][j]);
            else
                printf ("%d ", sub[i][j]);
        }
        printf("\n");
    }
}
void matrix_multiple        (int ** matrixA, int ** matrixB, int row, int columnA, int columnB){
    int matrix[row][columnB];
    for (int i = 0; i < row; i++){
        for (int j = 0; j < columnB; j++){
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < row; i++){
        for (int j = 0; j < columnB; j++){
            for (int k = 0; k < columnA; k++){
                matrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    printf ("%d %d\n", row, columnB);
    for (int i = 0; i < row; i++){
        for (int j = 0; j < columnB; j++){
            if (j == columnB - 1)
                printf("%d", matrix[i][j]);
            else
                printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
bool matrix_loading         (int ** matrix, int row, int column){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (scanf("%d", &matrix[i][j]) <= 0)
                return f;
        }
    }
    return t;
}
void free_memory            (int ** matrix, int row){
    for (int i = 0; i < row; i++){
        free(matrix[i]);
    }
}
void loading_error          (){
    fprintf (stderr, "Error: Chybny vstup!\n");
}
