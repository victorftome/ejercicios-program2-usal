#include <stdio.h>

#define MAX_SIZE 50

void copiaNoIncluidos(int *v1, int dimV1, int *v2, int dimV2, int *vsalida, int *dimSalida);

int main()
{
	int i;
	int v1[] = {0, 9, -7, 0, 5, 9};
	int v2[] = {3, 0, 7, 4, 0, 5, 6, -3};

	int vsalida[MAX_SIZE];
	int dimSalida;

	copiaNoIncluidos(v1, 6, v2, 8, vsalida, &dimSalida);

	printf("La dimension del vector ssalida es: %d\n Y los valores son: \n", dimSalida);
	for (i = 0; i < dimSalida; i++)
		printf("%d | ", vsalida[i]);
}

void copiaNoIncluidos(int *v1, int dimV1, int *v2, int dimV2, int *vsalida, int *dimSalida)
{
	int i, j, repetido;
	*dimSalida = 0;

	for (i = 0; i < dimV1; i++)
	{
		repetido = 0;
		for (j = 0; j < dimV2; j++)
		{
			if (v1[i] == v2[j])
			{
				repetido = 1;
				break;
			}
		}

		if (!repetido)
			vsalida[(*dimSalida)++] = v1[i];
	}
}
