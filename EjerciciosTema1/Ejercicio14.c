#include <stdio.h>
#include <string.h>

struct mes
{
    char nombreMes[30];
    char abreviatura[3];
    unsigned int dias;
    unsigned int orden;
};

void inicializar(struct mes *);
int diasPasados(struct mes *, char, char);

int main()
{
    int dia, mes;
    struct mes meses[12];

    inicializar(meses);

    do
    {
        printf("Introduzca el numero del mes: ");
        scanf(" %d", &mes);

        printf("Introduzca su dia: ");
        scanf(" %d", &dia);
    } while (mes < 1 || dia < 1);

    printf("Los dias que han pasado desde el mes numero %d y el dia %d son: %d\n", mes, dia, diasPasados(meses, mes, dia));

    return 0;
}

void inicializar(struct mes *meses)
{
    strcpy(meses[0].nombreMes, "Enero");
    meses[0].dias = 31;
    strcpy(meses[0].abreviatura, "JAN");
    meses[0].orden = 1;

    strcpy(meses[1].nombreMes, "Febrero");
    meses[1].dias = 28;
    strcpy(meses[1].abreviatura, "FEB");
    meses[1].orden = 2;

    strcpy(meses[2].nombreMes, "Marzo");
    meses[2].dias = 31;
    strcpy(meses[2].abreviatura, "MAR");
    meses[2].orden = 3;

    strcpy(meses[3].nombreMes, "Abril");
    meses[3].dias = 30;
    strcpy(meses[3].abreviatura, "APR");
    meses[3].orden = 4;

    strcpy(meses[4].nombreMes, "Mayo");
    meses[4].dias = 31;
    strcpy(meses[4].abreviatura, "MAY");
    meses[4].orden = 5;

    strcpy(meses[5].nombreMes, "Junio");
    meses[5].dias = 30;
    strcpy(meses[5].abreviatura, "JUN");
    meses[5].orden = 6;

    strcpy(meses[6].nombreMes, "Julio");
    meses[6].dias = 31;
    strcpy(meses[6].abreviatura, "JUL");
    meses[6].orden = 7;

    strcpy(meses[7].nombreMes, "Agosto");
    meses[7].dias = 31;
    strcpy(meses[7].abreviatura, "AUG");
    meses[7].orden = 8;

    strcpy(meses[8].nombreMes, "Septiembre");
    meses[8].dias = 30;
    strcpy(meses[8].abreviatura, "SEP");
    meses[8].orden = 9;

    strcpy(meses[9].nombreMes, "Octubre");
    meses[9].dias = 31;
    strcpy(meses[9].abreviatura, "OCT");
    meses[9].orden = 10;

    strcpy(meses[10].nombreMes, "Noviembre");
    meses[10].dias = 30;
    strcpy(meses[10].abreviatura, "NOV");
    meses[10].orden = 11;

    strcpy(meses[11].nombreMes, "Diciembre");
    meses[11].dias = 31;
    strcpy(meses[11].abreviatura, "DEC");
    meses[11].orden = 12;
}

int diasPasados(struct mes *meses, char mes, char dia)
{
    int i;
    int days = 0;

    if (dia < 1 || dia > 31)
        return -2;

    for (i = 0; i < 12; i++)
    {
        days += meses[i].dias;

        if (mes == meses[i].orden)
        {
            days -= (meses[i].dias - dia);
            return days;
        }
    }

    return -1;
}