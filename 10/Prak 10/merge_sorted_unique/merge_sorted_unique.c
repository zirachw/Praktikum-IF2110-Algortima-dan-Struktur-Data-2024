/* File : merge_sorted_unique.c */
/* Tanggal: 3 Desember 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

List deleteDups(List l, List unique)
{
    if (!isEmpty(l))
    {
        if (isEmpty(unique))
        {
            unique = konsb(unique, head(l));
        }
        else
        {
            if (!isMember(unique, head(l)))
            {
                unique = konsb(unique, head(l));
            }
        }
        unique = deleteDups(tail(l), unique);
    }
    else
    {
        return unique;
    }
}

void mergeSortedUnique(List l1, List l2, List *res)
{
    List merged = NIL;
    Address p1 = l1, p2 = l2;

    while (p1 != NIL && p2 != NIL) 
    {
        if (INFO(p1) <= INFO(p2)) 
        {
            merged = concat(merged, newNode(INFO(p1)));
            p1 = NEXT(p1);
        } 
        else 
        {
            merged = concat(merged, newNode(INFO(p2)));
            p2 = NEXT(p2);
        }
    }

    while (p1 != NIL) 
    {
        merged = concat(merged, newNode(INFO(p1)));
        p1 = NEXT(p1);
    }

    while (p2 != NIL) 
    {
        merged = concat(merged, newNode(INFO(p2)));
        p2 = NEXT(p2);
    }

    *res = deleteDups(merged, *res);
}