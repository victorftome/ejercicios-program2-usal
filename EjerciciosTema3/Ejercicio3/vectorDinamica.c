#include "vectorDinamica.h"

void *crearVectorDinamico(size_t size)
{
    return malloc(size);
}

int liberarMemoria(void *ptr)
{
    if (ptr == NULL)
        return -1;

    free(ptr);

    return 0;
}