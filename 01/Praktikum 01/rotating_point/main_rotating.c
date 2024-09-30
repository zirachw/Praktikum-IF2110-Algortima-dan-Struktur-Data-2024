/* File : main_rotating.c */
/* Program MainRotating */
/* Driver Rotating_Point */

#include <stdio.h>
#include <math.h>
#include "rotating_point.c"
#include "complex.c"
#include "point.c"

int main()
{   
    POINT P;
    CreatePoint(&P, 0.3, 0.5);

    COMPLEX C;
    CreateComplex(&C, 1.0, 1.0); 

    TulisPOINT(P);
    printf("\n");
    TulisCOMPLEX(C);
    
    int n = 0;

    TransformPointByComplexPower(&P, C, n);
}