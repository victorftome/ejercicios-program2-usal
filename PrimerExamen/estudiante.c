#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "estudiante.h"




int calcularCalificaciones(struct tipoEstudiante *estudiantes, int numEstudiantes, 
                         float *calificacionesFinales, float *promediosPruebas, 
                         int *numeroAprobados)
{
	if(estudiantes == NULL) return -1;
	if(numEstudiantes <= 0) return -2;
	if(calificacionesFinales == NULL || promediosPruebas == NULL || numeroAprobados == NULL) return -3;

	int i, j;
	float mediaAux;
	*numeroAprobados = 0;

	for(i = 0; i < numEstudiantes; i++) {
		mediaAux = 0;

		for(j = 0; j < NUM_EVA_CONT; j++)
			mediaAux += estudiantes[i].pruebasContinua[j];

		mediaAux = (mediaAux / NUM_EVA_CONT) * 0.5 + estudiantes[i].calificacionExamenFinal * 0.5;

		calificacionesFinales[i] = mediaAux;

		if(mediaAux >= 5.0) (*numeroAprobados)++;
	}

	for(i = 0; i < NUM_EVA_CONT; i++) {
		mediaAux = 0;

		for(j = 0; j < numEstudiantes; j++)
			mediaAux += estudiantes[j].pruebasContinua[i];

		promediosPruebas[i] = mediaAux / numEstudiantes;
	}
}


void
cargarRegistrosAleatorios(struct tipoEstudiante *estudiantes, int numEstudiantes)
{
    int i,j;
	static char letras[] = {'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E'};
    static char apellidos [][15] = {"ALONSO","ALVAREZ","ARBESU",
        "DOMINGUEZ","FERNANDEZ","FLORIANO",
        "GONZALEZ","GOMEZ","GUTIERREZ",
        "MARTIN", "MORO", "PEREZ","TURRION",
        "ZAMBRANO"};
    static char nombres [][15] = {"ALVARO","ARSENIO","DOMINGO",
        "FELIPE","FATIMA","FABIAN",
        "GONZALO","PEDRO","PATRICIA",
        "TOMAS", "ZOILO"};
    int numApellidos = sizeof(apellidos)/15;
    int numNombres = sizeof(nombres)/15;
   	
    
    srandom(time(NULL));
    for (i = 0; i < numEstudiantes; i++) {
        sprintf(estudiantes[i].nombre,"%s %s",nombres[random() % numNombres],
                apellidos[random() % numApellidos]);
		for (j = 0; j < 8; j++) {
			sprintf(&(estudiantes[i].dni[j]),"%c",(char)('0'+random()%10));
		}
		int temp = atoi(estudiantes[i].dni);
		sprintf(&(estudiantes[i].dni[8]),"%c",letras[temp%23]);						
        for (j = 0; j < NUM_EVA_CONT; j++) {
			estudiantes[i].pruebasContinua[j] = random()%10 + 1;
		}
		estudiantes[i].calificacionExamenFinal = random()%10 + 1;
    }
}

void
mostrarRegistros(struct tipoEstudiante *estudiantes, int numEstudiantes)
{
    int             i;
    
    for (i = 0; i < numEstudiantes; i++){
	    mostrarRegistro(estudiantes[i]);
    }
	    
}

void
mostrarRegistro(struct tipoEstudiante estudiante)
{
	int i;
	printf("\nReg: %10s -> %-30s\n",estudiante.dni,estudiante.nombre);
	printf("Pruebas: ");
	for (i = 0; i < NUM_EVA_CONT; i++) {
		printf("\t%5.2f", estudiante.pruebasContinua[i]);
	}
	printf("\nExamen final: \t%5.2f\n", estudiante.calificacionExamenFinal);
}

