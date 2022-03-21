#include "vectorAux.h"

int cargarValoresAleatorios(int *vector, size_t tam, int rangoInf, int rangoSup)
{
    int i;
    if (tam < 1 || rangoInf > rangoSup)
        return 1;

    for (i = 0; i < tam; i++)
        vector[i] = rand() % (rangoSup - rangoInf) + rangoInf;

    return 0;
}

int cargarValoresTeclado(int *vector, size_t tam)
{
    int i;

    if (tam < 1)
        return 1;

    for (i = 0; i < tam; i++)
    {
        printf("Introduzca el valor [%d]: ", (i + 1));
        scanf(" %d", vector++);
    }

    return 0;
}

int mostrarValores(int *vector, size_t tam)
{
    int i;

    if (tam < 1)
        return 1;

    for (i = 0; i < tam; i++)
        printf(" %d | ", vector[i]);

    return 0;
}
