//
//  matrizBidimensional.h
//  dinamicaMatrices
//
//  Created by Iván Álvarez Navia on 22/03/13.
//  Copyright (c) 2013 Iván Álvarez Navia. All rights reserved.
//

#ifndef MATRIZ_BIDIMENSIONAL_H
#define MATRIZ_BIDIMENSIONAL_H

#define COLS 25

typedef float *floatRef;
typedef int *intRef;
typedef char *charRef;

typedef struct matInt
{
	int **m;
	int numFil, numCol;
} matInt;

typedef struct matFloat
{
	float **m;
	int numFil, numCol;
} matFloat;

typedef matInt *matIntRef;
typedef matFloat *matFloatRef;

matFloatRef crearMatFloat(int numFil, int numCol, intRef errNum);
matIntRef crearMatInt(int numFil, int numCol, intRef errNum);

int liberarMatInt(matIntRef mat);
int liberarMatFloat(matFloatRef mat);

int leerMatFloat(matFloatRef m, charRef c);
int leerMatInt(matIntRef m, charRef c);

int mostrarMatFloat(matFloatRef m, charRef c);
int mostrarMatInt(matIntRef m, charRef c);

matFloatRef sumarMatFloat(matFloatRef a, matFloatRef b, intRef errNum);
matIntRef sumarMatInt(matIntRef a, matIntRef b, intRef errNum);

matIntRef multiplicarMatInt(matIntRef a, matIntRef b, intRef errNum);
int *obtenerColumnaMaxMatInt(matIntRef mat, intRef errNum);

#endif
