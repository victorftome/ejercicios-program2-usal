#include "vectorAux.h"
#define N 10

int main(void)
{
    int vx[N] = {0};
    int i, errNum;

    puts("VECTOR ESTÁTICO");
    puts("========================");
    puts("");
    puts("Estudio de las posiciones de memoria donde se almecenan los datos estáticos");
    puts("");

    puts("Variables estáticas:");
    puts("    int vx[N] = {0};  N=10");
    puts("    int i;          ");
    puts("                    ");
    printf("Dirección último elemento de vx: %p \n", vx + (N - 1));
    printf("Dirección comienzo de vx.......: %p \n", vx);
    printf("Dirección de i.................: %p \n", &i);

    printf("\n\n");
    printf("Carga valores aleatorios:\n");

    errNum = cargarValoresAleatorios(vx, N, 10, 100);
    if (!errNum)
        mostrarValores(vx, N);

    printf("\n\n");

    printf("Carga valores teclado:\n");

    errNum = cargarValoresTeclado(vx, N);

    if (!errNum)
        mostrarValores(vx, N);

    return 0;
}