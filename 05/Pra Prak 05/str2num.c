/* File: str2num.c */
/* Tanggal: 22 Oktober 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakter.h"

void writeCurrentWord()
{
    for (int i = 0; i < currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    }
}

int satuan()
{
    if (currentWord.Length == 3 &&
        currentWord.TabWord[0] == 'n' &&
        currentWord.TabWord[1] == 'o' &&
        currentWord.TabWord[2] == 'l')
        return 0;

    else if (currentWord.Length == 4 &&
             currentWord.TabWord[0] == 's' &&
             currentWord.TabWord[1] == 'a' &&
             currentWord.TabWord[2] == 't' &&
             currentWord.TabWord[3] == 'u')
        return 1;

    else if (currentWord.Length == 3 &&
             currentWord.TabWord[0] == 'd' &&
             currentWord.TabWord[1] == 'u' &&
             currentWord.TabWord[2] == 'a')
        return 2;

    else if (currentWord.Length == 4 &&
             currentWord.TabWord[0] == 't' &&
             currentWord.TabWord[1] == 'i' &&
             currentWord.TabWord[2] == 'g' &&
             currentWord.TabWord[3] == 'a')
        return 3;

    else if (currentWord.Length == 5 &&
             currentWord.TabWord[0] == 'e' &&
             currentWord.TabWord[1] == 'm' &&
             currentWord.TabWord[2] == 'p' &&
             currentWord.TabWord[3] == 'a' &&
             currentWord.TabWord[4] == 't')
        return 4;

    else if (currentWord.Length == 4 &&
             currentWord.TabWord[0] == 'l' &&
             currentWord.TabWord[1] == 'i' &&
             currentWord.TabWord[2] == 'm' &&
             currentWord.TabWord[3] == 'a')
        return 5;

    else if (currentWord.Length == 4 &&
             currentWord.TabWord[0] == 'e' &&
             currentWord.TabWord[1] == 'n' &&
             currentWord.TabWord[2] == 'a' &&
             currentWord.TabWord[3] == 'm')
        return 6;

    else if (currentWord.Length == 5 &&
             currentWord.TabWord[0] == 't' &&
             currentWord.TabWord[1] == 'u' &&
             currentWord.TabWord[2] == 'j' &&
             currentWord.TabWord[3] == 'u' &&
             currentWord.TabWord[4] == 'h')
        return 7;

    else if (currentWord.Length == 7 &&
             currentWord.TabWord[0] == 'd' &&
             currentWord.TabWord[1] == 'e' &&
             currentWord.TabWord[2] == 'l' &&
             currentWord.TabWord[3] == 'a' &&
             currentWord.TabWord[4] == 'p' &&
             currentWord.TabWord[5] == 'a' &&
             currentWord.TabWord[6] == 'n')
        return 8;

    else if (currentWord.Length == 8 &&
             currentWord.TabWord[0] == 's' &&
             currentWord.TabWord[1] == 'e' &&
             currentWord.TabWord[2] == 'm' &&
             currentWord.TabWord[3] == 'b' &&
             currentWord.TabWord[4] == 'i' &&
             currentWord.TabWord[5] == 'l' &&
             currentWord.TabWord[6] == 'a' &&
             currentWord.TabWord[7] == 'n')
        return 9;

    return -1; // Bukan satuan
}

int edge_belas()
{
    if (currentWord.Length == 7 &&
        currentWord.TabWord[0] == 's' &&
        currentWord.TabWord[1] == 'e' &&
        currentWord.TabWord[2] == 'p' &&
        currentWord.TabWord[3] == 'u' &&
        currentWord.TabWord[4] == 'l' &&
        currentWord.TabWord[5] == 'u' &&
        currentWord.TabWord[6] == 'h')
        return 10;

    else if (currentWord.Length == 7 &&
             currentWord.TabWord[0] == 's' &&
             currentWord.TabWord[1] == 'e' &&
             currentWord.TabWord[2] == 'b' &&
             currentWord.TabWord[3] == 'e' &&
             currentWord.TabWord[4] == 'l' &&
             currentWord.TabWord[5] == 'a' &&
             currentWord.TabWord[6] == 's')
        return 11;

    else
        return -1; // Bukan belas
}

int belasan()
{
    if (currentWord.Length == 5 &&
        currentWord.TabWord[0] == 'b' &&
        currentWord.TabWord[1] == 'e' &&
        currentWord.TabWord[2] == 'l' &&
        currentWord.TabWord[3] == 'a' &&
        currentWord.TabWord[4] == 's')
        return 1;

    else
        return 0; // Bukan belas
}

int puluhan()
{
    if (currentWord.Length == 5 &&
        currentWord.TabWord[0] == 'p' &&
        currentWord.TabWord[1] == 'u' &&
        currentWord.TabWord[2] == 'l' &&
        currentWord.TabWord[3] == 'u' &&
        currentWord.TabWord[4] == 'h')
        return 1;

    else
        return 0; // Bukan puluhan
}

int seratus()
{
    if (currentWord.Length == 7 &&
        currentWord.TabWord[0] == 's' &&
        currentWord.TabWord[1] == 'e' &&
        currentWord.TabWord[2] == 'r' &&
        currentWord.TabWord[3] == 'a' &&
        currentWord.TabWord[4] == 't' &&
        currentWord.TabWord[5] == 'u' &&
        currentWord.TabWord[6] == 's')
        return 1;

    else
        return -1;
}

int ratusan()
{
    if (currentWord.Length == 5 &&
        currentWord.TabWord[0] == 'r' &&
        currentWord.TabWord[1] == 'a' &&
        currentWord.TabWord[2] == 't' &&
        currentWord.TabWord[3] == 'u' &&
        currentWord.TabWord[4] == 's')
        return 1;

    else
        return 0; // Bukan ratusan
}

int main()
{
    STARTWORD();

    boolean first = 1;
    while (!EndWord)
    {
        int digit = 0;

        if (first)
            first = 0;
        else
            printf(" ");

        int sat;
        if (satuan() == -1 && edge_belas() == -1 && seratus() == -1)
        {
            writeCurrentWord();
        }
        else
        {
            if (satuan() == 1)
            {
                printf("1");
            }
            else if (edge_belas() != -1)
            {
                printf("%d", edge_belas());
            }
            else if (seratus() == 1)
            {
                digit = 100;

                ADVWORD();

                sat = satuan();
                if (sat == 0)
                {
                    printf("%d", digit);
                    continue;
                }
                else if (sat == 1)
                {
                    digit += 1;
                    printf("%d", digit);
                }
                else if (sat >= 2)
                {
                    ADVWORD();
                    if (puluhan())
                    {
                        digit += sat * 10;

                        ADVWORD();
                        sat = satuan();
                        if (sat == 0)
                        {
                            printf("%d", digit);
                            continue;
                        }
                        else if (sat >= 1)
                        {
                            printf("%d", digit + sat);
                        }
                        else
                        {
                            printf("%d", digit);
                            continue;
                        }
                    }
                    else if (belasan())
                    {
                        digit += 10;
                        digit += sat;

                        printf("%d", digit);
                    }
                    else
                    {
                        printf("%d", digit + sat);
                    }
                }
                else if (edge_belas() != -1)
                {
                    digit += edge_belas();

                    printf("%d", digit);
                }
                else
                {
                    printf("%d", digit);
                    continue;
                }
            }
            else
            {
                int sat = satuan();

                if (sat == 0)
                {
                    printf("0");
                }
                else
                {
                    ADVWORD();

                    if (ratusan())
                    {
                        if (sat == 1)
                        {
                            printf("1");
                            continue;
                        }

                        digit = sat * 100;

                        ADVWORD();
                        sat = satuan();

                        if (sat == 0)
                        {
                            printf("%d", digit);
                            continue;
                        }
                        else if (sat == 1)
                        {
                            digit += 1;
                            printf("%d", digit);
                        }
                        else if (sat >= 2)
                        {
                            ADVWORD();
                            if (puluhan())
                            {
                                digit += sat * 10;

                                ADVWORD();
                                sat = satuan();
                                if (sat == 0)
                                {
                                    printf("%d", digit);
                                    continue;
                                }
                                else if (sat >= 2)
                                {
                                    printf("%d", digit + sat);
                                }
                                else
                                {
                                    printf("%d", digit);
                                    continue;
                                }
                            }
                            else if (belasan())
                            {
                                digit += 10;
                                digit += sat;

                                printf("%d", digit);
                            }
                            else
                            {
                                printf("%d", digit + sat);
                            }
                        }
                        else if (edge_belas() != -1)
                        {
                            digit += edge_belas();

                            printf("%d", digit);
                        }
                        else
                        {
                            printf("%d", digit);
                            continue;
                        }
                    }
                    else if (puluhan())
                    {
                        digit = sat * 10;

                        ADVWORD();
                        sat = satuan();
                        if (sat == 0)
                        {
                            printf("%d", digit);
                            continue;
                        }
                        else if (sat >= 1)
                        {
                            printf("%d", digit + sat);
                        }
                        else
                        {
                            printf("%d", digit);
                            continue;
                        }
                    }
                    else if (belasan())
                    {
                        digit = 10;
                        digit += sat;

                        printf("%d", digit);
                    }
                    else
                    {
                        printf("%d", sat);
                        continue;
                    }
                }
            }
        }
        ADVWORD();
    }

    printf("\n");
}
