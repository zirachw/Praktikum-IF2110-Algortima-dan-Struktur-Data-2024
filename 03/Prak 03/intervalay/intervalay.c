#include <stdio.h>
#include "listdin.h"

int main()
{
    int CAPACITY = 100000, newA, newB;

    ListDin l;
    CreateListDin(&l, CAPACITY);
    readList(&l);

    ListDin result;
    CreateListDin(&result, listLength(l) + 2);

    scanf("%d %d", &newA, &newB);

    IdxType i = 0;

    while (i <= getLastIdx(l) && ELMT(l, i + 1) < newA)
    {
        insertLast(&result, ELMT(l, i));
        insertLast(&result, ELMT(l, i + 1));
        i += 2;
    }

    while (i <= getLastIdx(l) && ELMT(l, i) <= newB)
    {
        if (newA > ELMT(l, i))
        {
            newA = ELMT(l, i);
        }

        if (newB < ELMT(l, i + 1))
        {
            newB = ELMT(l, i + 1);
        }

        i += 2;
    }

    insertLast(&result, newA);
    insertLast(&result, newB);

    while (i <= getLastIdx(l))
    {
        insertLast(&result, ELMT(l, i));
        insertLast(&result, ELMT(l, i + 1));
        i += 2;
    }

    printf("%d", ELMT(result, getFirstIdx(result)));
    for (IdxType k = getFirstIdx(result) + 1; k <= getLastIdx(result); k++)
    {
        printf(" %d", ELMT(result, k));
    }
    printf("\n");

    dealocateList(&l);
    dealocateList(&result);

    return 0;
}
