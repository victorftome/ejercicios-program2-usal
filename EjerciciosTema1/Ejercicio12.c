#include <stdio.h>
#include <stdlib.h>

struct fraccion
{
	int numerador, denominador;
};

struct fraccion scanFraccion();

/* Devolverá un entero con el código de la operación realizada
	1 -> Multiplicación
	2 -> División
	3 -> Suma
	4 -> resta
	0 -> Operación no válida
*/
int operacion(struct fraccion x, struct fraccion y, struct fraccion *resultado, char operacion);
void printFraccion(struct fraccion f);
int getMCM(struct fraccion num1, struct fraccion num2);
struct fraccion simplicar(struct fraccion f);

int main()
{
	struct fraccion f1, f2, resultado;
	int resultadoOperacion;
	char operador;

	printf("Introduzca la primera fraccion\n");
	f1 = scanFraccion();

	printf("\nSIntroduzca la segunda fraccion\n");
	f2 = scanFraccion();

	printf("\nLas fracciones introducidas son: ");
	printFraccion(f1);
	printf(" y ");
	printFraccion(f2);

	do
	{
		printf("\n\nIntroduzca la operacion a realizar (+, -, *, /) en caso de introducir otro caracter se devolvera la fraccion 0/0: ");
		scanf(" %c", &operador);

		resultadoOperacion = operacion(f1, f2, &resultado, operador);
	} while (!resultadoOperacion);

	printf("\nEl resultado de la operacion ha sido: ");
	printFraccion(resultado);

	printf("\nFraccion simplificada: ");
	printFraccion(simplicar(resultado));

	printf("\n");

	return 0;
}

struct fraccion scanFraccion()
{
	struct fraccion temp;

	printf("Intoduzca el numerador: ");
	scanf("%d", &temp.numerador);

	do
	{
		printf("Introduzca el denominador (NO 0): ");
		scanf("%d", &temp.denominador);
	} while (!(temp.denominador)); // Comprobamos que no sea 0

	return temp;
}

int operacion(struct fraccion x, struct fraccion y, struct fraccion *resultado, char operacion)
{
	int mcm;

	switch (operacion)
	{
	case '*':
		resultado->numerador = x.numerador * y.numerador;
		resultado->denominador = x.denominador * y.denominador;

		return 1;

	case '/':
		resultado->numerador = x.numerador * y.denominador;
		resultado->denominador = x.denominador * y.numerador;

		return 2;

	// Multiplicamos el numerador por el resultado de la division del mcm obtenido entre el denominador
	// Esto nos dará el entero por el cual tendremos que multiplicar el numerador.
	case '+':
		mcm = getMCM(x, y);

		resultado->denominador = mcm;
		resultado->numerador = x.numerador * (mcm / x.denominador) + y.numerador * (mcm / y.denominador);

		return 3;

	case '-':
		mcm = getMCM(x, y);

		resultado->denominador = mcm;
		resultado->numerador = x.numerador * (mcm / x.denominador) - y.numerador * (mcm / y.denominador);

		return 4;

	default:
		return 0;
	}
}

void printFraccion(struct fraccion f)
{
	printf("%d/%d", f.numerador, f.denominador);
}

int getMCM(struct fraccion num1, struct fraccion num2)
{
	if (num1.denominador == num2.denominador)
		return num1.denominador;

	// Hacemos el valor obsoluto ya que para devolver el MCM nos interesa el positivo
	int flag = 1;
	int mayor = (abs(num1.denominador) > abs(num2.denominador)) ? abs(num1.denominador) : abs(num2.denominador);
	int menor = (abs(num1.denominador) > abs(num2.denominador)) ? abs(num2.denominador) : abs(num1.denominador);
	int cont = mayor;

	while (flag)
	{
		if (!(cont % mayor) && !(cont % menor))
		{
			flag = 0;	 // Establecemos la flag a false para que no siga el bucle
			return cont; // Hacemos un return con el valor. Gracias a este return la flag no sería necesaria.
		}

		cont++;
	}
}

struct fraccion simplicar(struct fraccion f)
{
	int i;

	// En caso de que el denominador sea negativo pasamos el signo al numerador
	// (en caso de ser ambos negativos pasara a positivo)
	if (f.denominador < 0)
	{
		f.numerador *= -1;
		f.denominador *= -1;
	}

	// Recorremos desde 2 hasta el menor de los números, comprobando si ambos son divisibles entre los números
	// por los que vamos pasando. Se usa el valor absoluto en caso de que haya algun negativo, ya que solo nos interesa
	// el número positivo entero por el cual son divisibles.
	for (i = 2; i <= ((abs(f.numerador) > abs(f.denominador)) ? abs(f.denominador) : abs(f.numerador)); i++)
	{
		// En caso de encontrar el número simplemente dividiremos tanto el numerador como el denominador por ese número
		// Y estableceremos i a 1 para volver a empezar con la busqueda de divisores válidos.
		if (!(f.numerador % i) && !(f.denominador % i))
		{
			f.numerador /= i;
			f.denominador /= i;
			i = 1; // Igualamos a 1 ya que al acabar la iteracción hara un incremento a 2.
		}
	}

	return f;
}