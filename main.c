#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* HW09 - Analyza textu */

void edit_input (int size, char * input, int case_sensitivity);
int get_word_count (int size, char * input);
void null_frequency_list (int word_count, int * frequency);
void fill_all_array (int word_count, char * text, char ** list);
//void get_word_frequency (int word_count, char ** word_list, int * frequncy_list);

int main() {
    int case_sensitivity = 0; // 0-insensitive, 1-sensitive
    char *text = (char*)malloc(1*sizeof(char));
    int word_count = 1;
    char character;
    int current_size = 1;
    int temp = 0;

    /* input */
    while (scanf("%c", &character) == 1) {
        text[temp] = character;
        temp++;
        // if array is full -> increment array size
        if (temp == current_size) {
            current_size = temp + 1;
            text = realloc(text, current_size * sizeof(char));
        }
    }
    edit_input(current_size, text, case_sensitivity);
    word_count = get_word_count(current_size, text);
    temp = 0;

    char *list_all[word_count]; // 2D matrix: rows = words, columns = characters
    // malloc 20 positions for every word
    for (int i = 0; i < word_count; i++) {
        list_all[i] = (char *)malloc(20 * sizeof(char));
    }
    fill_all_array(word_count, text, list_all);
    /*for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < 20; j++) {
            if (text[temp] < 48) {
                while(j < 20) {
                    list_all[i][j] = 32;
                    j++;
                }
                temp++;
                break;
            }
            list_all[i][j] = text[temp];
            temp++;
        }
    }
    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < 20; j++) {
            if (list_all[i][j] == '\n')
                list_all[i][j] = 32;
        }
    }*/

    printf("\n");
    for (int i = 0; i < word_count; i++){
        printf("%s", list_all[i]);
        printf("\n");
    }

    free(text); // Text array no longer needed

    int *frequency_all = (int*)malloc(word_count*sizeof(int)); // craete number vector for word frequency
    null_frequency_list(word_count, frequency_all); // fill vector with 0
    get_word_frequency(word_count, list_all, frequency_all);

    
    char *list[word_count];
    for (int i = 0; i < word_count; i++) {
        list[i] = (char *)malloc(20 * sizeof(char));
    }
    int *frequency = (int *)malloc(word_count*sizeof(int));
    null_frequency_list(word_count, frequency);

    // delete repeated words
    int count = 0;
    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < word_count; j++) {
            if (strcmp(list_all[i], list[j]) == 0) {
                break;
            }
            else {
                if (frequency[i] == 0) {
                    strcpy(list[temp],list_all[i]);
                    frequency[temp] = frequency_all[i];
                    count++;
                    temp++;
                }               
            }
        }
    }
    
    

    /* Output */
    printf("\n");
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 20; j++) {
            printf("%c", list[i][j]);
        }
        printf(" %d\n", frequency[i]);
    }
    printf("Pocet slov:         %d\n\n", count);
    
    for (int i = 0; i < count; i ++) {
        printf("len%d: %zu\n", i, strlen(list[i]));
    }

    // free(list_all);
    // free(frequency_all);
    // free(list);
    // free(frequency);
    return 0;
}

void edit_input (int size, char * input, int case_sensitivity) {
    for (int i = 0; i < size; i++) {
        // check for non wanted chars
        if ((input[i] >= 33 && input[i] <= 47)||(input[i] >=58 && input[i] <= 64)||(input[i] >=123)){
            for (int j = i; j < size; j++) {
                input[j] = input[j+1];
            }
        }
        // If case insensitivity -> transfer uppercase to lower
        if (case_sensitivity == 0) {
            if (input[i] >= 65 && input[i] <= 90)
                input[i] += 32;
        }
    }
}

int get_word_count (int size, char * input) {
    int count = 1;
    for (int i = 0; i < size; i++) {
        if (input[i] == 32 && input[i+1] != 32)
            count++;
    }
    return count;
}

void null_frequency_list (int word_count, int * frequency) {
    for (int i = 0; i < word_count; i++){
        frequency[i] = 0;
    }
}

void fill_all_array (int word_count, char * text, char ** list) {
    int position = 0;
    for (int i = 0; i < word_count; i ++) {
        for (int j = 0; j < 20; j++) {
            if (text[position] < 48) {
                while (j < 20) {
                    list[i][j] = ' ';
                    j++;
                }
                position++;
                break;
            }
            list[i][j] = text[position];
            position++;
        }
    }
    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < 20; j++){
            if (list[i][j] == '\n') 
                list[i][j] = 32;
        }
    }
}

/*void get_word_frequency ( int word_count, char ** word_list, int * frequency_list) { 
    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < word_count; j++) {
            if (strcmp(word_list[i], word_list[j]) == 0) {
                frequency_list[i]++;
            }
        }
    }
}*/

