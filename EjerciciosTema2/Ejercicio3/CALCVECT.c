#include <stdio.h>

#include "VECTOR.h"
#include "IOVECTOR.h"

#define VEC_SIZE 25

int main()
{
    double vec1[VEC_SIZE];
    double vec2[VEC_SIZE];
    double vecSuma[VEC_SIZE];
    int dim;

    do
    {
        printf("\nIntroduzca la DIM de los vectores: ");
        scanf(" %d", &dim);
    } while (dim > 25 && dim <= 0);

    printf("Introduzca el primer vector: ");
    inputVector(vec1, dim);

    printf("\nIntroduzca el segundo vector: ");
    inputVector(vec2, dim);

    printf("Los vectores introducidos son: \n");
    presentarVector(vec1, dim);
    printf("\n");
    presentarVector(vec2, dim);

    printf("\nSus modulos son %lf y %lf respectivamente\n", modulo(vec1, dim), modulo(vec2, dim));

    vectorSuma(vec1, vec2, dim, vecSuma);
    printf("Su vector suma es: ");
    presentarVector(vecSuma, dim);

    printf("\nEl producto escalar del vector es: %lf", productoEscalar(vec1, vec2, dim));

    return 0;
}