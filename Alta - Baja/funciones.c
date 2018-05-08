#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int menu()
{
    int opcion;
    system("cls");
    printf("1 - ALTA.\n");
    printf("2 - BAJA.\n");
    printf("3 - MODIFICACION.\n");
    printf("4 - LISTAR.\n");
    printf("5 - ORDENAR.\n");
    printf("6 - SALIR.\n");

    printf("\nElija lo que quiere hacer: ");
    scanf("%d" , &opcion);

    return opcion;
}

void inicializarEmpleados(eEmpleado emp[] , int tam)
{
    int i;

    for(i=0 ; i < tam ; i++)
    {
        emp[i].isEmpty = 1;
    }
}


int buscarLibre(eEmpleado emp[] , int tam)
{
    int i;
    int indiceVacio = -1;

    for(i=0 ; i < tam ; i++)
    {
        if(emp[i].isEmpty == 1)
        {
            indiceVacio = i;
            break;
        }
    }

    return indiceVacio;
}



void alta(eEmpleado emp[], int tam)
{
    eEmpleado nuevoEmplead;
    int indice;
    int legajo;
    int esta;

    indice = buscarLibre(emp , tam);

    if(indice == -1)
    {
        printf("LLENO.");
    }
    else
    {
        printf("LEGAJO: ");
        scanf("%d" , &legajo);

        esta = buscarEmpleado(emp , tam , legajo);
        if(esta != -1)
        {
            printf("Dado de alta.\n");
            //listarUno(emp[esta]);
            //break;
        }
        else
        {
            nuevoEmplead.isEmpty = 0;
            nuevoEmplead.legajo = legajo;

            printf("NOMBRE: ");
            fflush(stdin);
            scanf("%[^\n]" , nuevoEmplead.nombre);

            printf("SEXO:");
            fflush(stdin);
            scanf("%c" , &nuevoEmplead.sexo);

            printf("SUELDO: ");
            scanf("%f" , &nuevoEmplead.sueldo);

            printf("DIA: ");
            scanf("%d" , &nuevoEmplead.fechaIngreso.dia);

            printf("MES: ");
            scanf("%d" , &nuevoEmplead.fechaIngreso.mes);

            printf("ANIO: ");
            scanf("%d" , &nuevoEmplead.fechaIngreso.anio);

            emp[indice] = nuevoEmplead;

        }
    }

    /*for(i=0 ; i < tam ; i++)
    {
        libre = buscarLibre(emp , tam);
        if(libre == -1)
        {
            printf("Lleno");
        }
        else
        {
            printf("Legajo: ");
            scanf("%d" , &legajo);

            leg = buscarEmpleado(emp , tam , legajo);
            {
                if(leg != -1)
                {
                    printf("El legajo ya existe");
                    break;
                }
                else
                {
                    emp[i].isEmpty = 0;
                    emp[i].legajo = legajo;


                    printf("Nombre: ");
                    fflush(stdin);
                    scanf("%s", emp[i].nombre);

                    printf("Salario: ");
                    scanf("%f", &emp[i].sueldo);

                    printf("Sexo: ");
                    fflush(stdin);
                    scanf("%c" , &emp[i].sexo);

                    printf("Dia: ");
                    scanf("%d", &emp[i].fechaIngreso.dia);

                    printf("Mes: ");
                    scanf("%d", &emp[i].fechaIngreso.mes);

                    printf("Año: ");
                    scanf("%d", &emp[i].fechaIngreso.anio);
                    break;
                }
            }
        }

    }

    /*
    for(i=0; i<tam; i++)
    {
        if(emp[i].isEmpty == 1)
        {

            printf("Legajo: ");
            scanf("%d", &emp[i].legajo);

            printf("Nombre: ");
            fflush(stdin);
            scanf("%s", emp[i].nombre);

            printf("Salario: ");
            scanf("%f", &emp[i].sueldo);

            printf("Sexo: ");
            fflush(stdin);
            scanf("%c" , &emp[i].sexo);

            printf("Dia: ");
            scanf("%d", &emp[i].fechaIngreso.dia);

            printf("Mes: ");
            scanf("%d", &emp[i].fechaIngreso.mes);

            printf("Año: ");
            scanf("%d", &emp[i].fechaIngreso.anio);

            emp[i].isEmpty = 0;

            break;
        }
    }
    */
}


void listar(eEmpleado emp[], int tam)
{
    int i;

    printf("Legajo:\tNombre:\tSexo:\tFechaIng:\tSalario:\n\n");

    for(i=0; i < tam; i++)
    {
        if(emp[i].isEmpty == 0)
        {
            printf("%d\t%s\t%c\t%d/%d/%d\t\t%.2f\n", emp[i].legajo, emp[i].nombre, emp[i].sexo, emp[i].fechaIngreso.dia, emp[i].fechaIngreso.mes, emp[i].fechaIngreso.anio, emp[i].sueldo);
        }
    }
}


/*
void listarUno(eEmpleado emp[])
{
    eEmpleado nuevoEmpleado;
    printf("Legajo:\tNombre:\tSexo:\tFechaIng:\tSalario:\n\n");
    if(nuevoEmpleado.isEmpty == 0)
    {
        printf("%d\t%s\t%c\t%d/%d/%d\t\t%.2f\n", nuevoEmpleado.legajo, nuevoEmpleado.nombre, nuevoEmpleado.sexo, nuevoEmpleado.fechaIngreso.dia, nuevoEmpleado.fechaIngreso.mes, nuevoEmpleado.fechaIngreso.anio, nuevoEmpleado.sueldo);
    }

}
*/


int buscarEmpleado(eEmpleado emp[] , int tam , int legajo)
{
    int i;
    //int legajoIngresado;
    int legajoIndice = -1;

    //printf("Ingrese un legajo a buscar: ");
    //scanf("%d" , &legajoIngresado);

    for(i=0 ; i < tam ; i++)
    {
        if(legajo == emp[i].legajo)
        {
            legajoIndice = i;
            break;
        }
    }
    return legajoIndice;
}


void bajaPorLegajo(eEmpleado emp[] , int tam)
{
    eEmpleado nuevoEmpleado;
    int legajo;
    int legajoBaja = -1;
    printf("Legajo del empleado a dar de baja: ");
    scanf("%d" , &legajo);

    legajoBaja = buscarEmpleado(emp , tam , legajo);

    if(legajoBaja == -1)
    {
        printf("El legaja %d nunca fue ingresado en el sistema," , legajo);
    }
    else
    {
        nuevoEmpleado.isEmpty = 1;
        emp[legajoBaja] = nuevoEmpleado;
        printf("Baja exitosa.");
    }
}
