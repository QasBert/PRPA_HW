#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* HW09 - Analyza textu */

int main() {
    /* input arguments */
    int case_sensitivity = 0; // 0-insensitive, 1-sensitive
    int print_limit = 0; // how many word print out

    char character;
    char *input = (char*)malloc(1*sizeof(char));

    int tmp1 = 0;
    int tmp2 = 0;
    int input_size = 1;
    while (scanf("%c", &character) == 1) {
        if ((character > 0 && character < 33)||(character > 47 && character < 58)||(character > 64 && character < 91)||(character > 96 && character < 123)){
            if (case_sensitivity == 0 && character >= 'A' && character <= 'Z')
                character += 32;
            input[tmp1] = character;
            tmp1++;
            if (tmp1 == input_size){
                input_size = tmp1+1;
                input = realloc(input, input_size*sizeof(char));
                input[tmp1] = 32;
            }
        }
    }
    tmp1 = 0;
    for (int i = 0; i < input_size-1; i++)
        printf("%c", input[i]);
    printf("\n");



    int word_count = 1;
    for (int i = 0; i < input_size-1; i++) {
        if (input[i] <= 32 && input[i+1] > 32)
            word_count++;
    }
    printf("Celkovy pocet slov: %d\n", word_count);
    //printf("strlen(input): %lu\n", strlen(input));


    char *list_all[word_count];
    for (int i = 0; i < word_count; i++)
        list_all[i] = (char*)malloc(20*sizeof(char));
    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < 20; j++) {
            if (input[tmp1] < 48){
                while (j < 20) {
                    list_all[i][j] =32;
                    j++;
                }
                while ((input[tmp1] == 32 || input[tmp1] == '\n') && tmp1 < input_size-1)
                    tmp1++;
                break;
            }
            list_all[i][j] = input[tmp1];
            tmp1++;
        }
    }
    /*for (int i = 0; i < word_count; i++)
            printf("line %d: %s\n", i, list_all[i]);
    */


    free(input);
    for (int i = 0; i < word_count; i++)
        free(list_all[i]);
    return 0;
}
