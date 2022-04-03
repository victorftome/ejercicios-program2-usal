#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "empleado.h"

int main(void)
{

    tipoEmpleado *regEmpleados = NULL;
    tipoEmpleado **regEmpleadosRef = NULL;
    int numEmpleados, errNum = -1;
    clock_t tiempoInicial, tiempoFinal;

    printf("\nNúmero de empleados: ");
    scanf("%d%*c", &numEmpleados);
    printf("\nEl tamaño de un registro es: %ld\n\n", sizeof(tipoEmpleado));
    regEmpleados = crearVectorRegistros(numEmpleados, &errNum);
    if (regEmpleados == NULL)
    {
        printf("Error en crearRegistros: %d\n", errNum);
        return -1;
    }

    if (!cargarRegistrosAleatorios(regEmpleados, numEmpleados))
    {
        printf("\n\nValores no clasificados vector registros: \n");
        mostrarRegistros(regEmpleados, numEmpleados);
    }
    tiempoInicial = tiempoFinal = clock();
    ordenarRegistrosApellido(regEmpleados, numEmpleados);
    tiempoFinal = clock();

    printf("\n\nValores clasificados vector de registros: \n");
    printf("Tiempo tardado: %f\n", (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC);
    mostrarRegistros(regEmpleados, numEmpleados);

    regEmpleadosRef = crearRegistrosRef(numEmpleados, &errNum);
    if (regEmpleadosRef == NULL)
    {
        printf("Error en crearRegistrosRef: %d\n", errNum);
        return -1;
    }
    if (!cargarRegistrosAleatoriosRef(regEmpleadosRef, numEmpleados))
    {
        printf("\n\nValores no clasificados vector punteros a registros: \n");
        mostrarRegistrosRef(regEmpleadosRef, numEmpleados);
    }

    tiempoInicial = tiempoFinal = clock();
    ordenarRegistrosRefApellido(regEmpleadosRef, numEmpleados);
    tiempoFinal = clock();

    printf("\n\nValores clasificados vector punteros a registros: \n");
    printf("Tiempo tardado: %f\n", (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC);
    mostrarRegistrosRef(regEmpleadosRef, numEmpleados);

    free(regEmpleados);
    if (!liberarMemRegistrosRef(regEmpleadosRef, numEmpleados))
        regEmpleadosRef = NULL;

    return 0;
}
