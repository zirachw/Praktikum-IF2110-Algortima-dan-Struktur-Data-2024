/* File : susun_ulang.c */
/* Tanggal: 3 Desember 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    List L = NULL;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);

        L = konsb(L, x);
    }
    List reversed = reverseList(L);
    List res = NULL;

    boolean left = 1;
    for (int i = 0; i < N; i++)
    {
        if (left)
        {
            res = konsb(res, head(L));
            L = deleteFirst(L);
        }
        else
        {
            res = konsb(res, head(reversed));
            reversed = deleteFirst(reversed);
        }

        left = !left;
    }

    displayList(res);
}