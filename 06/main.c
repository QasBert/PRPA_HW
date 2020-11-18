#include <stdio.h>
#include <string.h>
/* HW06 - Caesarova sifra */

typedef enum {false, true} bool;

bool input_check (int size, const char * field);
bool lenght_check (int size, const char * field);
int same (int size, const char first_field[], const char second_field[], int correct);
void shift (char *field, int size);

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
    if (scanf(" %[^\n]", coded_message) != 1){
        fprintf(stderr, "Error: Chybny vstup! (input: coded_message)\n");
        return 100;
    }
    if (scanf(" %[^\n]", decoder_key) != 1){
        fprintf(stderr, "Error: Chybny vstup (input: decoder_key)\n");
        return 100;
    }
    if (input_check (message_lenght, coded_message) == false || input_check (message_lenght, decoder_key) == false){
        fprintf(stderr, "Error: Chybny vstup! (function 'input_check(int size, const char * field)' returned value false)\n");
        return 100;
    }
    if (lenght_check (message_lenght, coded_message) == false || lenght_check (message_lenght, decoder_key) == false){
        fprintf(stderr, "Error: Chybna delka vstupu (function 'lenght_check(int size, const char * field)' returned value false)\n");
        return 101;
    }

    /* Firs run - find highest compliance */
    int correct_letters = 0;
    int highest = 0;
    int lowest = 0;
    for (int i = 0; i < 52; ++i)
    {
        correct_letters = same (message_lenght, coded_message, decoder_key, correct_letters);
        if (correct_letters > highest)
            highest = correct_letters;
        printf("%02d: %s ~ %s > %d correct letters\n", i, coded_message, decoder_key, correct_letters);
    }
    

    
    return 0;
}

bool input_check (int size, const char * field) {
    for (int i = 0; i < size; ++i) {
        if (field[i] > 31 && field[i] < 65)
            return false;
        if (field[i] > 90 && field[i] < 97)
            return false;
        if (field[i] > 122)
            return false;
    }
    return true;
}

bool lenght_check (int size, const char * field) {
    for (int i = 0; i < size; ++i){
        if (field[i] == 0)
            return false;
    }
    return true;
}

int same (int size, const char first_field[], const char second_field[], int correct) {
    for (int i = 0; i < size; ++i) {
        if (first_field[i] == second_field[i])
            correct++;
    }
    return correct;
}

void shift ()