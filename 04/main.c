#include <stdio.h>
/* HW04 - RLE koder*/

int main()
{
    char first_char, character;
    int char_amount = 0;
    int same_amount = 1;
    int coded = 0;

    scanf("%c", &first_char);
    // Control
    if (first_char >= 'a' && first_char <= 'z')
    {
        fprintf(stderr, "Error: Neplatny symbol!\n");
    }

    while (scanf("%c", &character) == 1)
    {
        char_amount++;

        /* Znak je zadan vice nez 255x */
        if (character == first_char)
        {
            same_amount++;
            if (same_amount == 255)
            {
                printf("%c%d", first_char, same_amount);
                same_amount = 1;
                for (int i = 0; i < 4; i++)
                    coded++;
            }
        }

        /* Zmena znaku */
        else
        {
            if (same_amount == 1)
            {
            }
            else if (same_amount == 2)
            {
            }
            else if (same_amount > 2 && same_amount < 10)
            {
            }
            else if (same_amount >= 10 && same_amount < 100)
            {
            }
            else if (same_amount >= 100 && same_amount <= 255)
            {
            }
            first_char = character;
            same_amount = 1;
        }
    }

    /* Chybovy vystup */
    fprintf(stderr, "Pocet vstupnich symbolu: %d\n", char_amount);
    fprintf(stderr, "Pocet zakodovanych symbolu: %d\n", coded);
    fprintf(stderr, "Kompresni pomer: %.2f", (float)coded/(float)char_amount);

    return 0;
}