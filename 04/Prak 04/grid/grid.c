/* File: grid.c */
/* Tanggal: 24 Oktober 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "matrix.h"

#define MOD 1000000007

int main()
{
    int n;
    scanf("%d", &n);
    Matrix papan, langkah;

    createMatrix(n, n, &papan);
    createMatrix(n, n, &langkah);
    readMatrix(&papan, n, n);

    if (ELMT(papan, 0, 0) == 0)
    {
        ELMT(langkah, 0, 0) = 1;
    }
    else
    {
        ELMT(langkah, 0, 0) = 0;
    }

    int i, j;
    for (j = 1; j < COL_EFF(papan); j++)
    {
        if (ELMT(papan, 0, j) == 0 && ELMT(langkah, 0, j - 1) != 0)
        {
            ELMT(langkah, 0, j) = 1;
        }
        else
        {
            ELMT(langkah, 0, j) = 0;
        }
    }

    for (i = 1; i < ROW_EFF(papan); i++)
    {
        if (ELMT(papan, i, 0) == 0 && ELMT(langkah, i - 1, 0) != 0)
        {
            ELMT(langkah, i, 0) = 1;
        }
        else
        {
            ELMT(langkah, i, 0) = 0;
        }
    }

    for (i = 1; i < ROW_EFF(papan); i++)
    {
        for (j = 1; j < COL_EFF(papan); j++)
        {
            if (ELMT(papan, i, j) == 0)
            {
                ELMT(langkah, i, j) = (ELMT(langkah, i - 1, j) + ELMT(langkah, i, j - 1)) % MOD;
            }
            else
            {
                ELMT(langkah, i, j) = 0;
            }
        }
    }

    printf("%d\n", ELMT(langkah, n - 1, n - 1));

    return 0;
}