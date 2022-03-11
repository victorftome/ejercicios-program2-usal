#include "VECTOR.h"
#include <math.h>

double modulo(double *vector, int dim)
{
    int i;
    double acumulador = 0;

    for (i = 0; i < dim; i++)
        acumulador += pow(vector[i], 2);

    return sqrt(acumulador);
}

void vectorSuma(double *v1, double *v2, int dim, double *vresultado)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        vresultado[i] = 0;
        vresultado[i] = v1[i] + v2[i];
    }
}

double productoEscalar(double *v1, double *v2, int dim)
{
    int i;
    double acumulador = 0;
    for (i = 0; i < dim; i++)
        acumulador += v1[i] * v2[i];

    return acumulador;
}