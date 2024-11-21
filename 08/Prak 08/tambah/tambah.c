/* File : tambah.c */
/* Tanggal: 22 November 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main()
{
    List l1, l2, res;
    CreateList(&l1);
    CreateList(&l2);
    CreateList(&res);

    ElType val;

    do
    {
        scanf("%d", &val);

        if (val != -1)
        {
            insertLast(&l1, val);
        }

    } while (val != -1);

    do
    {
        scanf("%d", &val);

        if (val != -1)
        {
            insertLast(&l2, val);
        }

    } while (val != -1);

    int diff, len;
    if (length(l1) > length(l2))
    {
        len = length(l1);
        diff = len - length(l2);
        while (diff--)
        {
            insertFirst(&l2, 0);
        }
    }
    else
    {
        len = length(l2);
        diff = len - length(l1);
        while (diff--)
        {
            insertFirst(&l1, 0);
        }
    }

    int sum, carry = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        sum = (getElmt(l1, i) + getElmt(l2, i) + carry);
        carry = 0;
        if (sum > 9)
        {
            sum %= 10;
            carry = 1;
        }

        insertFirst(&res, sum);
    }

    if (carry)
    {
        insertFirst(&res, 1);
    }

    while (!isEmpty(res))
    {
        printf("%d", INFO(res));

        if (NEXT(res) != NULL)
            printf(" ");
        res = NEXT(res);
    }

    printf("\n");
    return 0;
}