/* File : bfs.c */
/* Tanggal: 19 November 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

const int MXN = 100;

boolean valid(int x, int y, int n)
{
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main()
{
    int N;
    char arr[MXN][MXN];
    int moveX[] = {1, -1, 0, 0};
    int moveY[] = {0, 0, 1, -1};
    int startX, startY, finishX, finishY;
    boolean found = false;

    scanf("%d", &N);

    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == 'A')
            {
                startX = i;
                startY = j;
            }
            if (arr[i][j] == 'B')
            {
                finishX = i;
                finishY = j;
            }
        }
    }

    Queue q;
    CreateQueue(&q);

    ElType val = {startX, startY};
    enqueue(&q, val);

    arr[startX][startY] = '#';

    int langkah = 0;

    while (!isEmpty(q))
    {
        int size = length(q);

        for (int s = 0; s < size; s++)
        {
            ElType val;
            dequeue(&q, &val);
            int ux = val.row, uy = val.col;

            for (int i = 0; i < 4; i++)
            {
                int vx = ux + moveX[i];
                int vy = uy + moveY[i];

                if (valid(vx, vy, N) && arr[vx][vy] != '#')
                {
                    if (vx == finishX && vy == finishY)
                    {
                        printf("Ya\n%d\n", langkah + 1);
                        return 0;
                    }

                    arr[vx][vy] = '#';
                    enqueue(&q, (ElType){vx, vy});
                }
            }
        }
        langkah++;
    }

    printf("Tidak\n");
    return 0;
}