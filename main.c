#include "scanner.c"

int main()
{
	freopen("input.txt", "r", stdin);
    int token;
    int identificadores = 0, constantes_enteras = 0, numerales = 0, errores = 0;

    printf("Los resultados del input.txt son: \n\n");
    do
    {
        token = scanner();

        switch(token)
        {
            case IDENTIFICADOR:
            	printf("Identificador\n");
            	identificadores++;
            	break;

            case CONSTANTE_ENTERA:
            	printf("Constante entera\n");
            	constantes_enteras++;
            	break;

            case NUMERAL:
            	printf("Numeral\n");
            	numerales++;
            	break;

            case ERROR:
            	printf("Error\n");
            	errores++;
            	break;
            }
            
    } while(token != FDT);
    
    printf("----\n");
    printf("Totales:\n");
    printf("Identificadores %d \n", identificadores);
    printf("Constantes enteras %d \n", constantes_enteras);
    printf("Numerales %d \n", numerales);
    printf("Errores %d \n", errores);

	getch();
    return 0;
}
