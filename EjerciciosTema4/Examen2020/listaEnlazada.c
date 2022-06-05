#include "listaEnlazada.h"

struct listaEnlazada *cargarRegistrosDeFicheroALista(char *rutaFichero, int *error)
{
    struct listaEnlazada *lista = NULL;
    struct listaEnlazada *indice = NULL;
    struct listaEnlazada *anterior = NULL;
    struct listaEnlazada *nuevo = NULL;
    FILE *fichero = NULL;
    struct tipoInfo aux;

    *error = 0;

    if (rutaFichero == NULL)
    {
        *error = -1;
        return lista;
    }

    if ((fichero = fopen(rutaFichero, "r")) == NULL)
    {
        *error = -2;
        return lista;
    }

    while (EOF != fscanf(fichero, "%[^\t]%*c%d%*c", aux.nombre, &aux.codigo))
    {
        anterior = NULL;
        indice = lista;

        while (indice != NULL && indice->info.codigo > aux.codigo)
        {
            anterior = indice;
            indice = indice->sig;
        }

        if (NULL == (nuevo = malloc(sizeof(struct listaEnlazada))))
        {
            while (lista != NULL)
            {
                indice = lista;
                lista = lista->sig;
                free(indice);
            }

            lista = NULL;
            *error = -3;
            fclose(fichero);
            return lista;
        }

        nuevo->info = aux;
        nuevo->sig = NULL;

        if (anterior == NULL)
        {
            nuevo->sig = lista;
            lista = nuevo;
        }
        else
        {
            anterior->sig = nuevo;
            nuevo->sig = indice;
        }

        (*error)++;
    }

    fclose(fichero);
    return lista;
}

int filtrarListaAFichero(char *rutaFichero, struct listaEnlazada **lista, int inf, int sup)
{
    struct listaEnlazada *indice, *anterior;
    FILE *fichero = NULL;
    int cont = 0;

    if (rutaFichero == NULL)
        return -1;

    if (*lista == NULL)
        return -2;

    if (inf <= sup)
        return -3;

    if ((fichero = fopen(rutaFichero, "w")) == NULL)
        return -4;

    indice = *lista;
    anterior = NULL;

    while (indice != NULL)
    {
        if (indice->info.codigo <= sup && indice->info.codigo >= inf)
        {
            fprintf(fichero, "%s\t%d\n", indice->info.nombre, indice->info.codigo);
            cont++;

            if (anterior == NULL)
            {
                *lista = indice->sig;
                free(indice);
                indice = *lista;
            }
            else
            {
                anterior->sig = indice->sig;
                free(indice);
                indice = anterior->sig;
            }
        }
        else
        {
            anterior = indice;
            indice = indice->sig;
        }
    }

    return cont;
}