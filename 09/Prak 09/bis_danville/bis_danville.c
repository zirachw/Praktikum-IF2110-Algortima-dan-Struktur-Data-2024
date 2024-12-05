/* File : bis_danville.c */
/* Tanggal: 5 Desember 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

int main()
{
    int N;
    List l, firstMax, firstMin;
    ElType val;

    CreateList(&l);
    CreateList(&firstMax);
    CreateList(&firstMin);

    scanf("%d", &N);

    int i = 0;
    while (i < N)
    {
        scanf(" %d", &val);
        insertLast(&l, val);
        i++;
    }

    int max = -999;
    int min = 999;
    Address p = FIRST(l);
    for (int i = 0; i < N; i++)
    {
        if (INFO(p) > max)
        {
            max = INFO(p);
        }
        if (INFO(p) < min)
        {
            min = INFO(p);
        }
        p = NEXT(p);
    }

    Address pMax = search(l, max), pMin = search(l, min);

    for (int i = 0; i < N; i++)
    {
        insertLast(&firstMax, INFO(pMax));
        insertLast(&firstMin, INFO(pMin));
        pMax = NEXT(pMax);
        pMin = NEXT(pMin);
    }

    boolean cwise = true, ctrwise = true;

    Address prev = FIRST(firstMax);
    p = NEXT(FIRST(firstMax));

    for (int i = 0; i < N - 1; i++)
    {
        if (INFO(p) != INFO(prev) - 1)
        {
            ctrwise = false;
            break;
        }
        p = NEXT(p);
        prev = NEXT(prev);
    }

    prev = FIRST(firstMin), p = NEXT(FIRST(firstMin));

    for (int i = 0; i < N - 1; i++)
    {
        if (INFO(p) != INFO(prev) + 1)
        {
            cwise = false;
            break;
        }
        p = NEXT(p);
        prev = NEXT(prev);
    }

    if (cwise | ctrwise)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}