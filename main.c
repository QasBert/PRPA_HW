#include <stdio.h>
#include <stdlib.h>
/* HW09 - Analyza textu */

/*
    implicitne  - case insensitive
                - razeni podel vyskytu
                - 
*/

int main() {
    char *text = (char*)malloc(1*sizeof(char));
    char character;
    int current_size = 1;
    int position = 0;

// stdin se ulozi do pole 'text' znak po znaku pres 'character'
    while (scanf("%c", &character) == 1) {
        text[position] = character;
        position++;
        if (position == current_size) {
            current_size = position + 1;
            text = realloc(text, current_size * sizeof(char));
        }
    }

    printf("Input: \n");
    for (int i = 0; i < current_size; i++) {
        printf("%c", text[i]);
    }
    printf("--------------------------------------------------------\n\n");

    printf("Upravene: \n");
    for (int i = 0; i < current_size; i++) {
        if ((text[i] >= 33 && text[i] <= 47)||(text[i] >=58 && text[i] <= 64)||(text[i] >=123))
            text[i] = text[i+1];
    }
    for (int i = 0; i < current_size; i++) {
        printf("%c", text[i]);
    }
    printf("--------------------------------------------------------\n\n");

    free(text);
    return 0;
}