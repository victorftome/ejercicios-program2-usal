/* ENUNCIADO
Escribir tres funciones que permitan hacer las operaciones de suma, resta y multiplicación de
números complejos. El tipo complejo deberá definirse como una estructura.
Escribir además una función para leer un complejo de teclado y otra para mostrarlos en
pantalla.
Escribir finalmente un programa para comprobar el correcto funcionamiento de las funciones
 */
#include <stdio.h>

struct complejo
{
    float real;
    float imaginaria;
};

struct complejo suma(struct complejo, struct complejo);
struct complejo resta(struct complejo, struct complejo);
struct complejo multiplicacion(struct complejo, struct complejo);

struct complejo leerComplejo();
void printComplejo(struct complejo);

int main()
{
    struct complejo n = leerComplejo();

    puts("Numero complejo leido: ");
    printComplejo(n);

    n = suma(n, (struct complejo){1, 1});

    puts("Numero complejo despues de la suma: ");
    printComplejo(n);

    n = resta(n, (struct complejo){1, 1});

    puts("Numero complejo despues de la resta: ");
    printComplejo(n);

    n = multiplicacion(n, (struct complejo){2, 2});

    puts("Numero complejo despues de la multiplicacion: ");
    printComplejo(n);

    return 0;
}

struct complejo suma(struct complejo x, struct complejo y)
{
    struct complejo temp;

    temp.real = x.real + y.real;
    temp.imaginaria = x.imaginaria + y.imaginaria;

    return temp;
}

struct complejo resta(struct complejo x, struct complejo y)
{
    struct complejo temp;

    temp.real = x.real - y.real;
    temp.imaginaria = x.imaginaria - y.imaginaria;

    return temp;
}

struct complejo multiplicacion(struct complejo x, struct complejo y)
{
    struct complejo temp;

    temp.real = x.real * y.real - x.imaginaria * y.imaginaria;
    temp.imaginaria = x.real * y.imaginaria + x.imaginaria * y.real;

    return temp;
}

struct complejo leerComplejo()
{
    struct complejo temp;

    puts("Introduzca la parte real: ");
    scanf("%f", &temp.real);

    puts("Introduzca la parte imaginaria: ");
    scanf("%f", &temp.imaginaria);

    return temp;
}

void printComplejo(struct complejo complejo)
{
    printf("%.3f %c %.3fi\n", complejo.real, (complejo.imaginaria < 0) ? ' ' : '+', complejo.imaginaria);
}