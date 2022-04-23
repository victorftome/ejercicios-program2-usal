#include "listaSimple.h"

nodo *creacionListaSimplementeEnlazada(int numNodos)
{
    nodo *lista = NULL;
    nodo *indice = NULL;
    nodo *nuevo = NULL;

    int i;

    for (i = 0; i < numNodos; i++)
    {
        nuevo = malloc(sizeof(nodo));

        nuevo->info = i;
        nuevo->sig = NULL;

        if (lista == NULL)
        {
            lista = nuevo;
            indice = nuevo;
        }
        else
        {
            indice->sig = nuevo;
            indice = nuevo;
        }
    }

    return lista;
}

nodo *creacionListaSimplementeEnlazadaAlReves(int numNodos)
{
    nodo *lista = NULL;
    nodo *nuevo = NULL;

    int i;

    for (i = 0; i < numNodos; i++)
    {
        if (lista == NULL)
        {
            lista = malloc(sizeof(nodo));
            lista->info = i;
            lista->sig = NULL;
        }
        else
        {
            nuevo = malloc(sizeof(nodo));
            nuevo->info = i;
            nuevo->sig = lista;
            lista = nuevo;
        }
    }

    return lista;
}

nodo *creacionListaOrdenada(int numNodos)
{
    nodo *lista = NULL;
    int i, num;

    if (numNodos <= 0)
        return NULL;

    for (i = 0; i < numNodos; i++)
    {
        printf("Introduzca el dato a almacenar: ");
        scanf("%d", &num);

        insertarNodoOrdenado(num, &lista);
    }

    return lista;
}

void insertarNodoOrdenado(int dato, nodo **lista)
{
    nodo *indice = NULL;
    nodo *nuevo = NULL;
    nodo *anterior = NULL;
    int i;

    indice = *lista;

    if ((nuevo = malloc(sizeof(nodo))) == NULL)
        return;

    nuevo->info = dato;
    nuevo->sig = NULL;

    if (indice == NULL)
    {
        *lista = nuevo;
    }
    else
    {

        while (indice != NULL && indice->info < nuevo->info)
        {
            anterior = indice;
            indice = indice->sig;
        }

        if (indice == NULL)
        {
            anterior->sig = nuevo;
        }
        else
        {
            if (anterior == NULL)
            {
                nuevo->sig = *lista;
                *lista = nuevo;
            }
            else
            {
                anterior->sig = nuevo;
                nuevo->sig = indice;
            }
        }
    }
}

int insertAtIndex(int index, nodo *lista, int dato)
{
    nodo *indice = NULL;
    nodo *anterior = NULL;
    nodo *nuevo = NULL;

    int i;

    if (lista == NULL)
        return 2;

    indice = lista;

    for (i = 0; i < index && indice != NULL; i++)
    {
        anterior = indice;
        indice = indice->sig;
    }

    if (anterior == NULL)
    {
        if ((anterior = malloc(sizeof(nodo))) == NULL)
            return 1;

        anterior->info = dato;
        anterior->sig = lista;
        lista = anterior;
    }
    else
    {
        if ((nuevo = malloc(sizeof(nodo))) == NULL)
            return 1;

        nuevo->info = dato;
        nuevo->sig = indice;
        anterior->sig = nuevo;
    }

    return 0;
}

int deleteAtIndex(int index, nodo *lista)
{
    nodo *indice = NULL;
    nodo *anterior = NULL;
    int i;

    if (lista == NULL)
        return 2;

    if (index < 0)
        return 3;

    indice = lista;

    for (i = 0; i < index && indice != NULL; i++)
    {
        anterior = indice;
        indice = indice->sig;
    }

    if (anterior == NULL)
    {
        lista = indice->sig;
        free(indice);
    }
    else
    {
        anterior->sig = indice->sig;
        free(indice);
    }

    return 0;
}

void mostrarValores(nodo *lista)
{
    nodo *index;
    index = lista;

    int cont = 0;

    while (index != NULL)
    {
        printf("Dato[%d]: %d\n", cont, index->info);
        index = index->sig;
        cont++;
    }
}

int liberacionLista(nodo **lista)
{
    nodo *index = NULL;

    if (*lista == NULL)
        return 1;

    while (*lista != NULL)
    {
        index = *lista;
        *lista = (*lista)->sig;
        free(index);
    }

    return 0;
}