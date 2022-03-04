#include <stdio.h>
#include <ctype.h>

typedef struct OchoBits
{
    unsigned char b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, b5 : 1, b6 : 1, b7 : 1;
} ochoBits;

union bitsComunes
{
    int campoInt;
    float campoFloat;
    long long campoLongLong;
    double campoDouble;
    ochoBits byte[8];
} tramas;

void menu();
void printBits(union bitsComunes bits);
void clearBits(union bitsComunes *bits);

int main()
{
    char repetir;

    do
    {
        menu();
        printBits(tramas);

        printf("\nDesea probar con otro numero (S/N): ");
        scanf(" %c", &repetir);
        clearBits(&tramas);
    } while (toupper(repetir) == 'S');
}

void menu()
{
    char opcion;
    char invalidInput;

    do
    {
        invalidInput = 0;
        printf("\n¿Que tipo de dato quiere ver en binario?\n");
        printf("A) int\n");
        printf("B) float\n");
        printf("C) long long\n");
        printf("D) double\n");
        printf("Introduzca el tipo deseado: ");
        scanf(" %c", &opcion);

        switch (toupper(opcion))
        {
        case 'A':
            printf("Introduzca el entero: ");
            scanf(" %i", &tramas.campoInt);
            break;

        case 'B':
            printf("Introduzca el flotante: ");
            scanf(" %f", &tramas.campoFloat);
            break;

        case 'C':
            printf("Introduzca el long long: ");
            scanf(" %lli", &tramas.campoLongLong);
            break;

        case 'D':
            printf("Introduzca el double: ");
            scanf(" %lf", &tramas.campoDouble);
            break;

        default:
            printf("Opcion no valida, vuelva a intentarlo");
            invalidInput = 1;
        }
    } while (invalidInput);
}

void printBits(union bitsComunes bits)
{
    int i;
    printf("Su trama de bits es: ");
    for (i = 7; i >= 0; i--)
        printf("%u%u%u%u%u%u%u%u  ", bits.byte[i].b7, bits.byte[i].b6, bits.byte[i].b5, bits.byte[i].b4, bits.byte[i].b3, bits.byte[i].b2, bits.byte[i].b1, bits.byte[i].b0);
}

void clearBits(union bitsComunes *bits)
{
    int i;
    printf("Su trama de bits es: ");
    for (i = 7; i >= 0; i--)
    {
        bits->byte[i].b7 = 0;
        bits->byte[i].b6 = 0;
        bits->byte[i].b5 = 0;
        bits->byte[i].b4 = 0;
        bits->byte[i].b3 = 0;
        bits->byte[i].b2 = 0;
        bits->byte[i].b1 = 0;
        bits->byte[i].b0 = 0;
    }
}