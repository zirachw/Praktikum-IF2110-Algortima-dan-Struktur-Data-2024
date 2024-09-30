/* File : main_point.c */
/* Program MainPoint */
/* Driver ADT Point */

#include <stdio.h>
#include "point.c"

int main()
{   /* KAMUS */
    POINT P1, P2;
    
    /* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */    
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    printf("Point yang Dibaca: \n");
    TulisPOINT(P1);
    printf("\n");
    TulisPOINT(P2);
    printf("\n");

    /* *** Kelompok operasi relasional terhadap POINT *** */
    boolean same = EQ(P1, P2);
    printf("%d\n", same);

    boolean not = NEQ(P1, P2);
    printf("%d\n", not);

    /* *** Kelompok menentukan di mana P berada *** */
    boolean origin = IsOrigin(P1);
    printf("%d\n", origin);

    boolean sbx = IsOnSbX(P1);
    printf("%d\n", sbx);

    boolean sby = IsOnSbY(P1);
    printf("%d\n", sby);

    int kuad = Kuadran(P2);
    printf("%d\n", kuad);

    /* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */    
    POINT nex = NextX(P1);
    TulisPOINT(nex);
    printf("\n");

    POINT ney = NextY(P1);
    TulisPOINT(ney);
    printf("\n");

    POINT plusdel = PlusDelta(P1, 1, 2);
    TulisPOINT(plusdel);
    printf("\n");

    POINT mirrorcopy = MirrorOf(P2, true);
    TulisPOINT(mirrorcopy);
    printf("\n");

    float jarak = Jarak0(P2);
    printf("%.2f\n", jarak);

    float len = Panjang(P1, P2);
    printf("%.2f\n", len);

    PersamaanLinearDuaVariabel(P1, P2);
}