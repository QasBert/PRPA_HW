#include <stdio.h>
#include <string.h>
/* HW06 - Caesarova sifra */

int input_check(int size, const char * field);

int main(){
    /* Input */
    int message_lenght;
    char coded_message[message_lenght + 1];
    char decoder_key[message_lenght + 1];

    /* Input check */
    if (scanf("%d", &message_lenght) == 0){
        fprintf(stderr, "Error: Chybny vstup! (input: message_lenght)\n");
        return 100;
    }

    memset(coded_message, 0, message_lenght + 1);
    memset(decoder_key, 0, message_lenght + 1);

    if (scanf("%[^\n]", coded_message) == 0){
        fprintf(stderr, "Error: Chybny vstup! (input: coded_message)\n");
        return 100;
    }
    if (scanf("%[^\n]", decoder_key) == 0){
        fprintf(stderr, "Error: Chybny vstup (input: decoder_key)\n");
        return 100;
    }

}