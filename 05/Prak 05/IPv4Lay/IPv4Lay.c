/* File: putar.c */
/* Tanggal: 22 Oktober 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakter.h"

boolean validWord(Word currentWord)
{
    boolean yes = true, first = 1;
    int num = 0, cnt = 0;

    for (int i = 0; i <= currentWord.Length; i++)
    {
        if (i == currentWord.Length || currentWord.TabWord[i] == '@')
        {
            if (first)
                yes = false;
            if (num >= 256)
                yes = false;

            first = true;
            num = 0;
            cnt++;
            continue;
        }

        if (currentWord.TabWord[i] - '0' >= 0 && currentWord.TabWord[i] - '0' <= 9)
        {
            if (first)
                first = false;
            else if (num == 0)
                yes = false;

            num *= 10;
            num += currentWord.TabWord[i] - '0';
        }
        else
            yes = false;
    }

    if (cnt != 4)
        yes = false;

    return yes;
}

int main()
{
    STARTWORD();

    while (!EndWord)
    {
        boolean valid;
        valid = validWord(currentWord);
        if (valid)
        {
            printf("4Lay");
        }
        else
        {
            printf("ewh");
        }

        ADVWORD();

        if (EndWord)
            break;
        else
            printf(" ");
    }
    printf("\n");
    return 0;
}