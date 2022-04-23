#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;

struct nodo
{
    int info;
    nodo *sig;
};

nodo *creacionListaSimplementeEnlazada(int numNodos);
nodo *creacionListaSimplementeEnlazadaAlReves(int numNodos);
nodo *creacionListaOrdenada(int numNodos);
void insertarNodoOrdenado(int dato, nodo **lista);

int insertAtIndex(int index, nodo *lista, int dato);
int deleteAtIndex(int index, nodo *lista);

void mostrarValores(nodo *lista);

int liberacionLista(nodo **lista);