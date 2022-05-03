//
//  listaEnlazadaSimple.c
//  listaEnlazadaSimple

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaEnlazadaSimple.h"

/*
 * Función presentada en clase de teoría
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int crearVacia(ListaEnlazadaRef raiz)
{
	*raiz = NULL;
	return 0;
}

/*
 * Función presentada en clase de teoría
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int estaVacia(ListaEnlazada raiz)
{
	return (raiz == NULL);
}

/*
 * Función presentada en clase de teoría
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
tipoNodoRef
creaNodo(tipoInfoRef info)
{
	tipoNodoRef nodo = malloc(sizeof(tipoNodo));

	if (nodo == NULL)
		return nodo;

	// Si info vale null simplemente le almacenaremos un valor por defecto, en este caso el 0.
	nodo->info = (info != NULL) ? *info : 0;
	nodo->sig = NULL;

	return nodo;
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int insertarDespuesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{
	tipoNodoRef nuevo = creaNodo(info);
	tipoNodoRef index = *raiz;

	if (nuevo == NULL)
		return -1;

	if (estaVacia(*raiz))
	{
		*raiz = nuevo;

		return 0;
	}

	// En este caso no hace falta comprobar que la direccion de la raiz sea la misma que POS
	// ya que simplemente el bucle saldra en la primera iteracion. Y como la funcion inserta despues
	// el funcionamiento sigue siendo el mismo. Simplemente lo insertaremos despues.

	// Y en el caso de que sea la ultima posicion o POS sea NULL o invalida simplemente lo añadiremos al final.
	// Ya que:
	//	1. En el caso de que POS = NULL, simplemente el bucle se ejecutara hasta el final.
	//	2. En el caso de que POS = al ultimo elemento, el bucle se ejecutara hasta el final como en el caso anterior.
	//	3. En el caso de que POS = una posicion no valida, simplemente el bucle se ejecutara hasta el final, como en los dos casos anteriores.
	while (index->sig != NULL && index != pos)
		index = index->sig;

	// Podemos realizar la signacion de esta forma ya que en el bucle no avanzamos hasta que index == NULL, si no hasta que
	// index->sig == NULL, por lo tanto en el puntero index siempre tendremos una posicion valida.
	// En el caso de que sea la ultima simplemente añadira el nodo al final, ya que index->sig valdria NULL.

	// Y en el caso de que la posicion fuese valida y estuviese entre medias de la lista el codigo nos seguira valiendo, ya que
	// en ese caso se habria salido porque index == pos, teniendo en index la direccion del elemento del que queremos insertar despues.

	// Y en el caso de que la variable pos apunte a una direccion no valida simplemente insertaremos el dato en la ultima posicion.
	// ya que el caso seria el mismo en el que index->sig vadria null.
	nuevo->sig = index->sig;
	index->sig = nuevo;

	return 0;
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int insertarAntesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info)
{
	tipoNodoRef nuevo = creaNodo(info);
	tipoNodoRef index = *raiz;

	if (nuevo == NULL)
		return -1;

	if (estaVacia(*raiz) || *raiz == pos || pos == NULL)
	{
		if (!estaVacia(*raiz))
			nuevo->sig = *raiz;

		*raiz = nuevo;

		return 0;
	}

	while (index->sig != NULL && index->sig != pos)
		index = index->sig;

	// En el caso de que se haya salido porque no se correspondan las posiciones simplemente
	// liberaremos el espacio almacenado y devolveremos -2
	if (index->sig != pos)
	{
		free(nuevo);
		return -2;
	}

	// Una vez llegados a esta parte del codigo sabemos que:
	// 	1. pos no es null.
	// 	2. index no es nulo ni vale la primera posicion
	//	3. index->sig es igual a pos.
	// Por lo tanto podemos proceder a insertar el nodo normalmente.
	nuevo->sig = index->sig;
	index->sig = nuevo;

	return 0;
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int insertarNodoComienzo(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	tipoNodoRef nuevo = creaNodo(info);

	if (nuevo == NULL)
		return -1;

	// Como simplemente estamos insertando al comiendo nos da igual que la raiz valga NULL.
	nuevo->sig = *raiz;
	*raiz = nuevo;

	return 0;
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int insertarNodoFinal(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	tipoNodoRef nuevo = creaNodo(info);
	tipoNodoRef index = *raiz;

	if (nuevo == NULL)
		return -1;

	if (estaVacia(*raiz))
	{
		nuevo->sig = *raiz;
		*raiz = nuevo;

		return 0;
	}

	while (index->sig != NULL)
		index = index->sig;

	// como sabemos que aqui solo llegamos cuando index->sig valga null ya que index esta en la ultima posicion simplemente
	// insertamos el nuevo nodo, el cual no hace falta poner nuevo->null ya que la funcion creaNodo lo hace por nosotros.
	index->sig = nuevo;

	return 0;
}

/*
 * Esta función recibe una lista (por referencia), un índice entero y una
 * variable de tipoInfo por referencia. Debe insertar un nuevo nodo
 * en la posición indicada por el índice entero (implica recorrido contando
 * nodos hasta el valor indicado por indice). Ojo, hay que garantizar que
 * esa posición existe, es decir, que si la lista tiene 5 nodos, (los numeramos
 * de 0 a 4), las posiciones válidas son 0, 1, 2, 3, 4, 5 (la posición 5
 * es equivalente a añadir al final).
 * Si la posición no existe, no se puede hacer la inserción (en nuestro ejemplo,
 * la posición -1 ya no existe, y la posición 6 tampoco).
 * Se puede hacer uso de alguna de las funciones implementadas, aunque implique
 * ineficiencias (recorridos adicionales de la lista enlazada). Opcional
 * escribir una versión eficiente que no implique repetir recorridos.
 */
int insertarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice, tipoInfoRef info)
{
	tipoNodoRef nuevo = NULL;
	tipoNodoRef anterior = NULL;
	tipoNodoRef index = *raiz;
	int i;

	// Si es un numero negativo ni empezamos a realizar la comprobacion
	if (indice < 0)
		return -2;

	// Llamamos a la funcion crear nodo aqui en vez de al comiendo, ya que si no nos tocaria hacer un free en el caso de que el indice
	// fuera menor que 0, asi nos lo evitamos.
	nuevo = creaNodo(info);

	if (nuevo == NULL)
		return -1;

	for (i = 0; i < indice && index != NULL; i++)
	{
		anterior = index;
		index = index->sig;
	}

	// Sabamos que anterior solo vale NULL cuando el bucle no se haya ejecutado ninguna vez.
	// Es decir, que la posicion a insertar sea la de inicio o la lista pasada este a NULL.

	// En este primer if comprobamos que el usuario a introducido otra posicion a insertar
	// que no es la de inicio, por lo tanto devolvemos -2
	if (anterior == NULL && indice)
	{
		free(nuevo);
		return -2;
	}

	// Comprobamos que el usuario a indicado la posicion 0, es decir, quiere insertar en el comienzo.
	if (anterior == NULL && !indice)
	{
		nuevo->sig = *raiz;
		*raiz = nuevo;

		return 0;
	}

	// Sabemos que si index vale NULL puede ser solo por dos motivos:
	//	1. La lista estaba vacia.
	//	2. El bucle se ha ejecutado hasta el final.
	// Y como en este caso, ya hemos comprobado con la variable anterior los posibles casos
	// en los que la lista este vacia, sabemos al 100% que a partir de aqui si index vale NULL solo va a poder ser
	// porque se haya llegado al final de la lista.

	// Comprobamos que el usuario a introducido como indice una posicion invalida.

	// Ya que, si tenemos por ejemplo, una lista de tamaño 3, es decir, con los indices:
	// 0, 1, 2 tal como nos indica el enunciado la posicion 3 indicaria que tendriamos que insertar al final.
	// Como nuestro bucle for tiene al final i++, la ultima iteracion sumara un valor a i, dandonos el valor correspondiente.
	// Es decir:
	//	En el primer ciclo i valdra 0 y ejecutamos el contenido y aumentamos i a 1.
	// 	En el segundo ciclo i valdra 1 y ejecutamos el contenido y aumentamos i a 2.
	//	En el tercer ciclo i valdra 2 y ejecutamos el contenido y aumentamos i a 3.
	//	En el cuarto ciclo no entra ya que no se cumplen las condiciones.
	// Por tanto nos quedamos con el valor de i igual a la siguiente posicion a insertar en la lista,
	// con lo cual simplemente comprobamos si el indice introducido por el usuario es mayor a i, en caso de que si lo sea
	// no insertamos el valor, ya que es una posicion no valida. En el caso contrario insertamos el dato.
	if (index == NULL && indice > i)
	{
		free(nuevo);
		return -2;
	}

	// Comprobamos que el usuario a introducido una posicion valida
	if (index == NULL && indice == i)
	{
		anterior->sig = nuevo;
		return 0;
	}

	// En caso de que no se haya entrado en ningun if anterior quiere decir que se ha introducido una posicion valida entre medias
	// de la lista.
	anterior->sig = nuevo;
	nuevo->sig = index;

	return 0;
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int eliminarNodo(ListaEnlazadaRef raiz, tipoNodoRef pos)
{
	tipoNodoRef index = *raiz;

	if (estaVacia(*raiz))
		return -1;

	// Comprobamos que sea la primera posicion
	if (*raiz == pos)
	{
		*raiz = (*raiz)->sig;
		free(index);

		return 0;
	}

	while (index->sig != NULL && index->sig != pos)
		index = index->sig;

	// Comprobamos que se haya salido por que no se ha encontrado pos
	// En cuyo caso no eliminaremos nada
	if (index->sig == NULL)
		return -2;

	index->sig = pos->sig;
	free(pos);

	return 0;
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int eliminarNodoComienzo(ListaEnlazadaRef raiz)
{
	// Simplemente llamamos al metodo eliminar nodo
	return eliminarNodo(raiz, *raiz);
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int eliminarNodoFinal(ListaEnlazadaRef raiz)
{
	tipoNodoRef index = *raiz;

	if (estaVacia(*raiz))
		return -1;

	// Avanzamos hasta el ultimo nodo
	while (index->sig != NULL)
		index = index->sig;

	// Al hacerlo de esta forma tendriamos un programa menos eficiente, ya que aparte del bucle anterior para llegar a la ultima posicion
	// tendriamos otro bucle dentro del metodo eliminar nodo.
	// Otra forma de hacerlo seria hacer directamente el intercambio en este metodo.
	// Pero ya que tenemos otro metodo que nos hace el trabajo simplemente lo llamaré.
	return eliminarNodo(raiz, index);
}

/*
 * Esta función recibe una lista (por referencia) y un índice entero
 * Debe eliminar el nodo situado en en la posición indicada por el
 * índice entero (implica recorrido contando nodos hasta el valor
 * indicado por indice). Ojo, hay que garantizar que
 * esa posición existe, es decir, que si la lista tiene 5 nodos (los numeramos
 * de 0 a 4), las posiciones válidas son 0, 1, 2, 3, 4.
 * Si la posición no existe, no se puede hacer la eliminación (en nuestro ejemplo,
 * la posición -1 ya no existe, y la posición 5 tampoco).
 * Se puede hacer uso de alguna de las funciones implementadas, aunque
 * implique ineficiencias (recorridos adicionales de la lista enlazada).
 * Opcional escribir una versión eficiente que no implique repetir recorridos.
 */
int eliminarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice)
{
	tipoNodoRef index = *raiz;
	int i;

	if (estaVacia(*raiz))
		return -1;

	if (indice < 0)
		return -2;

	if (!indice)
		return eliminarNodoComienzo(raiz);

	for (i = 0; i < indice && index->sig != NULL; i++)
		index = index->sig;

	if (index->sig == NULL && indice != i - 1)
		return -2;

	return eliminarNodo(raiz, index);
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la última versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int liberarListaEnlazada(ListaEnlazadaRef raiz)
{
	tipoNodoRef index = NULL;

	if (estaVacia(*raiz))
		return -1;

	while (*raiz != NULL)
	{
		index = *raiz;
		*raiz = (*raiz)->sig;
		free(index);
	}

	*raiz = NULL;

	return 0;
}

/********************************************************************
 *                                                                  *
 * Las cuatro funciones que vienen a continuación dependen de cómo  *
 * está definido el tipo de dato tipoInfo. No es lo mismo mostrar   *
 * por pantalla el contenido de los datos almacenados en una lista  *
 * enlazada si éste es de tipo entero, o si se trata de un registro.*
 * Adicionalmente, y para que el alumno no pierda el tiempo         *
 * en implementar funciones que aportan poco desde un punto de vista*
 * docente, se proporcionan ya implementadas las funciones          *
 * mostrarListaEnlazada() y crearListaValoresAleatorios(). Las otras*
 * dos son sencillas y se dejan al alumno su implementación.        *
 *                                                                  *
 *******************************************************************/

/*
 * Esta función recibe una lista (por referencia) y un índice entero
 * Debe devolver la información almacenada en el nodo situado en la
 * posición indicada por el índice entero (implica recorrido contando nodos
 * hasta el valor indicado por indice). Ojo, hay que garantizar que
 * esa posición existe, es decir, que si la lista tiene 5 nodos (los numeramos
 * de 0 a 4), las posiciones válidas son 0, 1, 2, 3, 4.
 * Si la posición no existe, no se puede devolver nada (en nuestro ejemplo,
 * la posición -1 ya no existe, y la posición 5 tampoco).
 * IMPORTANTE: tipoInfo es, en este caso particular, un entero. Aunque
 * la dependencia es pequeña, si existe. ¿Cómo se devuelve el código de error
 * en caso de no existir la posición indicada por el parámetro indice?. Si
 * tipoInfo es un int es sencillo, si es un registro también, pero ya es
 * diferente implementación.
 */
tipoInfo
devolverInfoPosicionIndice(ListaEnlazada raiz, int indice)
{
	tipoNodoRef index = raiz;
	int i;

	if (estaVacia(raiz) || indice < 0)
		return -404;

	for (i = 0; i < indice && index->sig != NULL; i++)
		index = index->sig;

	if (index->sig == NULL && indice != i)
		return -400;

	return index->info;
}

/*
 * Función presentada en clase de teoría. Se debe implementar
 * la versión presentada en clase y disponible en las diapositivas.
 * Todos los aspectos sobre funcionamiento y valor a devolver
 * están descritos en las diapositivas
 */
int insertarOrdenada(ListaEnlazadaRef raiz, tipoInfoRef info)
{
	tipoNodoRef index = *raiz;
	if (estaVacia(*raiz) || (*raiz)->info >= *info)
		return insertarNodoComienzo(raiz, info);

	while (index != NULL && index->info < *info)
		index = index->sig;

	return insertarAntesDeNodo(raiz, index, info);
}

int mostrarListaEnlazada(ListaEnlazada raiz)
{
	tipoNodoRef aImprimir;
	int res = 0, i = 0;

	printf("\n\n");
	printf("%-14s%-10s\n", "  Posición", "Valor");
	printf("%-14s%-10s\n", "  ==========", "======");

	aImprimir = raiz;
	while (aImprimir != NULL)
	{
		printf("\t%3d)\t%7d\n", i++, aImprimir->info);
		aImprimir = aImprimir->sig;
	}
	return res;
}

int crearListaValoresAleatorios(ListaEnlazadaRef raiz, int numNodos)
{
	int i;
	tipoInfo temp;

	if (estaVacia(*raiz))
	{
		srandom(time(NULL));
		for (i = 0; i < numNodos; i++)
		{
			temp = random() % 10000;
			insertarDespuesDeNodo(raiz, NULL, &temp);
			// insertarAntesDeNodo(raiz, NULL, &temp);
			// insertarNodoFinal(raiz, &temp);
			// insertarNodoComienzo(raiz, &temp);
		}
		return 0;
	}
	return -1;
}
