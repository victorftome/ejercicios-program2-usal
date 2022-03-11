#include "CBFAUX.h"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void presentacion(void);
void modulo_principal(void);

int main(void)
{
    /* ---------------------------------------------------------- */
    char respuesta;

    system("cls");
    presentacion();
    do
    {
        printf("\n");
        modulo_principal();
        printf("\n");
        do
        {
            printf("�Otra ejecuci�n (S/N)?: ");
            fflush(stdin); /* Limpia el buffer de teclado */
            respuesta = toupper(getchar());
        } while (respuesta != 'S' && respuesta != 'N');

    } while (respuesta != 'N');

    return 0;

} /* Fin del main */

void presentacion(void)
{
    /* ---------------------------------------------------------- */
    puts("N�mero combinatorio");
    puts("===================");
    puts("");
    puts("El programa presenta el n�mero combinatorio m sobre n");
    puts("");
}

/* ---------------------------------------------------------- */
void modulo_principal(void)
{
    /* ---------------------------------------------------------- */
    unsigned long m, n;
    unsigned long combinatoriomn;

    printf("Introduzca m (entero positivo): ");
    scanf("%lu", &m);

    printf("Introduzca n (entero positivo): ");
    scanf("%lu", &n);

    combinatoriomn = combinatorio(m, n);

    printf("\nC(%lu,%lu)= %lu\n", m, n, combinatoriomn);
}
