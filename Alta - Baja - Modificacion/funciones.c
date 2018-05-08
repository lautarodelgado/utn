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
            listarUno(emp[esta]);
            //break;
        }
        else
        {
            nuevoEmplead.isEmpty = 0;
            nuevoEmplead.legajo = legajo;

            printf("NOMBRE: ");
            fflush(stdin);
            scanf("%[^\n]" , nuevoEmplead.nombre);

            printf("SEXO: ");
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

            printf("ID: ");
            scanf("%d" , &nuevoEmplead.idSector);

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

                    printf("A�o: ");
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

            printf("A�o: ");
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

    printf("Legajo:\tNombre:\tSexo:\tFechaIng:\tSalario:\tSector:\n\n");

    for(i=0; i < tam; i++)
    {
        if(emp[i].isEmpty == 0)
        {
            printf("%d\t%s\t%c\t%d/%d/%d\t\t%.2f\t\t%d\n", emp[i].legajo, emp[i].nombre, emp[i].sexo, emp[i].fechaIngreso.dia, emp[i].fechaIngreso.mes, emp[i].fechaIngreso.anio, emp[i].sueldo , emp[i].idSector);
        }
    }
}



void listarUno(eEmpleado emp)
{

    printf("Legajo:\tNombre:\tSexo:\tFechaIng:\tSalario:\tID:\n\n");
    if(emp.isEmpty == 0)
    {
        printf("%d\t%s\t%c\t%d/%d/%d\t\t%.2f\t\t%d\n", emp.legajo, emp.nombre, emp.sexo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio, emp.sueldo , emp.idSector);
    }

}



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


void hardCode(eSector sectores[]){
    eSector nuevoSector;

    nuevoSector.id = 1;
    strcpy(nuevoSector.descripcion, "RRHH");
    nuevoSector.isEmpty = 0;
    sectores[0] = nuevoSector;

    nuevoSector.id = 2;
    strcpy(nuevoSector.descripcion, "Sistemas");
    nuevoSector.isEmpty = 0;
    sectores[1] = nuevoSector;

    nuevoSector.id = 3;
    strcpy(nuevoSector.descripcion, "Administracion.");
    nuevoSector.isEmpty = 0;
    sectores[2] = nuevoSector;

    nuevoSector.id = 4;
    strcpy(nuevoSector.descripcion, "Compras.");
    nuevoSector.isEmpty = 0;
    sectores[3] = nuevoSector;

    nuevoSector.id = 5;
    strcpy(nuevoSector.descripcion, "Deposito.");
    nuevoSector.isEmpty = 0;
    sectores[4] = nuevoSector;



    /*
    sectores[0].id = 1;
    strcpy(sectores[0].descripcion, "RRHH");
    sectores[0].isEmpty = 0;

    sectores[1].id = 2;
    strcpy(sectores[1].descripcion, "Sistemas");
    sectores[1].isEmpty = 0;

    sectores[2].id = 3;
    strcpy(sectores[2].descripcion, "Administracion");
    sectores[2].isEmpty = 0;

    sectores[3].id = 4;
    strcpy(sectores[3].descripcion, "Compras");
    sectores[3].isEmpty = 0;

    sectores[4].id = 5;
    strcpy(sectores[4].descripcion, "Deposito");
    sectores[4].isEmpty = 0;
    */
}

/*
int menu()
{
    int opcion;

    system("cls");
    printf("LEGAJO:");
    printf("NOMBRE:");
    printf("SEXO:");
    printf("SUELDO:");
    printf("DIA:");
    printf("MES:");
    printf("ANIO:");
    printf("ID:");

    printf("Elija lo que quiere cambiar: ");
    scanf("%d" , &opcion);
}

*/

