/* ENUNCIADO
Un formato de coma flotante para la representación de números reales es el estándar
IEEE 754, propuesto por el Institute of Electrical and Electronics Engineers.
Según indica este estándar, el formato de representación de números en 32 bits está
compuesto por el signo de la mantisa, el exponente y la mantisa, según se describe en la
siguiente tabla.
*/

#include <stdio.h>

struct bits
{
    unsigned bit0 : 1;
    unsigned bit1 : 1;
    unsigned bit2 : 1;
    unsigned bit3 : 1;
    unsigned bit4 : 1;
    unsigned bit5 : 1;
    unsigned bit6 : 1;
    unsigned bit7 : 1;
    unsigned bit8 : 1;
    unsigned bit9 : 1;
    unsigned bit10 : 1;
    unsigned bit11 : 1;
    unsigned bit12 : 1;
    unsigned bit13 : 1;
    unsigned bit14 : 1;
    unsigned bit15 : 1;
    unsigned bit16 : 1;
    unsigned bit17 : 1;
    unsigned bit18 : 1;
    unsigned bit19 : 1;
    unsigned bit20 : 1;
    unsigned bit21 : 1;
    unsigned bit22 : 1;
    unsigned bit23 : 1;
    unsigned bit24 : 1;
    unsigned bit25 : 1;
    unsigned bit26 : 1;
    unsigned bit27 : 1;
    unsigned bit28 : 1;
    unsigned bit29 : 1;
    unsigned bit30 : 1;
    unsigned bit31 : 1;
};

union IEEE_754
{
    float flotante;
    struct bits b;
};

void getBits(float);

int main()
{
    char opcion;
    float f;
    puts("FORMATO COMA FLOTANTE IEEE 754 PARA NUMEROS FLOAT");
    puts("=================================================");

    do
    {
        printf("Introduzca el numero flotante a ver en IEEE_754: ");
        scanf("%f", &f);
        getBits(f);
        printf("\nDesea introducir otro numero (S/N): ");
        scanf(" %c", &opcion);
    } while (opcion == 'S' || opcion == 's');

    return 0;
}

void getBits(float f)
{
    union IEEE_754 bits;
    bits.flotante = f;

    printf("%7.2f = ", f);

    printf("%d * %d%d%d%d%d%d%d%d",
           bits.b.bit31,
           bits.b.bit30,
           bits.b.bit29,
           bits.b.bit28,
           bits.b.bit27,
           bits.b.bit26,
           bits.b.bit25,
           bits.b.bit24,
           bits.b.bit23);

    printf(" * %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
           bits.b.bit22,
           bits.b.bit21,
           bits.b.bit20,
           bits.b.bit19,
           bits.b.bit18,
           bits.b.bit17,
           bits.b.bit16,
           bits.b.bit15,
           bits.b.bit14,
           bits.b.bit13,
           bits.b.bit12,
           bits.b.bit11,
           bits.b.bit10,
           bits.b.bit9,
           bits.b.bit8,
           bits.b.bit7,
           bits.b.bit6,
           bits.b.bit5,
           bits.b.bit4,
           bits.b.bit3,
           bits.b.bit2,
           bits.b.bit1,
           bits.b.bit0);
}