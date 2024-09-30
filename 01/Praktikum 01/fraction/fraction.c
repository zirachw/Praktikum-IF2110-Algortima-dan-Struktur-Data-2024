/* File: fraction.c */
/* Tanggal: 26 September 2024 */
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include "fraction.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

boolean IsFRACTIONValid(int N, int D)
/* Mengirim TRUE jika pecahan valid */
{
    return D != 0;
}

/* *** Konstruktor: Membentuk FRACTION F dari komponen-komponennya *** */
void CreateFRACTION(FRACTION *F, int N, int R)
/* Membentuk sebuah FRACTION yang valid */
/* Prekondisi : N, R valid */
{
    Numerator(*F) = N;
    Denominator(*F) = R;    
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadFRACTION(FRACTION *F)
/**
 * I.S. : F tidak terdefinisi
 * F.S. : F terdefinisi dan merupakan FRACTION yang valid
 * Proses : Mengulangi membaca komponen N, R sehingga membentuk F
 *  - Pembacaan dilakukan dengan mengetikkan komponen N, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika FRACTION tidak valid, maka berikan pesan: "FRACTION tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat FRACTION yang valid.
 */
{
    int N, R;
    scanf("%d %d", &N, &R);

    while (!(IsFRACTIONValid(N, R)))
    {
        printf("FRACTION tidak valid\n");
        scanf("%d %d", &N, &R);
    }
    CreateFRACTION(F, N, R);
}


void WriteFRACTION(FRACTION F)
/**
 * I.S. : F sembarang
 * F.S. : Nilai F ditulis dengan format "N/R"
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 * NOTE: hasil dalam bentuk paling sederhana
 */

/* ***************************************************************** */
/* KELOMPOK OPERASI DASAR TERHADAP TYPE                              */
/* ***************************************************************** */
/* NOTE: untuk hasil FRACTION = 0, maka kembalikan 0/1 */
{
    F = SimplifyFRACTION(F);
    printf("%d/%d", Numerator(F), Denominator(F));
}

FRACTION AddFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil penjumlahan F1 + F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    FRACTION result;
    int N = (Numerator(F1) * Denominator(F2)) + (Numerator(F2) * Denominator(F1));
    int D = Denominator(F1) * Denominator(F2);
    CreateFRACTION(&result, N, D);
    return SimplifyFRACTION(result);
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil pengurangan F1 - F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    FRACTION result;
    int N = (Numerator(F1) * Denominator(F2)) - (Numerator(F2) * Denominator(F1));
    int D = Denominator(F1) * Denominator(F2);
    CreateFRACTION(&result, N, D);
    return SimplifyFRACTION(result);
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil perkalian F1 * F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    FRACTION result;
    int N = Numerator(F1) * Numerator(F2);
    int D = Denominator(F1) * Denominator(F2);
    CreateFRACTION(&result, N, D);
    return SimplifyFRACTION(result);
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil pembagian F1 / F2 */
/* Prekondisi: F2 tidak nol */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    FRACTION result;
    int N = Numerator(F1) * Denominator(F2);
    int D = Denominator(F1) * Numerator(F2);
    CreateFRACTION(&result, N, D);
    return SimplifyFRACTION(result);
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1)
/* Mengirim hasil perkalian n * F1 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    FRACTION result;
    int N = n * Numerator(F1);
    int D = Denominator(F1);
    CreateFRACTION(&result, N, D);
    return SimplifyFRACTION(result);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
FRACTION SimplifyFRACTION(FRACTION F)
/* Mengembalikan FRACTION dalam bentuk sederhana */
/* NOTE: pastikan hanya numerator yang memiliki nilai negatif */
{
    int fpb = gcd(Numerator(F), Denominator(F));
    Numerator(F) /= fpb;
    Denominator(F) /= fpb;

    if (Denominator(F) < 0) {
        Numerator(F) = -Numerator(F);
        Denominator(F) = -Denominator(F);
    }
    return F;
}

float ToDecimal(FRACTION F)
/* Mengonversi FRACTION ke bentuk desimal */
{
    return (float) Numerator(F) / Denominator(F);
}
