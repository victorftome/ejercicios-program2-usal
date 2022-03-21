#include "vectorAux.h"
#define N 10

int main(void)
{
    // Realizamos sizeof(int) * N, ya que malloc realiza la reserva de la cantidad de bytes
    // que le indicamos. Por tanto, tendremos que multiplicar la cantidad de bytes que queremos
    // por el tamaño en bytes que ocupa nuestro tipo de dato. Y para obtener ese dato usamos sizeof
    int *vx = malloc(N * sizeof(int));
    int i, errNum;

    if (vx == NULL)
    {
        printf("Error realizando la reserva de memoria.\nSALIENDO...");
        return 1;
    }

    puts("VECTOR ESTÁTICO");
    puts("========================");
    puts("");
    puts("Estudio de las posiciones de memoria donde se almecenan los datos estáticos");
    puts("");

    puts("Variables estáticas:");
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

    free(vx);

    return 0;
}