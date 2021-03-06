/* ENUNCIADO
Se desea calcular la edad y estatura máxima, mínima y media de la alineación inicial de un
equipo de fútbol.
Para ello se realizará un programa que pida por teclado el nombre, la edad y la estatura de los
11 jugadores. Una vez introducidos los datos, el programa presentará en pantalla:
    − La estatura y edad media del equipo.
    − La edad mínima del equipo y el número de jugadores con su nombre y estatura que la
    poseen.
    − La estatura máxima del equipo y el número de jugadores con su nombre y edad que la
    poseen.

Análisis
Se definirá una estructura llamada jugador, que contendrá los datos que recoge el programa
de cada jugador del equipo: su nombre, su edad y su estatura. Posteriormente se definirá un
vector, llamado equipo, de elementos de esta estructura. La dimensión de este vector se
definirá en función de una constante DIM, cuyo valor se fija en 11 (según el enunciado del
problema).
*/
#include <stdio.h>

#define DIM 11

struct jugador
{
    char nombre[80];
    int edad;
    float estatura;
};

void leerJugadores(struct jugador *equipo, int dimension);
void getEstaturaEdadMedia(struct jugador *equipo, int dimension, float *edadMedia, float *estaturaMedia);
int getEdadMinima(struct jugador *equipo, int dimension);
float getEstaturaMaxima(struct jugador *equipo, int dimension);

int main()
{
    struct jugador equipo[DIM];

    float edadMedia, estaturaMedia, estaturaMaxima;
    int edadMinima, i;

    leerJugadores(equipo, DIM);
    getEstaturaEdadMedia(equipo, DIM, &edadMedia, &estaturaMedia);
    edadMinima = getEdadMinima(equipo, DIM);
    estaturaMaxima = getEstaturaMaxima(equipo, DIM);

    printf("La edad media es %.2f.\nLa estatura media es %.2f\n", edadMedia, estaturaMedia);

    printf("La edad minima es %d, y los jugadores con esta edad son: \n", edadMinima);

    for (i = 0; i < DIM; i++)
        if (equipo[i].edad == edadMinima)
            printf("\tNombre: %s\tEstatura: %.2f\n", equipo[i].nombre, equipo[i].estatura);

    printf("La estatura maxima es %.2f, y los jugadores con esta estatura son: \n", estaturaMaxima);

    for (i = 0; i < DIM; i++)
        if (equipo[i].estatura == estaturaMaxima)
            printf("\tNombre: %s\tEdad: %d\n", equipo[i].nombre, equipo[i].edad);

    return 0;
}

void leerJugadores(struct jugador *equipo, int dimension)
{
    int i;
    for (i = 0; i < dimension; i++)
    {
        printf("Introduzca los datos del %d jugador\n", i + 1);
        printf("======================================\n");

        printf("Nombre: ");
        scanf("%s", &equipo[i].nombre);

        printf("Edad: ");
        scanf("%d", &equipo[i].edad);

        printf("Estatura: ");
        scanf("%f", &equipo[i].estatura);
    }
}

void getEstaturaEdadMedia(struct jugador *equipo, int dimension, float *edadMedia, float *estaturaMedia)
{
    int i;

    *edadMedia = 0;
    *estaturaMedia = 0;

    for (i = 0; i < dimension; i++)
    {
        *edadMedia += equipo[i].edad;
        *estaturaMedia += equipo[i].estatura;
    }

    *edadMedia /= dimension;
    *estaturaMedia /= dimension;
}

int getEdadMinima(struct jugador *equipo, int dimension)
{
    int i, edadMinima = equipo[0].edad;

    for (i = 1; i < dimension; i++)
        if (edadMinima > equipo[i].edad)
            edadMinima = equipo[i].edad;

    return edadMinima;
}

float getEstaturaMaxima(struct jugador *equipo, int dimension)
{
    int i;
    float estaturaMaxima = equipo[0].estatura;

    for (i = 1; i < dimension; i++)
        if (estaturaMaxima < equipo[i].estatura)
            estaturaMaxima = equipo[i].estatura;

    return estaturaMaxima;
}