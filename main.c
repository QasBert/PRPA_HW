#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* HW09 - Analyza textu */

char nonwanted_char (char c);
int get_word_count (int size, char * input);
void null_frequency_list (int word_count, int * frequency);
void fill_all_array (int word_count, char * text, char ** list);
void get_word_frequency (int word_count, char ** word_list, int * frequncy_list);
void free_memory (char ** list_all, int * frequency_all, char ** list, int * frequency, int word_count, int count);
int remove_repeated (int word_count, int count, int * frequency_all, int * frequency, char ** list_all, char ** list);

int main() {
    int case_sensitivity = 0; // 0-insensitive, 1-sensitive
    char *text = (char*)malloc(1*sizeof(char));
    int word_count = 1;
    char character;
    int current_size = 1;
    int temp = 0;

    /* input */
    while (scanf("%c", &character) == 1) {
        if (nonwanted_char(character) != 0){
            if (case_sensitivity == 0 && character >= 'A' && character <= 'Z')
                character += 32;
            text[temp] = character;
            temp++;
            // if array is full
            if (temp = current_size) {
                current_size = temp + 1;
                text = realloc(text, current_size * sizeof(char));
            }
        }

    }
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
    count = remove_repeated(word_count, count, frequency_all, frequency, list_all, list);
       
    

    /* Output */
    printf("\n");
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 20; j++) {
            printf("%c", list[i][j]);
        }
        printf(" %d\n", frequency[i]);
    }
    printf("Pocet slov:          %d\n\n", count);
    
    for (int i = 0; i < count; i ++) {
        printf("len%d: %zu\n", i, strlen(list[i]));
    }

    free_memory(list_all, frequency_all, list, frequency, word_count, count);
    
    return 0;
}


char nonwanted_char (char c) {
    if ((c < 32) || (c >= 33 && c <= 47)||(c >=58 && c <= 64)||(c >=123))
        return 0;
    return c;
}

int get_word_count (int size, char * input) {
    int count = 1;
    for (int i = 0; i < size; i++) {
        // if is change from space to letter -> word_count++
        if (input[i] == 32 && input[i+1] != 32)
            count++;
    }
    return count;
}

void null_frequency_list (int word_count, int * frequency) {
    // set 0 for all positions
    for (int i = 0; i < word_count; i++){
        frequency[i] = 0;
    }
}

void fill_all_array (int word_count, char * text, char ** list) {
    int position = 0;
    for (int i = 0; i < word_count; i ++) {
        for (int j = 0; j < 20; j++) {
            // if character is space or new line - fill with space; else write character into matrix
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
    // check for new lines
    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < 20; j++){
            if (list[i][j] == '\n') 
                list[i][j] = 32;
        }
    }
}

void get_word_frequency ( int word_count, char ** word_list, int * frequency_list) { 
    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < word_count; j++) {
            // compare one word with others
            if (strcmp(word_list[i], word_list[j]) == 0) {
                frequency_list[i]++;
            }
        }
    }
}

void free_memory (char ** list_all, int * frequency_all, char ** list, int * frequency, int word_count, int count) {
    //for (int i = 0; i < word_count; i++)
    //    free(list_all[i]);
    free(list_all);
    free(frequency_all);
    //for (int i = 0; i < count; i++)
    //    free(list[i]);
    free(frequency);
}

int remove_repeated (int word_count, int count, int * frequency_all, int * frequency, char ** list_all, char ** list) {
    int write = 0;
    for (int i = 0; i < word_count; i++){
        for (int j = 0; j < word_count; j++){
            if (strcmp(list_all[i], list_all[j]) == 0){
                for (int k = 0; k < word_count; k++) {
                    if (strcmp(list_all[i], list[k]) == 0) {
                        write = 0;
                        break;
                    }
                    else
                        write = 1;
                }
                if (write == 1) {
                    list[count] = list_all[i];
                    frequency[count] = frequency_all[i];
                    count++;
                }
            }
        }
        write = 0;
    }
    return count;
}
