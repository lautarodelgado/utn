#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 5
#define TAMANIO 10

int main()
{
    int salir = 0;
    ePantalla pantallas[TAM];
    ePublicidad publicidades[TAMANIO];

    inicializarPantalla(pantallas, TAM);
    inicializarPublicidad(publicidades , TAMANIO);

    do
    {
        switch(menu())
        {

        case 1:
            altaPantalla(pantallas, TAM);
            system("pause");
            break;

        case 2:
            bajaPantalla(pantallas, TAM);
            system("pause");
            break;
        case 3:
            modificaPantalla(pantallas, TAM);
            system("pause");
            break;
        case 4:
            mostrarPantallas(pantallas, TAM);
            system("\npause");
            break;

        case 5:
            altaPublicidad(publicidades , TAMANIO , pantallas , TAM);
            system("pause");
            break;
        case 6:
            mostrarPantallasYPublicidades(pantallas , TAM , publicidades , TAMANIO);
            system("pause");
            break;
        case 7:
            modificarPublicacion(publicidades , TAMANIO , pantallas, TAM);
            system("pause");
            break;
        case 8:
            cancelarContratacion(publicidades , TAMANIO , pantallas , TAM);
            system("pause");
            break;
        case 9:
            printf("\nSalir\n\n");
            salir = 1;
            break;
        default:
            printf("\nOpcion Incorrecta\n\n");
            system("pause");
        }
    }
    while(salir != 1);

    return 0;
}
