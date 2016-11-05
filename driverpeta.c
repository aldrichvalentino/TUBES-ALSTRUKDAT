//driver MATRIKS

#include "matriks.h"
#include "point.h"
#include "mesinkar.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
    MATRIKS M1,M2,M3,M4,M5;

    BacaMATRIKS(&M1,&M2,&M3,&M4,&M5,20,20);
    TulisMATRIKS(M1);
    printf("\n");
    TulisPOINT(WayOut(M1,0));
    TulisPOINT(WayOut(M1,1));
    TulisPOINT(WayOut(M1,2));
    TulisPOINT(WayOut(M1,3));
    printf("\n");

    TulisMATRIKS(M2);
    printf("\n");
    TulisPOINT(WayOut(M2,0));
    TulisPOINT(WayOut(M2,1));
    TulisPOINT(WayOut(M2,2));
    TulisPOINT(WayOut(M2,3));
    printf("\n");

    TulisMATRIKS(M3);
    printf("\n");
    TulisPOINT(WayOut(M3,0));
    TulisPOINT(WayOut(M3,1));
    TulisPOINT(WayOut(M3,2));
    TulisPOINT(WayOut(M3,3));
    printf("\n");

    TulisMATRIKS(M4);
    printf("\n");
    TulisPOINT(WayOut(M4,0));
    TulisPOINT(WayOut(M4,1));
    TulisPOINT(WayOut(M4,2));
    TulisPOINT(WayOut(M4,3));
    printf("\n");

    TulisMATRIKS(M5);
    printf("\n");
    TulisPOINT(WayOut(M5,0));
    TulisPOINT(WayOut(M5,1));
    TulisPOINT(WayOut(M5,2));
    TulisPOINT(WayOut(M5,3));
    printf("\n");

    return 0;
}
