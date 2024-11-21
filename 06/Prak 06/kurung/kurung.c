/* File: kurung.c */
/* Tanggal: 5 November 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "stack.h"

int main()
{
    int N, i;
    char ch;
    boolean first = true;

    Stack s;
    infotype val;
    CreateEmpty(&s);

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf(" %c", &ch);

        if (ch == '(' | ch == '{' | ch == '[') Push(&s, ch);
        else
        {
            if (ch == ')' && InfoTop(s) == '(') Pop(&s, &val);
            else if (ch == '}' && InfoTop(s) == '{') Pop(&s, &val);
            else if (ch == ']' && InfoTop(s) == '[') Pop(&s, &val);
            else Push(&s, ch);
        }
    }

    if (IsEmpty(s))
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }

    return 0;
}