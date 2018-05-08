#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char letra = 's';
    eEmpleado gente[3];


    inicializarEmpleados(gente , 3);

    do
    {
        switch(menu())
        {
        case 1:
            alta(gente ,3);
            system("pause");
            break;
        case 2:
            bajaPorLegajo(gente , 3);
            system("pause");
            break;
        case 3:
            system("pause");
            break;
        case 4:
            listar(gente ,3);
            system("pause");
            break;
        case 5:
            system("pause");
            break;
        case 6:
            letra = 'n';
            break;
        default:
            printf("\nERROR, ingrese una opcion valida.\n\n");
            system("pause");
        }
    }
    while(letra == 's');
    return 0;
}
