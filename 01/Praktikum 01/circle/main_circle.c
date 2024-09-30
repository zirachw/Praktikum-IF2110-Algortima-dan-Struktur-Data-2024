/* File : main_circle.c */
/* Program MainCircle*/
/* Driver ADT Circle*/

#include <stdio.h>
#include <math.h>
#include "circle.c"
#include "point.c"

int main()
{
    /* KELOMPOK VALIDASI TERHADAP TYPE */
    int 
    X = 1, Y = 2, R = 0;
    printf("%d\n", IsCIRCLEValid(X, Y, R));

    X = 1, Y = 2, R = 3;
    printf("%d\n", IsCIRCLEValid(X, Y, R));

    CIRCLE C;
    CreateCIRCLE(&C, X, Y, R);

    /* KELOMPOK BACA/TULIS */
    CIRCLE C1, C2;
    ReadCIRCLE(&C1);
    ReadCIRCLE(&C2);
    printf("Lingkaran yang Dibaca: \n");
    WriteCIRCLE(C);
    printf("\n");
    WriteCIRCLE(C1);
    printf("\n");
    WriteCIRCLE(C2);
    printf("\n");

    /* KELOMPOK OPERASI GEOMETRI TERHADAP TYPE */
    float cir = Circumference(C);
    printf("%f\n", cir);

    float ar = Area(C);
    printf("%f\n", ar);

    POINT P ;
    CreatePoint(&P, 2, 2); 
    boolean inside = IsPOINTInsideCIRCLE(C, P);
    printf("%d\n", inside);

    boolean edge = IsPOINTInEdgeCIRCLE(C, P);
    printf("%d\n", edge);

    boolean tangents = IsCIRCLESTangents(C1, C2);
    printf("%d\n", tangents);

    boolean intersects = IsCIRCLESIntersects(C1, C2);
    printf("%d\n", intersects);

}