#include <stdio.h>
#include "listdin.h"

int main()
{
    int CAPACITY = 100000, INT_MAX = 1000000;

    ListDin l, pref, suff;
    CreateListDin(&l, CAPACITY);
    readList(&l);

    // Membuat prefix list yang menghapus elemen yang tidak terurut mengecil pada kiri pivot
    CreateListDin(&pref, CAPACITY);
    insertLast(&pref, ELMT(l, getFirstIdx(l)));

    // Membuat suffix list yang menghapus elemen yang tidak terurut membesar pada kanan pivot
    CreateListDin(&suff, CAPACITY);
    insertLast(&suff, ELMT(l, getLastIdx(l)));

    // Iterasi dan mengisi prefix and suffix lists
    for (IdxType i = 1; i <= getLastIdx(l); i++)
    {
        // ELMT(pref, i) = max(ELMT(l, i), ELMT(pref, i - 1));
        if (ELMT(l, i) > ELMT(pref, i - 1))
        {
            insertLast(&pref, ELMT(l, i));
        }
        else
        {
            insertLast(&pref, ELMT(pref, i - 1));
        }

        // ELMT(suff, i) = min(ELMT(l, getLastIdx(l) - i), ELMT(suff, i - 1));
        if (ELMT(l, getLastIdx(l) - i) < ELMT(suff, i - 1))
        {
            insertLast(&suff, ELMT(l, getLastIdx(l) - i));
        }
        else
        {

            insertLast(&suff, ELMT(suff, i - 1));
        }
    }

    /* Sebelumnya dilakukan pengisian suffix dari kiri ke kanan untuk menghindari random value assingment */
    /* Oleh karena itu, perlu dilakukan reverse pada suffix list agar sesuai definisi suffix list*/
    IdxType start = getFirstIdx(l), end = getLastIdx(l);
    while (start < end)
    {
        ElType temp = ELMT(suff, start);
        ELMT(suff, start) = ELMT(suff, end);
        ELMT(suff, end) = temp;
        start++;
        end--;
    }

    // Menghitung jumlah pivot
    int pivot = 0;
    for (IdxType i = 0; i <= getLastIdx(l); i++)
    {
        int left = -1;
        if (i > 0)
        {
            left = ELMT(pref, i - 1);
        }

        int right = INT_MAX + 1;
        if (i < getLastIdx(l))
        {
            right = ELMT(suff, i + 1);
        }

        // [left, pivot, right]
        if (right > ELMT(l, i) && left < ELMT(l, i))
        {
            pivot++;
        }
    }
    printf("%d\n", pivot);

    dealocateList(&l);
    dealocateList(&pref);
    dealocateList(&suff);

    return 0;
}
