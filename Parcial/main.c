#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 100

int main()
{
    eC cosa[CANT];
    char letra = 's';

    inicializar(cosa , CANT);

    do
    {
        switch(menu())
        {
            case 1:
                alta(cosa , CANT);
                system("pause");
                break;
            case 2:
                baja(cosa , CANT);
                system("pause");
                break;
            case 3:
                modificacion(cosa , CANT);
                system("pause");
                break;
            case 4:
                mostrarDatos(cosa , CANT);
                system("pause");
                break;
            case 5:
                letra = 'n';
                break;
        }

    }
    while(letra == 's');

    //printf("Hello world!\n");
    return 0;
}
