/* ENUNCIADO
Escribir una función que devuelva en un tipo enum estaciones, declarado anteriormente, la
estación del año que se ha introducido por teclado.
*/

// SOLUCIÓN
#include <stdio.h>

enum estaciones
{
    PRIMAVERA = 1,
    VERANO,
    OTONHO,
    INVIERNO
};

enum estaciones getEstacion(int estacion);

int main()
{
    int estacion;

    puts("1. Primavera");
    puts("2. Verano");
    puts("3. Oto\244o");
    puts("4. Invierno");
    puts("Introduzca la estacion: ");

    do
    {
        scanf("%d", &estacion);
    } while (estacion > 4 || estacion < 1);

    printf("Estacion en enum %d", getEstacion(estacion));

    return 0;
}

enum estaciones getEstacion(int estacion)
{
    return (enum estaciones)estacion;
}