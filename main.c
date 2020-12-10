#include <stdio.h>
#include <stdlib.h>
/* HW08 - Zpracovani ciselne rady */

int   GetLocalMinimum (const int * field, int count);
int   GetLocalMaximum (const int * field, int count);
float GetMedian       (const int * integer_numbers, int count);
void Histogram        (int histogram_size, int min, int max, int number_count,const int * numbers);

int main(){
    /* Input */
    int current_size    = 0;
    int number_count    = 0;
    int histogram_size  = 0;
    int *numbers        = (int *)malloc(1 * sizeof(int));
    int current_number  = 0;
    int field_position  = 0;

    /* Histogram size check */
    if (scanf("%d", &histogram_size) != 1) {
        fprintf(stderr, "Histogram size error\n");
        return 100;
    }
    if (histogram_size <= 0) {
        fprintf(stderr, "Histogram size error\n");
        return 100;
    }

    /* Load numbers */
    current_size = 1;
    while ((current_number = getchar()) != '\n') {
        if (scanf("%d", &current_number) != 1) {
            break;
        }
        number_count++;
        numbers[field_position] = current_number;
        field_position++;
        if (field_position == current_size) {
            current_size = field_position + 1;
            numbers = realloc(numbers, current_size * sizeof(int));
        }
    }

    int min = GetLocalMinimum(numbers, number_count);
    int max = GetLocalMaximum(numbers, number_count);

    /* Output */
    printf("Median %.02f\n",     GetMedian(numbers, number_count));
    printf("Number count: %d\n", number_count);
    printf("Min: %d\n",          min);
    printf("Max: %d\n",          max);
    Histogram(histogram_size, min, max, number_count, numbers);
    free(numbers);
    return 0;
}

int GetLocalMinimum (const int * field, int count) {
    int min = 10000;
    for (int i = 0; i < count; i++) {
        if (field[i] < min)
            min = field[i];
    }
    return min;
}

int GetLocalMaximum (const int * field, int count) {
    int max = -10000;
    for (int i = 0; i < count; i++) {
        if (field[i] > max)
            max = field[i];
    }
    return max;
}

float GetMedian (const int * integer_numbers, int count) {
    float numbers[count];
    float median = 0;
    float temp = 0;

    for (int i = 0; i < count; i++){
        numbers[i] = (float)integer_numbers[i];
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[j] < numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    median = count%2 == 0 ? (numbers[(count/2)-1]+numbers[(count/2)])/2.0:numbers[(count/2)];
    return median;
}

void Histogram (int histogram_size, int min, int max, int number_count,const int * numbers) {
    printf("Histogram:\n");
    float max_char = 0;
    int amount     = 0;
    float span     = ((float)max - (float)min)/(float)histogram_size;

    for (int i = 0; i < histogram_size; ++i) {
        for (int j = 0; j < number_count; ++j) {
            if (numbers[j] >= (float)min+(float)i*span && numbers[j] <= (float)min + ((float)i+1)*span)
                amount++;
            if ((float)amount > max_char)
                max_char = (float)amount;
        }
        amount = 0;
    }
    amount = 0;
    for (int i = 0; i < histogram_size; i++) {
        printf("%5.01f - %5.01f|", (float)min+(float)i*span, (float)min+((float)i+1)*span);
        for (int j = 0; j < number_count; ++j) {
            if (numbers[j] >= (float)min+(float)i*span && numbers[j] <= (float)min+((float)i+1)*span) {
                    amount++;
            }
        }
        for (int j = 0; j < (int)(amount*(25/max_char)); ++j) {
            printf("=");
        }
        printf("\n");
        amount = 0;
    }
}
