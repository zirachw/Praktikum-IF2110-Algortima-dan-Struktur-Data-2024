/* File : ascending.c */
/* Tanggal: 22 November 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

void bubbleSort(List *l)
{
    Address p;
    ElType val;
    boolean swap;

    if (isEmpty(*l))
    {
        return;
    }

    int n = length(*l);

    for (int i = 0; i < n - 1; i++)
    {
        swap = false;
        p = *l;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (INFO(p) > INFO(NEXT(p)))
            {
                val = INFO(p);
                INFO(p) = INFO(NEXT(p));
                INFO(NEXT(p)) = val;
                swap = true;
            }
            p = NEXT(p);
        }

        if (!swap)
        {
            break;
        }
    }
}

int main()
{
    List asc;
    CreateList(&asc);

    ElType val;

    do
    {
        scanf("%d", &val);

        if (val != -9999)
        {
            insertLast(&asc, val);
        }

    } while (val != -9999);

    bubbleSort(&asc);
    displayList(asc);
}