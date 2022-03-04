/* ENUNCIADO
Encuentra los errores en la siguiente declaración de estructura y posterior definición de
variable

struct hormiga
{
    int patas;
    char especie[41];
    float tiempo;
};
hormiga colonia[200];
*/

struct hormiga
{
    int patas;
    char especie[41];
    float tiempo;
};

// Error solucionado:
//   Faltaba la palabra struct en la declaración, ya que no se indica un typedef a la
//   hora de definir la estructura.
struct hormiga colonia[200];