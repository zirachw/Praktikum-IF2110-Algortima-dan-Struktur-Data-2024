/* File: kekayaan.c */
/* Tanggal: 1 Oktober 2024 */
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "liststatik.h" // Gunakan .h untuk olympia dan .c untuk run local

int main()
{
    ListStatik l;
    readList(&l);

    int keep = 1;
    for (int i = getLastIdx(l); i >= getFirstIdx(l); i--)
    {
        ELMT(l, i) += keep;

        if (ELMT(l, i) == 10)
        {
            ELMT(l, i) = 0;
            keep = 1;
        }
        else
        {
            keep = 0;
            break;
        }
    }

    if (keep == 1)
    {
        insertAt(&l, keep, getFirstIdx(l));
    }

    for (int i = getFirstIdx(l); i <= getLastIdx(l); i++)
    {
        if (i == getFirstIdx(l))
        {
            printf("%d", ELMT(l, i));
        }
        else
        {
            printf(" %d", ELMT(l, i));
        }
    }

    printf("\n");
    return 0;
}