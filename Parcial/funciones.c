#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu()
{
    int opcion;

    system("cls");
    printf("1-Alta.\n");
    printf("2-Baja.\n");
    printf("3-Modificar.\n");
    printf("4-Mostrar datos.\n");
    printf("5-Salir.\n\n");

    printf("Ingrese opcion: ");
    scanf("%d" , &opcion);

    return opcion;
}

void inicializar(eC vec[] , int tam)
{
    int i;

    for(i=0 ; i < tam ; i++)
    {
        vec[i].estado = 0;
    }
}

int buscarLibre(eC vec[] , int tam)
{
    int espacioLibre = -1;
    int i;

    for(i=0 ; i < tam ; i++)
    {
        if(vec[i].estado == 0)
        {
            espacioLibre = i;
            break;
        }
    }

    return espacioLibre;
}

int buscarAlgo(eC vec[] , int tam , int dato)
{
    int i;
    int datoRepetido = -1;

    for(i=0 ; i < tam ; i++)
    {
        if(vec[i].estado == 1 && dato == vec[i].algo)
        {
            datoRepetido = i;
            break;
        }
    }
    return datoRepetido;
}

void alta(eC vec[] , int tam)
{
    eC nuevoAlgo;
    int indice;
    int repetido;
    int algo;

    indice = buscarLibre(vec , tam);

    if(indice == -1)
    {
        printf("No hay mas espacio!");
    }
    else
    {
        printf("Ingrese algo: ");
        scanf("%d" , &algo);

        repetido = buscarAlgo(vec , tam , algo);

        if(repetido != -1)
        {
            printf("El %d ya fue ingresado en el sistema." , algo);
        }
        else
        {
            nuevoAlgo.algo = algo;
            nuevoAlgo.estado = 1;
            printf("Ingrese nombre: ");
            fflush(stdin);
            scanf("%s" , nuevoAlgo.nombre);

            vec[indice] = nuevoAlgo;
        }
    }

}


void baja(eC vec[] , int tam)
{
    int algo;
    int repetido;
    char confirmacion;

    printf("Ingrese x a eliminar: ");
    scanf("%d" , &algo);

    repetido = buscarAlgo(vec , tam , algo);

    if(repetido == -1)
    {
        printf("El %d nunca se ingreso en el sistema." , algo);
    }
    else
    {
        printf("Desea dar de baja %d? " , algo);
        fflush(stdin);
        scanf("%c" , &confirmacion);
        confirmacion = toupper(confirmacion);

        while(confirmacion != 'S' && confirmacion != 'N')
        {
            printf("No se ingreso 's' o 'n'. Reingrese.");
            fflush(stdin);
            scanf("%c" , &confirmacion);
            confirmacion = toupper(confirmacion);
        }

        if(confirmacion == 'S')
        {
            vec[repetido].estado = 0;
            printf("Baja existosa!");
        }
        else
        {
            printf("Se ha cancelado la baja.");
        }
    }
}


int menuModifica()
{
    int opcion;
    system("cls");
    printf("1-Algo\n");
    printf("2-Nombre.\n");
    printf("3-.\n");

    printf("Ingrese opcion: ");
    scanf("%d" , &opcion);

    return opcion;
}

void modificacion(eC vec[] , int tam)
{
    int algo;
    char salir = 's';
    int indice;
    char confirmacion;
    int repetido;
    eC nuevo;

    printf("Ingrese el x a modificar: ");
    scanf("%d" , &algo);

    indice = buscarAlgo(vec , tam , algo);

    if(indice == -1)
    {
        printf("El %d nunca fue ingresado en el sistema." , &algo);
    }
    else
    {
        printf("Esta seguro que desea cambiar alguno de estos datos? [s/n]");
        fflush(stdin);
        scanf("%c" , &confirmacion);
        confirmacion = toupper(confirmacion);

        if(confirmacion == 'S')
        {
            do
            {
                switch(menuModifica())
                {
                    case 1:
                        printf("Ingrese nuevo algo: ");
                        scanf("%d" , &nuevo.algo);
                        repetido = buscarAlgo(vec, tam , nuevo.algo);
                        if(repetido != -1)
                        {
                            printf("El %d ya fue ingresado." , nuevo.algo);
                        }
                        else
                        {
                            vec[indice].algo = nuevo.algo;
                        }
                    case 4:
                    salir = 'n';
                    break;
                }
            }
            while(salir == 's');
        }
    }
}

void mostrarDatos(eC vec[], int tam)
{
    int i;

    printf("ALGO:\tNOMBRE:\n");
    for(i=0 ; i < tam ; i++)
    {
        if(vec[i].estado == 1)
        {
            printf("%d\t%s\n" , vec[i].algo , vec[i].nombre);
        }
    }
}
