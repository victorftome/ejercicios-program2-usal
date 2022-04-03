#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "empleado.h"

tipoEmpleado *
crearVectorRegistros(int numEmpleados, int *errNum)
{
    tipoEmpleado *res = NULL;

    if (numEmpleados <= 0)
    {
        *errNum = -1;
        return res;
    }

    if ((res = malloc(numEmpleados * sizeof(tipoEmpleado))) == NULL)
    {
        *errNum = -2;
        return res;
    }

    *errNum = 0;
    return res;
}

tipoEmpleado **
crearRegistrosRef(int numEmpleados, int *errNum)
{
    tipoEmpleado **res = NULL;
    int i;

    if (numEmpleados <= 0)
    {
        *errNum = -1;
        return res;
    }

    if (NULL == (res = malloc(sizeof(tipoEmpleado *) * numEmpleados)))
    {
        *errNum = -2;
        return res;
    }

    for (i = 0; i < numEmpleados; i++)
        if ((res[i] = malloc(sizeof(tipoEmpleado))) == NULL)
        {
            for (i--; i >= 0; i--)
            {
                free(res[i]);
                res[i] = NULL;
            }

            free(res);
            res = NULL;

            *errNum = -3;
            return res;
        }

    *errNum = 0;
    return res;
}

int liberarMemRegistrosRef(tipoEmpleado **empleadosRef, size_t numEmpleados)
{
    int i;
    if (empleadosRef == NULL)
        return -1;

    for (i = 0; i < numEmpleados; i++)
    {
        free(empleadosRef[i]);
        empleadosRef[i] = NULL;
    }

    free(empleadosRef);
    empleadosRef = NULL;
}

int cargarRegistroAleatorio(tipoEmpleado *empleado)
{
    static char apellidos[][15] = {"ALONSO", "ALVAREZ", "ARBESU",
                                   "DOMINGUEZ", "FERNANDEZ", "FLORIANO",
                                   "GONZALEZ", "GOMEZ", "GUTIERREZ",
                                   "MARTIN", "MORO", "PEREZ", "TURRION",
                                   "ZAMBRANO"};
    static char nombres[][15] = {"ALVARO", "ARSENIO", "DOMINGO",
                                 "FELIPE", "FATIMA", "FABIAN",
                                 "GONZALO", "PEDRO", "PATRICIA",
                                 "TOMAS", "ZOILO"};
    int numApellidos = sizeof(apellidos) / 15;
    int numNombres = sizeof(nombres) / 15;
    char buffer[5];

    if (empleado == NULL)
    {
#ifdef DEBUG
        fprintf(stderr, "Error: registro no válido!\n");
#endif
        return -1;
    }

    sprintf(empleado->apellidos, "%s %s", apellidos[random() % numApellidos],
            apellidos[random() % numApellidos]);
    sprintf(empleado->nombre, "%s", nombres[random() % numNombres]);
    sprintf(buffer, "%c%c%c%c", (char)('0' + random() % 10),
            (char)('0' + random() % 10),
            (char)('0' + random() % 10),
            (char)('0' + random() % 10));
    empleado->matricula = atoi(buffer);
    return 0;
}

int cargarRegistrosAleatorios(tipoEmpleado *empleados, int numEmpleados)
{
    int i, check;
    if (empleados == NULL)
        return -1;

    for (i = 0; i < numEmpleados; i++)
    {
        check = cargarRegistroAleatorio(empleados + i);

        if (check)
            return -2;
    }

    return 0;
}

int cargarRegistrosAleatoriosRef(tipoEmpleado **empleados, int numEmpleados)
{
    int i, check;
    if (empleados == NULL)
        return -1;

    for (i = 0; i < numEmpleados; i++)
    {
        check = cargarRegistroAleatorio(empleados[i]);

        if (check)
            return -2;
    }

    return 0;
}

void cargarUnRegistro(tipoEmpleado *empleado)
{
    printf("Introducir el apellido \n");
    gets(empleado->apellidos);
    printf("Introducir el nombre \n");
    gets(empleado->nombre);
    printf("Introducir el número de matrícula \n");
    scanf("%d%*c", &(empleado->matricula));
}

void mostrarRegistro(tipoEmpleado empleado)
{
    printf("%s, %s %d\n", empleado.apellidos,
           empleado.nombre,
           empleado.matricula);
}

void mostrarRegistros(tipoEmpleado *empleados, int numEmpleados)
{
    int i;

    for (i = 0; i < numEmpleados; i++)
        printf("%s, %s %d\n", empleados[i].apellidos,
               empleados[i].nombre, empleados[i].matricula);
}

void mostrarRegistrosRef(tipoEmpleado **refsEmpleados, int numEmpleados)
{
    int i;

    for (i = 0; i < numEmpleados; i++)
        printf("%s, %s %d\n", refsEmpleados[i]->apellidos,
               refsEmpleados[i]->nombre, refsEmpleados[i]->matricula);
}

void ordenarRegistrosApellido(tipoEmpleado *empleados, int numEmpleados)
{
    int i, j;
    tipoEmpleado temp;

    for (i = 0; i < numEmpleados - 1; i++)
    {
        for (j = numEmpleados - 1; j > i; j--)
        {
            if ((strcmp(empleados[j].apellidos, empleados[j - 1].apellidos)) < 0)
            {
                temp = empleados[j];
                empleados[j] = empleados[j - 1];
                empleados[j - 1] = temp;
            }
        }
    }
}

void ordenarRegistrosRefApellido(tipoEmpleado **refsEmpleados, int numEmpleados)
{
    int i, j;
    tipoEmpleado *temp;

    for (i = 0; i < numEmpleados - 1; i++)
    {
        for (j = numEmpleados - 1; j > i; j--)
        {
            if ((strcmp(refsEmpleados[j]->apellidos, refsEmpleados[j - 1]->apellidos)) < 0)
            {
                temp = refsEmpleados[j];
                refsEmpleados[j] = refsEmpleados[j - 1];
                refsEmpleados[j - 1] = temp;
            }
        }
    }
}
