#include "scanner.h"

int tabla[9][6]={ {1, 2, 6, 3, 0, 8},  // 0 ESTADO INICIAL
                  {1, 1, 4, 4, 4, 4},  // 1 ESTADO IDENTIFICADOR
                  {5, 2, 5, 5, 5, 5},  // 2 ESTADO CONSTANTE ENTERA
                  {7, 7, 7, 3, 7, 7},  // 3 ESTADO ERROR
                  {8, 8, 8, 8, 8, 8},	// 4 ESTADO final identificador
                  {8, 8, 8, 8, 8, 8},	// 5 ESTADO final constante entera
                  {8, 8, 8, 8, 8, 8},	// 6 ESTADO final numeral
                  {8, 8, 8, 8, 8, 8},	// 7 ESTADO final error
                  {8, 8, 8, 8, 8, 8}	// 8 ESTADO final texto
				 }; 

int estado_actual = 0;

int nuevoEstado(char caracter) { // Devolvera el combo [][] correspondiente, los distintos estados es lo que debera ser, a menos que aparezca un otro, el while del scanner manejara el espacio en blanco, para cortar
    if (isalpha(caracter))
        return tabla[estado_actual][LETRA];

    else if (isdigit(caracter))
        return tabla[estado_actual][NUMERO];

    else if (caracter == '#')
        return tabla[estado_actual][CARACTER_NUMERAL];

    else if (isspace(caracter))
        return tabla[estado_actual][ESPACIO_BLANCO];

    else if (caracter == EOF)
    	return tabla[estado_actual][FIN];

    else
        return tabla[estado_actual][OTRO];
}

int asignarToken(int estado, char caracter) {
    switch (estado) {
        case 4:
            ungetc(caracter, stdin);
            return IDENTIFICADOR;
            break;
    
        case 5:
            ungetc(caracter, stdin);
            return CONSTANTE_ENTERA;
            break;

        case 6:
            return NUMERAL;
            break;

        case 7:
            ungetc(caracter, stdin);
            return ERROR;
            break;

        case 8:
            return FDT;
            break;
    }
}


int scanner() {
    estado_actual = 0;
    char caracter_actual;

    while (estado_actual < 4){
	    caracter_actual = getchar();
	    estado_actual = nuevoEstado(caracter_actual);
    }

    int valor_token = asignarToken(estado_actual, caracter_actual);

    return valor_token;
}
