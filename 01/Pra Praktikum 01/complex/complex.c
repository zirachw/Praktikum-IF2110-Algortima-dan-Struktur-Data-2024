/* File: complex.c */
/* Tanggal: 24 September 2024 */
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

/* Definisi ADT COMPLEX */
/* Catatan: Gunakan %.2f pada printf serta %f untuk scanf untuk mengeluarkan dan membaca float */

#include "complex.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsCOMPLEXValid(float Re, float Im)
/* Mengirim true jika Re dan Im valid untuk membentuk COMPLEX */
/* Dalam konteks kompleks, semua bilangan real adalah valid */
{
    return true;
}

/* *** Konstruktor: Membentuk sebuah COMPLEX dari komponen-komponennya *** */
void CreateComplex(COMPLEX *C, float Re, float Im)
/* Membentuk sebuah COMPLEX dari komponen-komponennya */
{   /* Kamus Lokal */
    /* Algoritma */
    Real(*C) = Re;
    Imag(*C) = Im;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaCOMPLEX(COMPLEX *C)
/* I.S. : C tidak terdefinisi */
/* F.S. : C terdefinisi */
/* Proses : Membaca komponen Re dan Im dari pengguna */
{
    float Re, Im;
    do 
    {
        scanf("%f %f", &Re, &Im);

    }
    while(!IsCOMPLEXValid(Re, Im));
    CreateComplex(C, Re, Im);
}

void TulisCOMPLEX(COMPLEX C)
/* I.S. : C sembarang */
/* F.S. : Nilai C ditulis dengan format "a + bi" atau "a - bi" (tanpa spasi) dan diakhiri newline */
/* Proses : Menulis nilai Re dan Im ke layar */
{
    if (Imag(C) < 0)
    {
        printf("%.2f%.2fi\n", Real(C), Imag(C));
    }
    else 
    {
        printf("%.2f+%.2fi\n", Real(C), Imag(C));
    }
}

/* ***************************************************************** */
/* KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE                         */
/* ***************************************************************** */
COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2)
/* Mengirim hasil penjumlahan C1 + C2 */
{
    COMPLEX result;
    Real(result) = Real(C1) + Real(C2);
    Imag(result) = Imag(C1) + Imag(C2);
    return result;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2)
/* Mengirim hasil pengurangan C1 - C2 */
{
    COMPLEX result;
    Real(result) = Real(C1) - Real(C2);
    Imag(result) = Imag(C1) - Imag(C2);
    return result;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2)
/* Mengirim hasil perkalian C1 * C2 */
/* Rumus: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i */
{
    COMPLEX result;
    Real(result) = (Real(C1) * Real(C2)) - (Imag(C1) * Imag(C2));
    Imag(result) = (Real(C1) * Imag(C2)) + (Imag(C1) * Real(C2));
    return result;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2)
/* Mengirim hasil pembagian C1 / C2 */
/* Rumus: (a + bi) / (c + di) = [(a + bi)(c - di)] / (c^2 + d^2) */
/* Jika denominator pecahan bernilai 0, maka kembalikan nilai 0+0i*/
{
    COMPLEX result;
    float denominator = Real(C2) * Real(C2) + Imag(C2) * Imag(C2);
    if (denominator == 0)
    {
        Real(result) = 0;
        Imag(result) = 0;
    }   
    else
    {
        Imag(C2) = -Imag(C2);
        COMPLEX numerator = MultiplyCOMPLEX(C1, C2);
        Real(result) = Real(numerator) / denominator ;
        Imag(result) = Imag(numerator) / denominator ;
    }
    return result;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
float AbsCOMPLEX(COMPLEX C)
/* Mengirim nilai absolut (modulus) dari C */
/* Rumus: |C| = sqrt(Re^2 + Im^2) */
{
    float abs;
    abs = sqrt(Real(C) * Real(C) + Imag(C) * Imag(C));
    return abs;
}

COMPLEX ConjugateCOMPLEX(COMPLEX C)
/* Mengirim hasil konjugasi dari C */
/* Rumus: Conj(C) = Re - i*Im */
{
    COMPLEX conj;
    Real(conj) = Real(C);
    Imag(conj) = -Imag(C);
    return conj;
}

/* *** Kelompok Operator Relational *** */
boolean CEQ(COMPLEX C1, COMPLEX C2)
/* Mengirimkan true jika C1 = C2 (Re dan Im sama) */
{
    return (Real(C1) == Real(C2) && Imag(C1) == Imag(C2));
}

boolean CNEQ(COMPLEX C1, COMPLEX C2)
/* Mengirimkan true jika C1 tidak sama dengan C2 */
{
    return (Real(C1) != Real(C2) || Imag(C1) != Imag(C2));
}

/* ***************************************************************** */