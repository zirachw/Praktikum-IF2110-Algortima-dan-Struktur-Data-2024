/* File : bola.c */
/* Tanggal: 5 Desember 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

#define MAX 10000

int main()
{
    int N;
    scanf("%d", &N);

    List agent;
    CreateList(&agent);

    int ballHit[MAX];

    int i;
    for (i = 1; i <= N; i++)
    {
        insertLast(&agent, i);
        ballHit[i] = 0;
    }

    boolean first = 1;
    int agentsNow = N;

    for (i = 0; i < N - 1; i++)
    {
        int move;
        scanf("%d", &move);

        Address p = FIRST(agent);
        Address del = NEXT(p);
        Address q = NEXT(del);

        if (move > 0 || first)
            move--;

        move %= agentsNow;
        move += agentsNow;
        move %= agentsNow;

        if (move == 0)
            move = agentsNow;

        for (int j = 1; j <= move; j++)
        {
            p = NEXT(p);
            del = NEXT(del);
            q = NEXT(q);
        }

        NEXT(p) = q;
        FIRST(agent) = del;
        ballHit[INFO(del)] = 1;

        first = 0;
        agentsNow--;
    }

    for (i = 1; i <= N; i++)
    {
        if (ballHit[i] == 0)
        {
            printf("%d\n", i);
            break;
        }
    }
}