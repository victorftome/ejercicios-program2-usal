/* ENUNCIADO Pt 1
Declarar un tipo de dato estructura para representar un alumno. Los campos de los que
debe de disponer son:
    Nombre completo, cadena de caracteres
    Curso, entero
    Fecha nacimiento, estructura de tres campos enteros para el día, mes y año
    Dirección completa, cadena de caracteres
    10 notas parciales, vector de 10 números reales
Definir una variable del tipo estructura anterior.
*/

#include <stdio.h>

struct fecha
{
    int dia, mes, anho;
};

struct alumno
{
    char nombre[50];
    int curso;
    struct fecha fechaNacimiento;
    char direccion[300];
    float notasParciales[10];
};

struct alumno alumnoEjemplo;

/* ENUNCIADO Pt 2
Escribir una función que lea de teclado los campos de una estructura de tipo alumno y la
devuelva al módulo llamador como valor de retorno de la función.
*/

struct alumno getAlumno();

struct alumno getAlumno()
{
    struct alumno alumnoTemp;
    int i;

    puts("Introduzca su nombre");
    gets(alumnoTemp.nombre);

    puts("Introduzca el curso que se esta cursando");
    scanf("%d", &alumnoTemp.curso);

    puts("Introduzca la fecha de nacimiento (dia-mes-a\244o)");
    scanf("%d-%d-%d", &alumnoTemp.fechaNacimiento.dia, &alumnoTemp.fechaNacimiento.mes, &alumnoTemp.fechaNacimiento.anho);

    puts("Introduzca su direccion");
    gets(alumnoTemp.direccion);

    puts("Introduzca sus notas parciales");
    for (i = 0; i < 10; i++)
    {
        printf("%d. Nota: ", i + 1);
        scanf("%f", &alumnoTemp.notasParciales[i]);
    }

    return alumnoTemp;
}

/* ENUNCIADO Pt 3
Escribir una función que lea de teclado los campos de una estructura de tipo alumno y la
devuelva al módulo llamador a través de un parámetro que se le haya pasado por
referencia.
*/

void getAlumnoRef(struct alumno *);

void getAlumnoRef(struct alumno *alumno)
{
    int i;

    puts("Introduzca su nombre");
    gets(alumno->nombre);

    puts("Introduzca el curso que se esta cursando");
    scanf("%d", &alumno->curso);

    puts("Introduzca la fecha de nacimiento (dia-mes-a\244o)");
    scanf("%d-%d-%d", &alumno->fechaNacimiento.dia, &alumno->fechaNacimiento.mes, &alumno->fechaNacimiento.anho);

    puts("Introduzca su direccion");
    gets(alumno->direccion);

    puts("Introduzca sus notas parciales");
    for (i = 0; i < 10; i++)
    {
        printf("%d. Nota: ", i + 1);
        scanf("%f", &alumno->notasParciales[i]);
    }
}

/* ENUNCIADO Pt 4
Escribir una función que reciba una estructura de tipo alumno por valor, y presente sus
campos en pantalla.
*/

void printAlumno(struct alumno);

void printfAlumno(struct alumno alumno)
{
    int i;

    printf("Nombre: %s\n", alumno.nombre);
    printf("Curso: %d\n", alumno.curso);
    printf("Fecha de nacimiento: %d-%d-%d\n", alumno.fechaNacimiento.dia, alumno.fechaNacimiento.mes, alumno.fechaNacimiento.anho);
    printf("Direccion: %s\n", alumno.direccion);
    puts("Notas parciales: ");
    for (i = 0; i < 10; i++)
        printf("%d. Nota: %d\n", i + 1, alumno.notasParciales[i]);
}

/* ENUNCIADO Pt 5
Escribir una función que reciba una estructura de tipo alumno por referencia, y presente
sus campos en pantalla.
*/
void printAlumnoRef(struct alumno *);

void printfAlumnoRef(struct alumno *alumno)
{
    int i;

    printf("Nombre: %s\n", alumno->nombre);
    printf("Curso: %d\n", alumno->curso);
    printf("Fecha de nacimiento: %d-%d-%d\n", alumno->fechaNacimiento.dia, alumno->fechaNacimiento.mes, alumno->fechaNacimiento.anho);
    printf("Direccion: %s\n", alumno->direccion);
    puts("Notas parciales: ");
    for (i = 0; i < 10; i++)
        printf("%d. Nota: %d\n", i + 1, alumno->notasParciales[i]);
}