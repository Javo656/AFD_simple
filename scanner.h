#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

enum caracteres {LETRA, NUMERO, CARACTER_NUMERAL, OTRO, ESPACIO_BLANCO, FIN};
enum tokens {IDENTIFICADOR, CONSTANTE_ENTERA, NUMERAL, ERROR, FDT};

int nuevoEstado(char c);
int scanner();
int asignarToken(int e, char c2);