/* ENUNCIADO
Declara una variable enum para representar las estaciones del año. Deberán representarse
internamente por las constantes 1, 2, 3 y 4.
*/

#include <stdio.h>

// No hace falta indicar los indices a partir de primavera, ya que automaticamente
// el compilador de C empezará a asignar los indices a partir del numero aignado,
// 1 en este caso, dando la sucesion de indices 2, 3 y 4.
enum estaciones
{
    PRIMAVERA = 1,
    VERANO,
    OTONHO,
    INVIERNO
};

int main()
{
    int i;

    printf("INDICES:\n");
    for (i = PRIMAVERA; i <= INVIERNO; i++)
        printf("%d | ", i);
}