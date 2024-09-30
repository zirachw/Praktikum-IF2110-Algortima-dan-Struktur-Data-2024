/* File: rotating_point.c */
/* Tanggal: 26 September 2024 */
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include "point.h"
#include "complex.h"

/* Catatan: Hasil perkalian float dan int adalah float*/

/* Fungsi untuk menghitung perpangkatan bilangan kompleks */
/* Formula: Bilangan kompleks dikalikan dirinya sendiri sebanyak P kali */
COMPLEX PowerCOMPLEX(COMPLEX C, int p)
{
    COMPLEX result = C;
    if (p == 0) {
        Real(result) = 1;
        Imag(result) = 0;
        return result;
    }
    for (int i = 1; i < p; i++) {
        result = MultiplyCOMPLEX(result, C);
        // printf("p: %d, re: %.2f, im: %.2f\n", p, Real(result), Imag(result));
    }
    return result;
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n)
{
    float x = Absis(*P);
    float y = Ordinat(*P);
    boolean exceed = false;
    
    if (n == 0)
    {
        printf("Titik keluar dari lingkaran pada iterasi ke %d", n);
    }
    else
    {
        for (int i = 1; i <= n; i++) {
            COMPLEX pC = PowerCOMPLEX(C, i);

            float re = Real(pC);
            float im = Imag(pC);
            float newX = x * re - y * im;
            float newY = x * im + y * re;

            x = newX;
            y = newY;
            // printf("i: %d, re: %.2f im: %.2f P(%.2f, %.2f), len: %.2f\n", i, re, im, x, y, x * x + y * y);
            if (x * x + y * y > 1) {
                exceed = true;
                printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
                break;
            }   
        }
        if (exceed == false)
        {
            printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);
        }
    }
}