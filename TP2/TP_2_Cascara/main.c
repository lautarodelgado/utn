#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 20


int main()
{
    ePersona persona[CANT];
    char seguir='s';
    int opcion=0;

    inicializarLibre(persona , CANT);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n\n");
        printf("Elija lo que quiere hacer: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPersona(persona , CANT);
                break;
            case 2:
                borrarPersona(persona , CANT);
                break;
            case 3:
                mostrarPersonas(persona , CANT);
                system("pause");
                break;
            case 4:
                graficoEdades(persona , CANT);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
