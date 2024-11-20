/* File: mhanoi.c */
/* Tanggal: 24 Oktober 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "matrix.h"

int main()
{
    int n;
    scanf("%d", &n);

    Matrix papan, piring;

    createMatrix(n, n, &papan);
    createMatrix(2, 2, &piring);
    readMatrix(&papan, n, n);
    readMatrix(&piring, 2, 2);

    int count = 0;

    int i, j;
    for (i = 0; i <= getLastIdxRow(papan) - 1; i++)
    {
        for (int j = 0; j <= getLastIdxCol(papan) - 1; j++)
        {
            boolean valid = false;

            if (ELMT(papan, i, j) > ELMT(piring, 0, 0) && ELMT(papan, i, j + 1) > ELMT(piring, 0, 1) &&
                ELMT(papan, i + 1, j) > ELMT(piring, 1, 0) && ELMT(papan, i + 1, j + 1) > ELMT(piring, 1, 1))
            {
                valid = true;
            }

            if (ELMT(papan, i, j) > ELMT(piring, 1, 0) && ELMT(papan, i, j + 1) > ELMT(piring, 0, 0) &&
                ELMT(papan, i + 1, j) > ELMT(piring, 1, 1) && ELMT(papan, i + 1, j + 1) > ELMT(piring, 0, 1))
            {
                valid = true;
            }

            if (ELMT(papan, i, j) > ELMT(piring, 1, 1) && ELMT(papan, i, j + 1) > ELMT(piring, 1, 0) &&
                ELMT(papan, i + 1, j) > ELMT(piring, 0, 1) && ELMT(papan, i + 1, j + 1) > ELMT(piring, 0, 0))
            {
                valid = true;
            }

            if (ELMT(papan, i, j) > ELMT(piring, 0, 1) && ELMT(papan, i, j + 1) > ELMT(piring, 1, 1) &&
                ELMT(papan, i + 1, j) > ELMT(piring, 0, 0) && ELMT(papan, i + 1, j + 1) > ELMT(piring, 1, 0))
            {
                valid = true;
            }

            if (valid)
            {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}