#include "listaSimple.h"

int main()
{
    nodo *lista;

    int num, dato, error_code;

    printf("Introduzca el numero de elementos de la lista a crear agregando nodos al final: ");
    scanf("%d", &num);

    lista = creacionListaSimplementeEnlazada(num);

    printf("\n == Mostrando lista == \n");
    mostrarValores(lista);

    liberacionLista(&lista);

    printf("Introduzca el numero de elementos de la lista a crear agregando nodos por el comienzo: ");
    scanf("%d", &num);

    lista = creacionListaSimplementeEnlazadaAlReves(num);

    printf("\n == Mostrando lista == \n");
    mostrarValores(lista);

    do
    {
        printf("Introduzca alguna posicion a modificar (0-n): ");
        scanf("%d", &num);
    } while (num < 0);

    printf("Introduzca el nuevo dato a introducir: ");
    scanf("%d", &dato);

    error_code = insertAtIndex(num, lista, dato);

    printf("\n == Mostrando lista una vez modificada == \n");
    mostrarValores(lista);

    do
    {
        printf("Introduzca alguna posicion a eliminar (0-n): ");
        scanf("%d", &num);
    } while (num < 0);

    error_code = deleteAtIndex(num, lista);

    if (!error_code)
    {
        printf("\n == Mostrando lista eliminando el dato == \n");
        mostrarValores(lista);
    }

    liberacionLista(&lista);

    do
    {
        printf("\n\n==== Introduzca el numero de elementos a insertar ordenadamente ====\n\n");
        scanf("%d", &num);
    } while (num <= 0);

    lista = creacionListaOrdenada(num);

    printf("\n\n==== Mostrando lista ordenada ====\n");
    mostrarValores(lista);

    liberacionLista(&lista);

    return 0;
}