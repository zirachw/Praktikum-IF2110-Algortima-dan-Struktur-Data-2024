/* File: inventory.c */
/* Tanggal: 5 November 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "stack.h"

int main()
{
    int N, i, nEl, keep;
    char ch;
    infotype val;
    Stack s;

    CreateEmpty(&s);
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf(" %c", &ch);
        keep = 0;
        
        if (ch == '+')
        {
            Pop(&s, &val);
            if (!IsEmpty(s)) keep = InfoTop(s);

            Push(&s, val);
            Push(&s, val + keep);
        }
        else if (ch == 'X')
        {
            Pop(&s, &val);
        }
        else if (ch == 'S')
        {
            while (!IsEmpty(s))
            {
                Pop(&s, &val);
                keep += val;
            }
            Push(&s, keep);
        }
        else if (ch == 'A')
        {
            nEl = 0;
            while (!IsEmpty(s))
            {
                Pop(&s, &val);
                keep += val;
                nEl++;
            }
            if (nEl != 0)
                Push(&s, keep / nEl);
        }
        else
        {
            Push(&s, (int)(ch - '0'));
        }
    }

    keep = 0;

    while (!IsEmpty(s))
    {
        Pop(&s, &val);
        keep += val;
    }

    printf("%d\n", keep);
    return 0;
}