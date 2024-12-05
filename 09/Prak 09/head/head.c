/* File : head.c */
/* Tanggal: 5 Desember 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

int main()
{
    int N;
    List l, res;
    ElType val;

    CreateList(&l);
    CreateList(&res);

    scanf("%d", &N);

    int i = 0;
    while (i < N)
    {
        scanf(" %d", &val);
        insertLast(&l, val);
        i++;
    }

    int max = -999;
    boolean first = true;
    Address p = FIRST(l);
    for (int i = 0; i < N; i++)
    {
        if (INFO(p) > max)
        {
            max = INFO(p);
        }
        p = NEXT(p);
    }

    boolean found = false;
    Address pMax = search(l, max);

    for (int i = 0; i < N; i++)
    {
        insertLast(&res, INFO(pMax));
        pMax = NEXT(pMax);
    }

    displayList(res);

    return 0;
}