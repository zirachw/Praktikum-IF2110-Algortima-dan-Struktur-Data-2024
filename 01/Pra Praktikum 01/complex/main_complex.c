/* File : main_complex.c */
/* Program MainComplex */
/* Driver ADT Complex */

#include <stdio.h>
#include "complex.c"

int main()
{   /* KAMUS */
    COMPLEX C1, C2;
    
    /* ***************************************************************** */
    /* KELOMPOK BACA/TULIS                                               */
    /* ***************************************************************** */
    BacaCOMPLEX(&C1);
    BacaCOMPLEX(&C2);
    printf("Bilangan Kompleks yang Dibaca: \n");
    TulisCOMPLEX(C1);
    TulisCOMPLEX(C2);

    /* ***************************************************************** */
    /* KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE                         */
    /* ***************************************************************** */
    COMPLEX add = AddCOMPLEX(C1, C2);
    printf("Add: ");
    TulisCOMPLEX(add);

    COMPLEX sub = SubtractCOMPLEX(C1, C2);
    printf("Sub: ");
    TulisCOMPLEX(sub);

    COMPLEX mul = MultiplyCOMPLEX(C1, C2);
    printf("Mul: ");
    TulisCOMPLEX(mul);

    COMPLEX div = DivideCOMPLEX(C1, C2);
    printf("Div: ");
    TulisCOMPLEX(div);

    /* ***************************************************************** */
    /* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
    /* ***************************************************************** */
    float abs1 = AbsCOMPLEX(C1);
    printf("%.2f\n", abs1);

    float abs2 = AbsCOMPLEX(C2);
    printf("%.2f\n", abs2);

    COMPLEX conj1 = ConjugateCOMPLEX(C1);
    printf("Conj1: ");
    TulisCOMPLEX(conj1);

    COMPLEX conj2 = ConjugateCOMPLEX(C2);
    printf("Conj2: ");
    TulisCOMPLEX(conj2);

    /* *** Kelompok Operator Relational *** */
    boolean same = CEQ(C1, C2);
    printf("%d\n", same);

    boolean not = CNEQ(C1, C2);
    printf("%d\n", not);

    return 0;
}   