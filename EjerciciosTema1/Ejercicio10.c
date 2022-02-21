/* ENUNCIADO
Un punto en el plano se puede representar mediante una estructura con dos campos. Escribir
un programa que mediante funciones que manejen estructuras que representen los puntos del
plano realice las siguientes operaciones.
     Leer un punto de teclado
     Presentar un punto en pantalla
     Dados dos puntos, calcular la distancia entre ellos
     Dados dos puntos, determinar el punto medio de la línea que los une.
Análisis del problema

Las coordenadas de un punto en el plano de dos dimensiones son dos números reales que se
representarán en forma de estructura. Es decir, por cada punto se define una estructura.

La distancia entre dos puntos se calcula como la raíz cuadrada de la suma del cuadrado de la
diferencia de sus coordenadas, es decir sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2))

El punto medio de la línea que los une se calcula
    p3.x = (p1.x + p2.x) / 2
    p3.y = (p1.y + p2.y) / 2
*/

#include <stdio.h>
#include <math.h>

struct punto
{
    float x, y;
};

struct punto leerPunto();
void printPunto(struct punto);
float getDistance(struct punto, struct punto);
struct punto getPuntoMedio(struct punto, struct punto);

int main()
{
    struct punto punto1, punto2;

    printf("Introduzca el primero punto\n");
    punto1 = leerPunto();

    printf("\nIntroduzca el segundo punto\n");
    punto2 = leerPunto();

    printf("\nLos puntos introducidos son\n");
    printPunto(punto1);
    printPunto(punto2);

    printf("La distancia entre los puntos es de %.2f\n", getDistance(punto1, punto2));
    printf("El punto medio entre los puntos es el siguiente.\n");

    printPunto(getPuntoMedio(punto1, punto2));

    printf("\n");

    return 0;
}

struct punto leerPunto(void)
{
    struct punto temp;

    printf("Introduzca la coordenada x del punto: ");
    scanf("%f", &temp.x);

    printf("Introduzca la coordenada y del punto: ");
    scanf("%f", &temp.y);

    return temp;
}

void printPunto(struct punto p)
{
    printf("Punto x: %.2f\n", p.x);
    printf("Punto y: %.2f\n", p.y);
}

float getDistance(struct punto p1, struct punto p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

struct punto getPuntoMedio(struct punto p1, struct punto p2)
{
    struct punto temp;

    temp.x = (p1.x + p2.x) / 2;
    temp.y = (p1.y + p2.y) / 2;

    return temp;
}