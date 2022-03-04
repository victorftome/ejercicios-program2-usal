#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>

#define NAME_SIZE 15

// En Windows la funcion clock devuelve microsegundos, en linux y macOS nanosegundos

typedef struct empleados
{
    char apellidos[30];
    char nombre[NAME_SIZE];
    int matricula;
    // char bufferRelleno[50000];
} tipoEmpleado;

void cargarRegistrosAleatorios(tipoEmpleado *empleados, int numEmpleados);
void cargarUnRegistro(tipoEmpleado *empleado);

void mostrarRegistro(tipoEmpleado empleado);
void mostrarRegistrosRef(tipoEmpleado **refsEmpleados, int numEmpleados);
void mostrarRegistros(tipoEmpleado *empleados, int numEmpleados);

void ordenarRegistrosRefApellido(tipoEmpleado **refsEmpleados, int numEmpleados);
void ordenarRegistrosApellido(tipoEmpleado *empleados, int numEmpleados);
void ordenarRegistrosRefNombre(tipoEmpleado **refsEmpleados, int numEmpleados);
void ordenarRegistrosNombre(tipoEmpleado *empleados, int numEmpleados);
void ordenarRegistrosRefMatricula(tipoEmpleado **refsEmpleados, int numEmpleados);
void ordenarRegistrosMatricula(tipoEmpleado *empleados, int numEmpleados);

int buscarRegistroNombre(char *nombre, tipoEmpleado *empleados, int numEmpleados);
int buscarRegistroRefNombre(char *nombre, tipoEmpleado **refsEmpleados, int numEmpleados);

void modificarRegistro(tipoEmpleado *empleado);

#define NUM_EMPLEADOS 10

int main(void)
{
    tipoEmpleado regEmpleados[NUM_EMPLEADOS], unEmpleado;
    tipoEmpleado *regEmpleadosRef[NUM_EMPLEADOS];
    int i, pos;
    char nombreABuscar[NAME_SIZE];
    clock_t tiempoInicial, tiempoFinal;

    cargarRegistrosAleatorios(regEmpleados, NUM_EMPLEADOS);

    mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

    printf("\n\n Jugando con un único registro: \n");
    unEmpleado = regEmpleados[2];
    mostrarRegistro(unEmpleado);
    mostrarRegistro(regEmpleados[2]);
    mostrarRegistros(&unEmpleado, 1);

    // cargarUnRegistro(&unEmpleado);
    // printf("\n\nEl registrocargado es: \n");
    // mostrarRegistro(unEmpleado);
    // printf("\ny el registro regEmpleados[2] es: \n");
    // mostrarRegistro(regEmpleados[2]);

    for (i = 0; i < NUM_EMPLEADOS; i++)
        regEmpleadosRef[i] = &regEmpleados[i];

    printf("\n\nValores no clasificados (a través matriz punteros): \n");
    mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);

    tiempoInicial = tiempoFinal = clock();
    ordenarRegistrosRefApellido(regEmpleadosRef, NUM_EMPLEADOS);
    tiempoFinal = clock();

    printf("\n\nValores clasificados (a través matriz punteros): \n");
    printf("Tiempo tardado: %f\n", (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC);
    mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);

    printf("\n\nAhora valores no clasificados matriz de registros original: \n");
    mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

    tiempoInicial = tiempoFinal = clock();
    ordenarRegistrosApellido(regEmpleados, NUM_EMPLEADOS);
    tiempoFinal = clock();

    printf("\n\nAhora valores clasificados matriz de registros original: \n");
    printf("Tiempo tardado: %f\n", (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC);
    mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

    ordenarRegistrosNombre(regEmpleados, NUM_EMPLEADOS);
    printf("\n\nMatriz ordenada por nombres: \n");
    mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

    ordenarRegistrosRefNombre(regEmpleadosRef, NUM_EMPLEADOS);
    printf("\n\nMatriz de punteros ordenada por nombres: \n");
    mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);

    ordenarRegistrosMatricula(regEmpleados, NUM_EMPLEADOS);
    printf("\n\nMatriz ordenada por matriculas: \n");
    mostrarRegistros(regEmpleados, NUM_EMPLEADOS);

    ordenarRegistrosRefMatricula(regEmpleadosRef, NUM_EMPLEADOS);
    printf("\n\nMatriz de punteros ordenada por matriculas: \n");
    mostrarRegistrosRef(regEmpleadosRef, NUM_EMPLEADOS);

    printf("Introduzca el nombre del empleado a modificar: ");
    scanf(" %[^\n]", nombreABuscar);

    if ((pos = buscarRegistroNombre(nombreABuscar, regEmpleados, NUM_EMPLEADOS)) < 0)
        printf("\nNo se encontro a ningun empleado con ese nombre\n");
    else
    {
        printf("\n\nEl empleado encontrado es: \n");
        mostrarRegistro(regEmpleados[pos]);

        modificarRegistro(&regEmpleados[pos]);

        printf("\nEmpleado modificado: \n");
        mostrarRegistro(regEmpleados[pos]);
    }

    return 0;
}

