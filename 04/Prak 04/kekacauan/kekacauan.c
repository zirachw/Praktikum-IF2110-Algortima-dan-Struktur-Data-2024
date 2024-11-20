/* File: kekacauan.c */
/* Tanggal: 22 Oktober 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "matrix.h"

#define MOD 1000000007

int main()
{
    int n;
    scanf("%d", &n);

    Matrix m;
    createMatrix(n, n, &m);
    readMatrix(&m, n, n);

    long long kekacauan = 0;

    int i, j, k;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (ELMT(m, i, j) > 0)
            {
                long long row = 0;
                long long col = 0;

                for (k = 0; k < n; k++)
                {
                    if (ELMT(m, i, k) > 0)
                    {
                        row += ELMT(m, i, k);
                    }
                }

                for (k = 0; k < n; k++)
                {
                    if (ELMT(m, k, j) > 0)
                    {
                        col += ELMT(m, k, j);
                    }
                }

                long long kacau = row + col - 2 * ELMT(m, i, j);
                kekacauan = (kekacauan + kacau) % MOD;
            }
        }
    }

    printf("%lld\n", kekacauan);
    return 0;
}