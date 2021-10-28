// AQUI TODAS LAS FUNCIONES DE HASH QUE PODRIAMOS USAR
// https://softwareengineering.stackexchange.com/questions/49550/which-hashing-algorithm-is-best-for-uniqueness-and-speed Acá hay muchas opciones
// http://www.cse.yorku.ca/~oz/hash.html
// https://stackoverflow.com/questions/34595/what-is-a-good-hash-function
// http://burtleburtle.net/bob/hash/doobs.html
// ????????como importamos esto????????? https://github.com/sindresorhus/fnv1a
// ????????como importamos esto????????? https://github.com/aappleby/smhasher
// https://en.wikipedia.org/wiki/List_of_hash_functions
// https://www.strchr.com/hash_functions
// ---------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdint.h>

// FUNCION DJB2
// https://stackoverflow.com/questions/7666509/hash-function-for-string
unsigned long
djb2(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

// FUNCION SDBM
// http://www.cse.yorku.ca/~oz/hash.html
static unsigned long
sdbm(str)
unsigned char *str;
{
    unsigned long hash = 0;
    int c;

    while (c = *str++)
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash;
}

// Paul Larson's
// Originalmente era de c++ y recibía una seed. Reemplazar/ rehacer
// https://stackoverflow.com/questions/98153/whats-the-best-hashing-algorithm-to-use-on-a-stl-string-when-using-hash-map
unsigned int
paul(
    const char* s)
{
    unsigned int seed = 0;
    unsigned int hash = seed;
    while (*s)
    {
        hash = hash * 101  +  *s++;
    }
    return hash;
}

/* D. J. Bernstein hash function */
// Muy similar a djb2?
// https://codereview.stackexchange.com/questions/85556/simple-string-hashing-algorithm-implementation
static size_t djb_hash(const char* cp)
{
    size_t hash = 5381;
    while (*cp)
        hash = 33 * hash ^ (unsigned char) *cp++;
    return hash;
}
/* FUNCION SIN USAR POR RETORNAR NUMEROS NEGATIVOS
// Fowler/Noll/Vo (FNV) hash function, variant 1a
// https://codereview.stackexchange.com/questions/85556/simple-string-hashing-algorithm-implementation
// La palabra meme da negativo pero el hash<0 no funciona
static size_t fnv1a_hash(const char* cp)
{
    size_t hash = 0x811c9dc5;
    while (*cp) {
        hash ^= (unsigned char) *cp++;
        hash *= 0x01000193;
    }
    // Esto lo agregó Santiago:
    if (hash<0) {
      printf("Trigger\n");
      hash = hash * (-1);
    };
    return hash;
}
*/
/*
// .C para probar funciones de hashing. Compilar y llamar como: ./NOMBRE_COMPILADO NOMBRE_FUNCION TEXTO
// Ejemplo: astrocinco$ ./prueba_funciones djb2 hola  ----->  Resultado: hola -> 6385302889
// Si escribiste una función que no está retorna 0 en la terminal.
int main(int argc, char* argv[]){
  size_t resultado = 0;
  if (argc != 3) {
    printf("Error cantidad de parametros\n");
    return -1;
  }

  if (strcmp(argv[1], "djb2") == 0){
    resultado = djb2(argv[2]);
  }

  if (strcmp(argv[1], "sdbm") == 0){
    resultado = sdbm(argv[2]);
  }

  if (strcmp(argv[1], "paul") == 0){
    resultado = paul(argv[2]);
  }

  if (strcmp(argv[1], "djb") == 0){
    resultado = djb_hash(argv[2]);
  }

  if (strcmp(argv[1], "fnv1a") == 0){
    resultado = fnv1a_hash(argv[2]);
  }

  printf("Resultado: %s -> %li\n", argv[2], resultado);
  return 0;
}
*/