#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* HW09 - analyza textu */ 

void min_max (char ** list, int * freq, int lenght);
void A_Z (char ** list, int * freq, int lenght);
char allowed_chars (char letter);
char case_insensitivity (char letter);
int is_on_list (char ** list, char * word, int size);
void edit_input (char * word, int position, char (*function)(char));
 
int main(int argc, char * argv[])
{
	/* Arguments */
	int case_sensitivity = 0; // [done] 0-insensitive, 1-sensitive
	int order = 0; 			  // 0-default, 1-frequency min-max, 2-A-Z
	int limit = -1;			  // word lenght to print out

	for (int i = 0; i < argc; i++){
		if (argv[i][0] == '-') {
			if (argv[i][1] == 'c') case_sensitivity = 1;
			if (argv[i][1] == 's'){
				if (i < argc-1){	
					if (argv[i+1][0] == '1') order = 1;
					else if (argv[i+1][0] == '2') order = 2;
					else fprintf(stderr, "Warning: Chybna hodnota parametru -s!\n");
				}
				else fprintf(stderr, "Warning: Chybna hodnota parametru -s!\n");
			}
			if (argv[i][1] == 'l'){
				if (i < argc-1) {
					if (strlen(argv[i+1]) == 1 && argv[i+1][0] == '0') limit = 0;
					else {
						for (int j = 0; j < strlen(argv[i+1]); j++){
							if (argv[i+1][j] < '0' || argv[i+1][j] > '9'){
								fprintf(stderr, "Warning: Chybna hodnota parametru -l!\n");
								limit = -2;
								break;
							}
						}
						if (limit > -2) limit = atoi(argv[i+1]);
					}
				}
				else fprintf(stderr, "Warning: Chybna hodnota parametru -l!\n");
			}
		}
	}

	char word[20];
	int position = 0, max_frequency = 0, min_frequency = 100;
	char **list      = malloc(sizeof(char *));
	int   *frequency = malloc(sizeof(int));
 
	while (scanf("%s", word) > 0)
	{
		edit_input(word, strlen(word)-1, allowed_chars);
		if (case_sensitivity == 0) edit_input(word, 0, case_insensitivity);
		int tmp = is_on_list (list, word, position); // If word is already on list reurn where, if not return -1
		if (tmp < 0) { // write word on list
			list[position] = malloc(20); //Create spece word new unique word
			strcpy(list[position], word); // Copy new word into list
			frequency[position] = 1; // set new word frequency 1
			position++;
			list      = realloc(list,      (position+1)*sizeof(char*));
			frequency = realloc(frequency, (position+1)*sizeof(int));
		}
		else { //increment word frequency
			frequency[tmp]++;
		} 
	}
	for (int i = 0; i < position; i++) {
		if (frequency[i] < min_frequency) min_frequency = frequency[i];
		if (frequency[i] > max_frequency) max_frequency = frequency[i];
	}
	if (order == 1) min_max(list, frequency, position);
	if (order == 2) A_Z (list, frequency, position); // Alphabetical Z-A


	
	/* Output */
	/*printf("Pocet argumentu: %d\n", argc);
	printf("Argumenty: ");
	for (int i = 0; i < argc; i++) printf(" %s", argv[i]);
	printf("\nLimit: %d\n", limit);
	printf("Razeni: %d\n", order);
	printf("\n\n");*/


	if (limit != 0) printf("Seznam slov:\n");
	for (int i = 0; i < position; i++){
		if (limit < 0) printf("%-20s %d\n", list[i], frequency[i]);
		if (limit == 0) break;
		if (limit > 0 && strlen(list[i])==limit) printf("%-20s %d\n", list[i], frequency[i]);
		 
	}
	printf("Pocet slov:          %d\n", position);
	printf("Nejcastejsi:        ");
	for (int i = 0; i < position; i++) if (frequency[i] == max_frequency) printf(" %s", list[i]);
	printf("\nNejmene caste:      ");
	for (int i = 0; i < position; i++) if (frequency[i] == min_frequency) printf(" %s", list[i]);
	printf("\n");
	/* Free memory*/
	for (int i = 0; i < position; i++) free(list[i]);
	free(list);
	free(frequency);
 
	return 0;
}

void min_max (char ** list, int * freq, int lenght) {
	for (int i = 0; i < lenght; i++) {
		for (int j = 0; j < lenght - 1; j++) {
			if (freq[j] > freq[j+1]) {
				char array[20];
				int tmp;
				strcpy(array, list[j]);
				tmp = freq[j];
				strcpy(list[j], list[j+1]);
				freq[j] = freq[j+1];
				strcpy(list[j+1], array);
				freq[j+1] = tmp;
			}
		}
	}
}

void A_Z (char ** list,int * freq, int lenght) {
	for (int i = 0; i < lenght; i++) {
		for (int j = 0; j < lenght - 1; j++) {
			int tmp = (strcmp(list[j], list[j+1]) > 0);
			if (tmp) {
				char array[20];
				int tmp;
				strcpy(array, list[j]);
				tmp = freq[j];
				strcpy(list[j], list[j+1]);
				freq[j] = freq[j+1];
				strcpy(list[j+1], array);
				freq[j+1] = tmp;
			}
		}
	}
}
char allowed_chars (char letter) {
	if (letter < '0' || letter > 'z' || (letter > 'Z' && letter < 'a') || (letter > '9' && letter < 'A')) return 0;	
	return letter;
}
char case_insensitivity (char letter) {
	if (letter >= 'A' && letter <= 'Z') letter ^= (1 << 5);
	return letter; 
}

int is_on_list (char ** letter, char * word, int size){
	for (int i = 0; i < size; i++)
		if (!strcmp(letter[i], word)) return i;
	return -1;
}
 
void edit_input (char * word, int position, char (*function)(char))
{
	word[position] = function(word[position]);
}
