#include "IOVECTOR.h"
#include <stdio.h>

int inputVector(double *vector, int dim)
{
    if (dim <= 0)
        return 0;

    int i = 0;

    for (i = 0; i < dim; i++)
    {
        printf("\nIntroduzca el valor en [%d]: ", i);
        scanf("%lf", &vector[i]);
    }

    return 1;
}

void presentarVector(double *vector, int dim)
{
    int i;

    printf("(");
    for (i = 0; i < dim; i++)
        printf(" %lf", vector[i]);

    printf(")");
}