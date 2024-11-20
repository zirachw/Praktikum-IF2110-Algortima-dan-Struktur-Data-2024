/* File: putar.c */
/* Tanggal: 22 Oktober 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakter.h"

Word reverseWord(Word currentWord)
{
    int kiri = 0;
    int kanan = currentWord.Length - 1;
    int temp;

    while (kiri < kanan)
    {
        temp = currentWord.TabWord[kiri];
        currentWord.TabWord[kiri] = currentWord.TabWord[kanan];
        currentWord.TabWord[kanan] = temp;
        kiri++;
        kanan--;
    }
    return currentWord;
}

void printWord(Word word)
{
    int i;
    for (i = 0; i < word.Length; i++)
    {
        printf("%c", word.TabWord[i]);
    }
}

int main()
{
    STARTWORD();

    while (!EndWord)
    {
        int reverse = 0;
        while (reverse < NMax)
        {
            if (reverse % 2 == 0)
                printWord(reverseWord(currentWord));
            else
                printWord(currentWord);
            ADVWORD();
            reverse++;

            if (EndWord)
                break;
            else
                printf(" ");
        }
    }
    printf("\n");
    return 0;
}