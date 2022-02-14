#include <stdio.h>
#include <math.h>

int esPrimo(long int num);
int primosContiguos(long int num, long int *anterior, long int *posterior);

int main()
{
	printf("15: %d\n", esPrimo(15));
	printf("18: %d\n", esPrimo(18));
	printf("11: %d\n", esPrimo(11));
	printf("51: %d\n", esPrimo(51));

	long int anterior, posterior;

	primosContiguos(52, &anterior, &posterior);

	printf("El primo inmediatamente superior de 52 es: %ld\n", posterior);
	printf("El primo inmediatamente inferior a 52 es: %ld\n", anterior);

	primosContiguos(2, &anterior, &posterior);

	printf("El primo inmediatamente superior de 2 es: %ld\n", posterior);
	printf("El primo inmediatamente inferior a 2 es: %ld\n", anterior);

	return 0;
}

int esPrimo(long int num)
{
	int i;
	if (num <= 0)
		return -1;
	if (!(num % 2) || num == 1)
		return 0;

	// Empezamos direcamente en el valor 3, ya que la comprobación con el 2
	// la hemos realizado en el condicional anterior.

	// Se ha mejorado indicando la raiz cuadrada. Ya que en progra 1 nos comentó el profesor de prácticas
	// 	que matematicamente si no era divisible hasta su raiz cuadrada no lo iba a ser posterior a ella
	for (i = 3; i <= sqrt(num); i += 2) // Se mejora usando i+=2, ya que ya hemos comprobado que no fuese par.
		if (!(num % i))
			return 0;

	return 1;
}

int primosContiguos(long int num, long int *anterior, long int *posterior)
{
	int flag = 1;
	long int cont = num;
	int i;
	if (num <= 1)
		return -1;

	while (flag)
	{
		++cont;
		if (esPrimo(cont) == 1)
		{
			flag = 0;
			*posterior = cont;
		}
	}

	cont = num;
	*anterior = -1;

	while (cont > 1)
	{
		--cont;
		if (esPrimo(cont) == 1)
		{
			*anterior = cont;
			cont = -1;
		}
	}

	return 0;
}
