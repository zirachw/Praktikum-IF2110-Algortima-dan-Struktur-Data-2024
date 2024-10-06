/* File: olist.c */
/* Tanggal: 1 Oktober 2024 */
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "liststatik.h" // Gunakan .h untuk olympia dan .c untuk run local

int main()
{
    ListStatik l, unique, occur;
    readList(&l);

    CreateListStatik(&unique);
    CreateListStatik(&occur);

    int count = -1;
    for (int i = getFirstIdx(l); i <= getLastIdx(l); i++)
    {
        if (indexOf(l, ELMT(l, i)) == i)
        {
            count++;
            ELMT(occur, count) = 1;
            ELMT(unique, count) = ELMT(l, i);
        }
        else
        {
            ELMT(occur, indexOf(unique, ELMT(l, i))) += 1;
        }
    }

    printList(unique);
    printf("\n");

    for (int i = getFirstIdx(unique); i <= getLastIdx(occur); i++)
    {
        printf("%d %d\n", ELMT(unique, i), ELMT(occur, i));
    }

    return 0;
}