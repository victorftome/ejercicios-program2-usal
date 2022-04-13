//
//  main.c
//  dinamicaMatrices
//
//  Created by Iván Álvarez Navia on 22/03/13.
//  Copyright (c) 2013 Iván Álvarez Navia. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "matrizBidimensional.h"

int main(int argc, const char *argv[])
{
	char menu[] = "Suma de matrices:\nA) Leer datos \nB) Sumar matrices \nC) Ver resultados \nD) Liberar matrices \nE) Multiplicar matrices \nQ) Salir";
	char opcion;
	int numFil, numCol, errNum, i;
	int *filaMaxima = NULL;

	matIntRef A, B, C;

	A = B = C = NULL;

	do
	{
		printf("%s: ", menu);
		scanf("%c%*c", &opcion);
		opcion = toupper(opcion);
		switch (opcion)
		{
		case 'A':
			if (A != NULL || B != NULL)
			{
				printf("Ya existen matrices ... opciones C o D\n\n");
				break;
			}
			printf("\n\nDimensiones de las matrices:\n\n");
			printf("Número de filas: ");
			scanf("%d%*c", &numFil);
			printf("Número de columnas: ");
			scanf("%d%*c", &numCol);

			printf("Primera matriz: \n");
			if (NULL != (A = crearMatInt(numFil, numCol, &errNum)))
				leerMatInt(A, "Matriz A");
			else
				printf("Fallo creación matriz: %d\n", errNum);

			printf("Segunda matriz: \n");
			if (NULL != (B = crearMatInt(numFil, numCol, &errNum)))
				leerMatInt(B, "Matriz B");
			else
				printf("Fallo creación matriz: %d\n", errNum);
			break;
		case 'B':
			printf("\n\nSuma...");
			if (NULL != C)
			{
				liberarMatInt(C);
				free(C);
			}
			if (NULL == (C = sumarMatInt(A, B, &errNum)))
				printf("... no realizada %d\n", errNum);
			else
				printf("efectuada.\n\n");
			break;
		case 'C':
			printf("\n\nVisualización de resultados\n\n");
			printf("\n\nPrimera matriz\n\n");
			mostrarMatInt(A, " %d ");
			printf("\n\nSegunda matriz\n\n");
			mostrarMatInt(B, " %d ");
			printf("\n\nMatriz resultado\n\n");
			mostrarMatInt(C, " %d ");
			printf("\n\nFila con el valor maximo de la matriz resultado\n\n");
			filaMaxima = obtenerColumnaMaxMatInt(C, &errNum);

			if (filaMaxima == NULL)
				printf("Error al obtener la fila maxima (Err: %d)\n", errNum);

			for (i = 0; i < C->numFil; i++)
				printf("| %d ", filaMaxima[i]);

			free(filaMaxima);
			filaMaxima = NULL;

			printf(" |\n\n");

			break;
		case 'D':
			printf("\n\nLiberación de matrices...");
			liberarMatInt(A);
			free(A);
			A = NULL;
			liberarMatInt(B);
			free(B);
			B = NULL;
			liberarMatInt(C);
			free(C);
			C = NULL;
			printf("efectuada.\n\n");
			break;

		case 'E':
			if (NULL != C)
			{
				liberarMatInt(C);
				free(C);
			}

			if (NULL == (C = multiplicarMatInt(A, B, &errNum)))
				printf("...No se pude realizar la multiplicacion correctamente (Err: %d)\n", errNum);
			else
				printf("Multiplicacion realizada correctamente.\n\n");
			break;
		case 'Q':
			printf("\n\nSaliendo.\n\n");
			break;
		default:
			printf("\n\nOpción incorrecta!\a\n\n");
			break;
		}
	} while ('Q' != opcion);
	printf("\n\nTerminación normal del programa.\n\n");
	return 0;
}
