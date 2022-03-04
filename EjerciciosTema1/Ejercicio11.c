#include <stdio.h>

struct byte
{
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
    unsigned char bit8 : 1;
};

union longBits
{
    unsigned long pixel;
    unsigned char bytesAux[4];
    struct byte bytes[4];
} argb;

void printColor(union longBits bits);

int main()
{
    argb.pixel = 0;
    printf("\nPonemos todos los bits a 0: ");
    printColor(argb);

    printf("\nPonemos a 1 el bit menos significativo del canal alpha: ");
    argb.bytes[3].bit1 = 1;
    printColor(argb);

    printf("\nPonemos a 1 todo el canal azul: ");
    argb.bytes[0].bit8 = 1;
    argb.bytes[0].bit7 = 1;
    argb.bytes[0].bit6 = 1;
    argb.bytes[0].bit5 = 1;
    argb.bytes[0].bit4 = 1;
    argb.bytes[0].bit3 = 1;
    argb.bytes[0].bit2 = 1;
    argb.bytes[0].bit1 = 1;
    printColor(argb);

    printf("\nPonemos a 0 el bit mas significativo del canal Azul");
    argb.bytes[0].bit8 = 0;
    printColor(argb);

    printf("Introduzca el valor long a ver su representacion en ARGB: ");
    scanf(" %ld", &argb.pixel);
    printColor(argb);

    printf("\nEl cuarto bit del canal verde es: ");
    printf(" %u\n", argb.bytes[1].bit4);

    printf("\nEl quinto bit del canal azul es: ");
    printf(" %u\n", argb.bytes[0].bit5);
}

void printColor(union longBits bits)
{
    int i;
    printf("\nEl valor en decimal, ARGB (%d, %d, %d, %d)\n",
           bits.bytesAux[3],
           bits.bytesAux[2],
           bits.bytesAux[1],
           bits.bytesAux[0]);

    printf("El valor en bits, ARGB (");
    for (i = 3; i >= 0; i--)
    {
        printf("%u%u%u%u%u%u%u%u ",
               bits.bytes[i].bit8,
               bits.bytes[i].bit7,
               bits.bytes[i].bit6,
               bits.bytes[i].bit5,
               bits.bytes[i].bit4,
               bits.bytes[i].bit3,
               bits.bytes[i].bit2,
               bits.bytes[i].bit1);
    }

    printf(")\n");
}