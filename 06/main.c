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
    
    memset(coded_message, 0, message_lenght + 1);
    memset(decoder_key, 0, message_lenght + 1);
    
    /* Input check */
    if (scanf("%d", &message_lenght) == 0){
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }
    if (scanf(" %[^\n]", coded_message) != 1){
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }
    if (scanf(" %[^\n]", decoder_key) != 1){
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }
    if (input_check (message_lenght, coded_message) == false || input_check (message_lenght, decoder_key) == false){
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }
    if (lenght_check (message_lenght, coded_message) == false || lenght_check (message_lenght, decoder_key) == false){
        fprintf(stderr, "Error: Chybna delka vstupu!\n");
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
        shift(coded_message, message_lenght);
        correct_letters = 0;
    }

    /* Second run - break on highest compliance */
    int temp = 0;
    for (int i = 0; i < 52; ++i){
        correct_letters = same(message_lenght, coded_message, decoder_key, correct_letters);
        if (correct_letters > temp)
            temp = correct_letters;
        if (highest == temp)
            break;
        shift(coded_message, message_lenght);
        correct_letters = 0;
    }
    printf("%s\n", coded_message);

    
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

void shift (char *field, int size){
    for (int i = 0; i < size; ++i){
        if ((field[i] >= 97 && field[i] < 122) || (field[i] >= 65 && field[i] < 90))
            field[i]++;
        else if (field [i] == 122)
            field[i] = 65;
        else if (field[i] == 90)
            field[i] = 97;
    }
}
