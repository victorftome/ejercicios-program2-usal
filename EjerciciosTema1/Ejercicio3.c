/* ENUNCIADO
¿Es válida en un programa la siguiente definición?. ¿Por qué?

enum vehiculo {moto, coche, carruaje, autobus, bicicleta, motocicleta};
enum transporte {avion, barco, coche, ferrocarril, tranvia};
*/

/* SOLUCIÓN
No, no es una solución válida, ya que los valores de los enumeradores tienen que ser constantes,
no se pueden repetir ni en enumeradores separados. Y como se puede ver tanto en el enumerador de
vehiculo como en el de transporte el nombre de identificador "coche" se repite.
*/