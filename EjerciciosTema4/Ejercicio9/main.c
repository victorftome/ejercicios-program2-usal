#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct persona
{
    char nombre[21];
    int edad;
    float peso;
    float estatura;
    char ciudad[13];
};

int main()
{
    struct persona personas[50];

    int i = 0;
    int j, k;

    FILE *fichero = fopen("./lista100.txt", "r");

    if (fichero == NULL)
        return -1;

    while (fscanf(fichero, "%20[^\t]%4d%8f%6f%12[^\t]%*c", personas[i].nombre, &personas[i].edad, &personas[i].peso, &personas[i].estatura, personas[i].ciudad) != EOF)
    {
        while (personas[i].nombre[0] == '\x20')
        {
            k = 0;
            while (personas[i].nombre[k] != '\0')
            {
                personas[i].nombre[k] = personas[i].nombre[k + 1];
                k++;
            }
        }

        while (personas[i].ciudad[0] == '\x20')
        {
            k = 0;
            while (personas[i].ciudad[k] != '\0')
            {
                personas[i].ciudad[k] = personas[i].ciudad[k + 1];
                k++;
            }
        }

        i++;
    }

    fclose(fichero);

    fichero = fopen("./listaenc.txt", "w");

    if (fichero == NULL)
        return -1;

    for (j = 0; j < i; j++)
        fprintf(fichero, "%s*%d*%.3f*%.2f*%s\n", personas[j].nombre, personas[j].edad, personas[j].peso, personas[j].estatura, personas[j].ciudad);

    fclose(fichero);

    return 0;
}