#ifndef __EMPLEADO_H
#define __EMPLEADO_H

typedef struct empleados
{
    char apellidos[30];
    char nombre[15];
    int matricula;
    // char bufferRelleno[5];
} tipoEmpleado;

tipoEmpleado *crearVectorRegistros(int numEmpleados, int *errNum);
int cargarRegistrosAleatorios(tipoEmpleado *empleados, int numEmpleados);

tipoEmpleado **crearRegistrosRef(int numEmpleados, int *errNum);
int liberarMemRegistrosRef(tipoEmpleado **empleadosRef, size_t numEmpleados);
int cargarRegistrosAleatoriosRef(tipoEmpleado **empleados, int numEmpleados);

void cargarUnRegistro(tipoEmpleado *empleado);

void mostrarRegistro(tipoEmpleado empleado);
void mostrarRegistrosRef(tipoEmpleado **refsEmpleados, int numEmpleados);
void mostrarRegistros(tipoEmpleado *empleados, int numEmpleados);

void ordenarRegistrosRefApellido(tipoEmpleado **refsEmpleados, int numEmpleados);
void ordenarRegistrosApellido(tipoEmpleado *empleados, int numEmpleados);

#endif
