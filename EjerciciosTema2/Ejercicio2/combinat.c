/* Fuente: COMBINAT.C
   Programa: COMBINATORIO
   Descripci�n: A trav�s de una funci�n, calcula el n�mero combinatorio
                                 m!
                   C(m,n) = ------------
                             n! * (m-n)!
   Donde C(m,n) = 0 si m<n;
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* ---------------------------------------------------------- */
/* Prototipos                                                 */
/* ---------------------------------------------------------- */
void modulo_principal(void);
unsigned long combinatorio(unsigned long, unsigned long);
unsigned long factorial(unsigned long);
void presentacion(void);

/* ---------------------------------------------------------- */
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

/* ---------------------------------------------------------- */
unsigned long factorial(unsigned long num)
{
   /* ---------------------------------------------------------- */
   unsigned long fact;
   unsigned long j;

   fact = 1;
   for (j = 1; j <= num; j++)
      fact *= j;
   return (fact);
}

/* ---------------------------------------------------------- */
unsigned long combinatorio(unsigned long m, unsigned long n)
{
   /* ---------------------------------------------------------- */

   if (n > m)
      return (0);
   else
      return (factorial(m) / (factorial(n) * factorial(m - n)));
}

/* ---------------------------------------------------------- */
void presentacion(void)
{
   /* ---------------------------------------------------------- */
   puts("N�mero combinatorio");
   puts("===================");
   puts("");
   puts("El programa presenta el n�mero combinatorio m sobre n");
   puts("");
}
