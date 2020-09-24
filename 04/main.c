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
        return 100;
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
                coded++;
                coded++;
                coded++;
                coded++;
            }
        }

        /* Zmena znaku */
        else
        {
            /* Bez opakovani */
            if (same_amount == 1)
            {
                printf("%c", first_char);
                if (character >= 'a' && character <= 'z')
                    break;
                coded++;
            }
            /* 1x opakovani */
            else if (same_amount == 2)
            {
                printf("%c%c", first_char, first_char);
                if (character >= 'a' && character <= 'z')
                    break;
                coded++;
                coded++;
            }
            /* 2x - 8x opakovani */
            else if (same_amount > 2 && same_amount < 10)
            {
                printf("%c%d", first_char, same_amount);
                if (character >= 'a' && character <= 'z')
                    break;
                coded++;
                coded++;
            }
            /* 9x - 98x opakovani */
            else if (same_amount >= 10 && same_amount < 100)
            {
                if (character >= 'a' && character <= 'z')
                    break;
                printf("%c%d", first_char, same_amount);
                coded++;
                coded++;
                coded++;
            }
            /* 99x - 254x opakovani */
            else if (same_amount >= 100 && same_amount <= 255)
            {
                if (character >= 'a' && character <= 'z')
                    break;
                printf("%c%d", first_char, same_amount);
                coded++;
                coded++;
                coded++;
                coded++;
            }
            first_char = character;
            same_amount = 1;
        }
    }
    if (character >= 'a' && character <= 'z')
    {
        fprintf(stderr, "Error: Neplatny symbol!\n");
        return 100;
    }
    printf("\n");

    /* Chybovy vystup */
    fprintf(stderr, "Pocet vstupnich symbolu: %d\n", char_amount);
    fprintf(stderr, "Pocet zakodovanych symbolu: %d\n", coded);
    fprintf(stderr, "Kompresni pomer: %.2f\n", (float)coded/(float)char_amount);

    return 0;
}