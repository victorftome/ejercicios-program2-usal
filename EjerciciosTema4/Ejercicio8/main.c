#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct persona
{
    char nombre[50];
    char ciudad[30];
    int edad;
    float peso;
};

int main()
{
    struct persona personas[MAX];
    int i = 0;
    int j;

    char x_edad[4];
    char x_peso[6];

    FILE *fichero = fopen("./fperde01.txt", "r");

    while (fscanf(fichero, "%[^*]%*c%[^*]%*c%[^*]%*c%[^\n]%*c", personas[i].nombre, personas[i].ciudad, x_edad, x_peso) != EOF)
    {
        personas[i].edad = atoi(x_edad);
        personas[i].peso = atof(x_peso);

        i++;
    }

    fclose(fichero);

    fichero = fopen("./fperta02.txt", "r");

    while (fscanf(fichero, "%[^\t]%*c%[^\t]%*c%[^\t]%*c%[^\n]%*c", personas[i].nombre, personas[i].ciudad, x_edad, x_peso) != EOF)
    {
        personas[i].edad = atoi(x_edad);
        personas[i].peso = atof(x_peso);

        i++;
    }

    fclose(fichero);

    fichero = fopen("./fperen03.txt", "w");

    for (j = 0; j < i; j++)
        fprintf(fichero, "%-50s%-30s%4d%10.2f\n", personas[j].nombre, personas[j].ciudad, personas[j].edad, personas[j].peso);

    fclose(fichero);

    return 0;
}