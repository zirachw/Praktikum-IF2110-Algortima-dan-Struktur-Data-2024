/* File : hapus-duplikat.c */
/* Tanggal: 19 November 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include <stdlib.h>
#include "hapus-duplikat.h"

List hapusDuplikat(List l)
/**
 * Menerima masukan sebuah list l yang terurut mengecil
 * Mengembalikan list yang merupakan hasil penghapusan elemen yang mempunyai duplikat pada list l, terurut membesar
 * Contoh: hapusDuplikat(3->3->2->1) = 1->2 (-> adalah panah next pada list linear)
 */
{
    List result;
    CreateList(&result);

    while (l != NULL)
    {
        boolean occur = false;
        while (NEXT(l) != NULL && INFO(l) == INFO(NEXT(l)))
        {
            l = NEXT(l);
            occur = true;
        }

        if (occur)
        {
            l = NEXT(l);
        }
        else if (l != NULL)
        {
            insertLast(&result, INFO(l));
            l = NEXT(l);
        }
    }

    List reverse;
    ElType temp;
    CreateList(&reverse);

    while (length(result) != 0)
    {
        deleteLast(&result, &temp);
        insertLast(&reverse, temp);
    }

    return reverse;
}
