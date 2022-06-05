#ifndef _LISTA_ENLAZADA_H_
#define _LISTA_ENLAZADA_H_

#include <stdio.h>
#include <stdlib.h>

struct tipoInfo
{
    char nombre[30];
    int codigo;
};

struct listaEnlazada
{
    struct tipoInfo info;
    struct listaEnlazada *sig;
};

struct listaEnlazada *cargarRegistrosDeFicheroALista(char *rutaFichero, int *error);
int filtrarListaAFichero(char *rutaFichero, struct listaEnlazada **lista, int inf, int sup);

#endif