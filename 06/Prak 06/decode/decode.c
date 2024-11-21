/* File: decode.c */
/* Tanggal: 14 November 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "stack.h"

int main()
{
    int N, i, j, k;
    char ch;

    Stack s, sTemp;
    CreateEmpty(&s);
    CreateEmpty(&sTemp);

    scanf("%d\n", &N);

    for (i = 0; i < N; i++)
    {
        scanf(" %c", &ch);
        Push(&s, ch);
    }

    int length = N, lengthTemp;
    boolean end = false;

    while (!end)
    {
        for (i = 0; i < length; i++)
        {
            sTemp.T[i] = s.T[i];
        }
        lengthTemp = length;

        boolean done = false;
        int before = -999;

        for (i = 0; i < lengthTemp; i++)
        {
            if (sTemp.T[i] == '[')
            {
                before = i;
            }
            else if (sTemp.T[i] == ']' && !done)
            {
                int digit = sTemp.T[before - 1] - '0';
                int l = before - 1;

                if (before >= 2 && sTemp.T[before - 2] - '0' >= 0 && sTemp.T[before - 2] - '0' <= 9)
                {
                    digit += (sTemp.T[before - 2] - '0') * 10;
                    l--;
                }
                if (before >= 3 && sTemp.T[before - 3] - '0' >= 0 && sTemp.T[before - 3] - '0' <= 9 && digit + (sTemp.T[before - 3] - '0') * 100 <= 150)
                {
                    digit += (sTemp.T[before - 3] - '0') * 100;
                    l--;
                }

                length = 0;
                for (j = 0; j < l; j++)
                {
                    s.T[length++] = sTemp.T[j];
                }
                for (j = 0; j < digit; j++)
                {
                    for (k = before + 1; k <= i - 1; k++)
                    {
                        s.T[length++] = sTemp.T[k];
                    }
                }
                for (j = i + 1; j < lengthTemp; j++)
                {
                    s.T[length++] = sTemp.T[j];
                }
                done = true;
            }
        }

        if (!done) end = true;
    }

    for (int i = 0; i < length; i++)
    {
        printf("%c", s.T[i]);
    }

    printf("\n");
    return 0;
}