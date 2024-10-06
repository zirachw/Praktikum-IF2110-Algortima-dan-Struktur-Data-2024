/* File: main.c */
/* Tanggal: 1 Oktober 2024 */
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik l, unique, occur;
    readList(&l);

    CreateListStatik(&unique);
    CreateListStatik(&occur);

    int count = -1;
    for (int i = getFirstIdx(l); i <= getLastIdx(l); i++)
    {
        if (indexOf(l, ELMT(l, i)) == i)
        {
            count++;
            ELMT(occur, count) = 1;
            ELMT(unique, count) = ELMT(l, i);
        }
        else
        {
            ELMT(occur, indexOf(unique, ELMT(l, i))) += 1;
        }
    }

    int firstMax = -1, secondMax = -1;
    for (int i = 0; i <= count; i++)
    {
        if (ELMT(occur, i) > firstMax)
        {
            secondMax = firstMax;
            firstMax = ELMT(occur, i);
        }
        else if (ELMT(occur, i) > secondMax && ELMT(occur, i) < firstMax)
        {
            secondMax = ELMT(occur, i);
        }
    }

    if (secondMax == -1)
    {
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
        return 0;
    }

    int secondMaxElement = 2147483647;
    for (int i = 0; i <= count; i++)
    {
        if (ELMT(occur, i) == secondMax)
        {
            if (ELMT(unique, i) < secondMaxElement)
            {
                secondMaxElement = ELMT(unique, i);
            }
        }
    }

    printf("%d\n", secondMaxElement);
    return 0;
}