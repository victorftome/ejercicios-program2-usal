#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pantalla.h"

int
main (void)
{
	char respuesta;
 	system ("clear");
	presentacion();
	do { 
		printf("\n");
		moduloPrincipal();
		printf("\n");
		do { 
			printf("¿Otra ejecución (S/N)?: ");
			scanf("%c%*c", &respuesta);
			respuesta = toupper(respuesta);
		} while (respuesta != 'S' && respuesta != 'N');
	} while (respuesta != 'N');
    
	printf("\n");
	return 0;
}