void cargarRegistrosAleatorios(tipoEmpleado *empleados, int numEmpleados)
{
    int i;
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

    srandom(time(NULL));
    for (i = 0; i < numEmpleados; i++)
    {
        sprintf(empleados[i].apellidos, "%s %s", apellidos[random() % numApellidos],
                apellidos[random() % numApellidos]);
        sprintf(empleados[i].nombre, "%s", nombres[random() % numNombres]);
        sprintf(buffer, "%c%c%c%c", (char)('0' + random() % 10),
                (char)('0' + random() % 10),
                (char)('0' + random() % 10),
                (char)('0' + random() % 10));
        empleados[i].matricula = atoi(buffer);
    }
}

void cargarUnRegistro(tipoEmpleado *empleado)
{
    printf("Introduzca el apellidos del empleado: ");
    scanf(" %[^\n]", empleado->apellidos); // Leemos hasta el caracter de salto de linea

    printf("Introduzca el nombre del empleado: ");
    scanf(" %[^\n]", empleado->nombre);

    printf("Introduzca la matricula del empleado: ");
    scanf(" %d", &empleado->matricula);
    /*
     * Esta función recibe un ÚNICO REGISTRO de tipo tipoEmpleado
     * y el alumno debe escribir el código necesario para que
     * se pidan los datos necesarios por pantalla y cargar
     * los campos del registro con los datos introducidos
     * por teclado por el usuario
     */
}

void mostrarRegistro(tipoEmpleado empleado)
{
    printf("%-31s%-16s%-10d\n", empleado.apellidos, empleado.nombre, empleado.matricula);
    /*
     * Esta función muestra por pantalla y en una única línea
     * los datos almacenados en los campos del registro
     * recibido
     */
}

void mostrarRegistros(tipoEmpleado *empleados, int numEmpleados)
{
    int i;

    printf("%-31s%-16s%-10s\n", "Apellidos", "Nombre", "Matricula");
    for (i = 0; i < numEmpleados; i++)
        mostrarRegistro(empleados[i]);
    /*
     * Esta función recibe un vector de registros de tipoEmpleado
     * de tamaño numEmpleados, y muestra por pantalla el contenido
     * de los campos de todos los registros de dicho vector, un
     * registro por línea
     */
}

