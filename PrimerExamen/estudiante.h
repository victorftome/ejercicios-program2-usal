#ifndef __ESTUDIANTE_H
#define __ESTUDIANTE_H

#define NUM_EVA_CONT		  5
#define NUM_ESTUDIANTES			300


//Definimos el struct
struct tipoEstudiante {
	char nombre[80];
	char dni[10];
	float pruebasContinua[NUM_EVA_CONT];
	float calificacionExamenFinal;
};



int calcularCalificaciones(struct tipoEstudiante *estudiantes, int numEstudiantes, float *calificacionesFinales, float *promediosPruebas, int *numeroAprobados);
void cargarRegistrosAleatorios(struct tipoEstudiante *estudiantes, int numEstudiantes);
void mostrarRegistros(struct tipoEstudiante *estudiantes, int numEstudiantes);
void mostrarRegistro(struct tipoEstudiante estudiante);

#endif

