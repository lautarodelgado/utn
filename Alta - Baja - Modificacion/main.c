#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int i;
    char letra = 's';
    eEmpleado gente[3];
    eSector sectores[5];

    inicializarEmpleados(gente , 3);
    hardCode(sectores);

    printf("ID:\tDESCRIPCION:\t\t\n");
    for(i=0 ; i < 5 ;i++)
    {
        printf("%d\t%s\t\t\n" , sectores[i].id , sectores[i].descripcion);
        //system("pause");
    }
    system("pause");


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
