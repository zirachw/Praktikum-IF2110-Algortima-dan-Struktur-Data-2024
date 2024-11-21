/* File : maxxing.c */
/* Tanggal: 19 November 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "prioqueue.h"

int main()
{
    int n;
    scanf("%d", &n);

    PrioQueue A, B;
    CreatePrioQueue(&A);
    CreatePrioQueue(&B);

    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        enqueue(&A, a);
    }

    for (int i = 0; i < n; i++)
    {
        int b;
        scanf("%d", &b);
        enqueue(&B, b);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int karakter, senjata;
        dequeue(&A, &karakter);
        dequeue(&B, &senjata);
        ans += (long long)karakter * senjata;
    }
    printf("%lld\n", ans);
}