#include <stdio.h>

#define MAX_VALUE 100
#define MIN_VALUE 3

void matrizMarco(int (*matriz)[MAX_VALUE], int filas, int columnas, int *resultado);

int main()
{
    int resultado, rows, cols;
    int matriz[MAX_VALUE][MAX_VALUE];
    int i, j;

    printf("Introduzca las filas y columnas separadas por un espacio: ");

    do
    {
        scanf("%d %d", &rows, &cols);
    } while (rows < MIN_VALUE || cols < MIN_VALUE || rows > MAX_VALUE || cols > MAX_VALUE);

    printf("Rellena el vector\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
        {
            printf("Numero en la posicion [%d][%d]: ", i, j);
            scanf(" %d", &matriz[i][j]);
        }

    matrizMarco(matriz, rows, cols, &resultado);

    printf("La matriz ");

    if (!resultado)
        printf("no es marco");

    if (resultado == 1)
        printf("es marco");

    if (resultado == 2)
        printf("es marco perfecto");
}

void matrizMarco(int (*matriz)[MAX_VALUE], int filas, int columnas, int *resultado)
{
    int i, j, sumaMarco = 0, sumaInteriores = 0, perfecta = 1;
    int sumaColumna, aux;

    // Sumamos los valores del marco y de los interiores
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (!i || !j || j == columnas - 1 || i == filas - 1)
            {
                sumaMarco += matriz[i][j];
                continue; // Pasa a la siguiente iteracción
            }

            sumaInteriores += matriz[i][j];
        }
    }

    for (i = 1; i < columnas - 1; i++)
    {
        sumaColumna = 0;

        for (j = 1; j < filas - 1; j++)
            sumaColumna += matriz[j][i];

        if (i == 1)
        {
            aux = sumaColumna;
            continue;
        }

        if (aux != sumaColumna)
        {
            perfecta = 0;
            break;
        }
    }

    if (perfecta && sumaMarco > sumaInteriores)
        *resultado = 2;
    else if (sumaMarco > sumaInteriores)
        *resultado = 1;
    else
        *resultado = 0;
}