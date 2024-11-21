/* File : messagequeue.c */
/* Tanggal: 12 November 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "queue.h"

int main()
{
    Queue q;
    CreateQueue(&q);

    int N, input, val, i = 0;
    scanf("%d", &N);

    while (i < N)
    {
        scanf("%d", &input);

        if (input == 1)
        {
            scanf("%d", &val);
            if (!isFull(q))
            {
                enqueue(&q, val);
                printf("Enqueue %d Berhasil\n", val);
            }
            else
            {
                printf("Queue Penuh\n");
            }
        }
        else if (input == 2)
        {
            if (!isEmpty(q))
            {
                dequeue(&q, &val);
                printf("Dequeue %d Berhasil\n", val);
            }
            else
            {
                printf("Queue Kosong\n");
            }
        }
        else if (input == 3)
        {
            if (!isEmpty(q))
            {
                printf("Elemen Awal Queue adalah %d\n", HEAD(q));
            }
            else
            {
                printf("Queue Kosong\n");
            }
        }
        else if (input == 4)
        {
            printf("Ukuran Queue saat ini adalah %d\n", length(q));
        }
        else
        {
            i--;
        }
        i++;
    }
    displayQueue(q);
}