void mostrarRegistrosRef(tipoEmpleado **refsEmpleados, int numEmpleados)
{
    int i;

    printf("%-31s%-16s%-10s\n", "Apellidos", "Nombre", "Matricula");
    for (i = 0; i < numEmpleados; i++)
        mostrarRegistro(*refsEmpleados[i]);
    /*
     * Esta función recibe un vector de  punteros a registros de
     * tipoEmpleado, de tamaño numEmpleados (el vector), y muestra por pantalla
     * el contenido de los campos de todos los registros referenciados
     * por los punteros del vector, mostrando un registro por línea
     */
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
        for (j = numEmpleados - 1; j > i; j--)
        {
            if ((strcmp(refsEmpleados[j]->apellidos, refsEmpleados[j - 1]->apellidos)) < 0)
            {
                temp = refsEmpleados[j];
                refsEmpleados[j] = refsEmpleados[j - 1];
                refsEmpleados[j - 1] = temp;
            }
        }
    /*
     * Esta función es análoga a la función ordenarRegistrosApellido
     * pero con la diferencia que en vez de recibir un vector de
     * registros, recibe un vector de punteros a registros. La función
     * utiliza el mismo algoritmo de ordenación (burbuja) para ordenar
     * pero en vez de ordenar los registros, se ordenará el vector
     * de punteros, utilzando la información del campo apellidos
     * del registro apuntado.
     */
}

void ordenarRegistrosRefNombre(tipoEmpleado **refsEmpleados, int numEmpleados)
{
    int i, j;
    tipoEmpleado *temp;

    for (i = 0; i < numEmpleados - 1; i++)
        for (j = numEmpleados - 1; j > i; j--)
            if (strcmp(refsEmpleados[j]->nombre, refsEmpleados[j - 1]->nombre) < 0)
            {
                temp = refsEmpleados[j];
                refsEmpleados[j] = refsEmpleados[j - 1];
                refsEmpleados[j - 1] = temp;
            }
}

void ordenarRegistrosNombre(tipoEmpleado *empleados, int numEmpleados)
{
    int i, j;
    tipoEmpleado temp;

    for (i = 0; i < numEmpleados - 1; i++)
    {
        for (j = numEmpleados - 1; j > i; j--)
        {
            if ((strcmp(empleados[j].nombre, empleados[j - 1].nombre)) < 0)
            {
                temp = empleados[j];
                empleados[j] = empleados[j - 1];
                empleados[j - 1] = temp;
            }
        }
    }
}

void ordenarRegistrosRefMatricula(tipoEmpleado **refsEmpleados, int numEmpleados)
{
    int i, j;
    tipoEmpleado *temp;

    for (i = 0; i < numEmpleados - 1; i++)
    {
        for (j = numEmpleados - 1; j > i; j--)
        {
            if (refsEmpleados[j]->matricula < refsEmpleados[j - 1]->matricula)
            {
                temp = refsEmpleados[j];
                refsEmpleados[j] = refsEmpleados[j - 1];
                refsEmpleados[j - 1] = temp;
            }
        }
    }
}

void ordenarRegistrosMatricula(tipoEmpleado *empleados, int numEmpleados)
{
    int i, j;
    tipoEmpleado temp;

    for (i = 0; i < numEmpleados - 1; i++)
    {
        for (j = numEmpleados - 1; j > i; j--)
        {
            if (empleados[j].matricula < empleados[j - 1].matricula)
            {
                temp = empleados[j];
                empleados[j] = empleados[j - 1];
                empleados[j - 1] = temp;
            }
        }
    }
}

int buscarRegistroNombre(char *nombre, tipoEmpleado *empleados, int numEmpleados)
{
    int i;

    for (i = 0; i < numEmpleados; i++)
        if (!strcmp(nombre, empleados[i].nombre))
            return i;

    return -1;
}

int buscarRegistroRefNombre(char *nombre, tipoEmpleado **refsEmpleados, int numEmpleados)
{
    int i;

    for (i = 0; i < numEmpleados; i++)
        if (!strcmp(nombre, refsEmpleados[i]->nombre))
            return i;

    return -1;
}

void modificarRegistro(tipoEmpleado *empleado)
{
    printf("=== Introduzca los nuevos datos del empleado ===\n");
    cargarUnRegistro(empleado);
}