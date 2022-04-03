#include <stdio.h>
#include "estudiante.h"

void 
moduloPrincipal (void) 
{
    struct tipoEstudiante estudiantes[NUM_ESTUDIANTES];
	float calificacionesFinales[NUM_ESTUDIANTES], promediosPruebas[NUM_EVA_CONT];
	int num, numAprobados, res, i;

    do {
        printf("\nIntroduzca un n�mero entero positivo: (<%d)",NUM_ESTUDIANTES);
        scanf("%d%*c", &num);
    } while (num <= 0  || num > NUM_ESTUDIANTES);

	cargarRegistrosAleatorios(estudiantes,num);
    printf("\nLos estudiantes son: %d\n", num);
	mostrarRegistros(estudiantes, num);
	
	calcularCalificaciones(estudiantes, num, calificacionesFinales, promediosPruebas, &numAprobados);
	printf("\nCalificaciones por estudiante: \n");
	for(i = 0; i < num; i++){
		mostrarRegistro(estudiantes[i]);
		printf("Calificación final alumno %3d: %6.2f\n",i, calificacionesFinales[i]);
	}
	
	for(i = 0; i < NUM_EVA_CONT; i++){
		printf("Mes: %d promedio: %6.2f\n", i, promediosPruebas[i]);
	}

	res = num - numAprobados;

	printf("\nEl resultado es: %d y %d aprobados\n",res, numAprobados);
		
    printf ("\n\n");

}


void 
presentacion (void) 
{
/* ---------------------------------------------------------- */
     puts("Trabajando con registros\n");
     puts("=========================");
     puts("");
     puts("El programa pedirá creará un vector de registros y cargará con datos");
     puts("para calcular promedios                                     ");
     puts("");
}
