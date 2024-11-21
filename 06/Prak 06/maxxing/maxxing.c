/* File: maxxing.c */
/* Tanggal: 14 November 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "stack.h"

int main()
{
    int N, val, i, j;
    int input[10007], left[10007], right[10007], result[10007];
    Stack s;

    CreateEmpty(&s);
    scanf("%d", &N);

    for (i = 1; i <= N; i++)
    {
        scanf("%d", &input[i]);
    }

    for (i = 1; i <= N; i++)
    {
        while (!IsEmpty(s) && input[InfoTop(s)] >= input[i])
        {
            Pop(&s, &val);
        }

        if (IsEmpty(s)) left[i] = 0;
        else left[i] = InfoTop(s);

        Push(&s, i);
    }

    while (!IsEmpty(s))
    {
        Pop(&s, &val);
    }

    for (i = N; i >= 1; i--)
    {
        while (!IsEmpty(s) && input[InfoTop(s)] >= input[i])
        {
            Pop(&s, &val);
        }

        if (IsEmpty(s)) right[i] = N + 1;
        else right[i] = InfoTop(s);

        Push(&s, i);
    }

    for (i = 1; i <= N; i++)
    {
        if (result[right[i] - left[i] - 1] > input[i]) result[right[i] - left[i] - 1] = result[right[i] - left[i] - 1];
        else result[right[i] - left[i] - 1] = input[i];
    }
    for (i = N; i >= 1; i--)
    {
        if (result[i] > result[i + 1]) result[i] = result[i];
        else result[i] = result[i + 1];
    }

    for (i = 1; i <= N; i++)
    {
        if (i != N) printf("%d ", result[i]);
        else printf("%d\n", result[i]);
    }
}