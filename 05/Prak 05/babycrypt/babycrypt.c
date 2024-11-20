/* File: putar.c */
/* Tanggal: 22 Oktober 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakter.h"

int main()
{
    boolean first = true, putar = true;
    int shift;

    scanf("%d", &shift);
    shift %= 26;
    shift = 26 - shift;

    STARTWORD();
    while (!EndWord)
    {
        if (!first)
            printf(" ");
        else
            first = false;

        for (int i = 0; i < currentWord.Length; i++)
        {
            char c = currentWord.TabWord[i];

            if (c - 'a' >= 0 && c - 'a' <= 25)
            {
                c = (c - 'a' + shift) % 26;
                c += 'a';
            }
            else if (c - 'A' >= 0 && c - 'A' <= 25)
            {
                c = (c - 'A' + shift) % 26;
                c += 'A';
            }
            printf("%c", c);
        }
        ADVWORD();
    }
    printf("\n");
    return 0;
}