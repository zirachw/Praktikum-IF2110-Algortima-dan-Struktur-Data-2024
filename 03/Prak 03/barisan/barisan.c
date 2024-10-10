#include <stdio.h>
#include "listdin.h"

int main()
{
    int CAPACITY = 1000, mundur = 0;

    ListDin l, siswa;
    CreateListDin(&l, CAPACITY);
    CreateListDin(&siswa, CAPACITY);
    readList(&l);

    for (IdxType i = 0; i <= getLastIdx(l); i++)
    {
        insertLast(&siswa, ELMT(l, i));

        for (IdxType j = getFirstIdx(siswa); j < getLastIdx(siswa); j++)
        {
            if (ELMT(siswa, j) > ELMT(siswa, getLastIdx(siswa)))
            {
                mundur++;
            }
        }
    }
    printf("%d\n", mundur);

    dealocateList(&l);
    dealocateList(&siswa);

    return 0;
}