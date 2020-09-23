#include <stdio.h>
/* HW04 - RLE koder*/

int main() {
    char first_char, character;
    int char_amount = 0;
    int same_amount = 1;

    scanf("%c", &first_char);
    // Control
    if(first_char >= 'a' && first_char <= 'z') {
        fprintf(stderr, "Error: Neplatny symbol!\n");
    }

    while(scanf("%c", &character) == 1){
        char_amount++;
        if(character == first_char) {
            same_amount++;
        }
    }
}