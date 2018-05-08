#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

void inicializar(EEmpleado emp[], int cantidad){
    int i;

    for(i=0; i<cantidad; i++){
        emp[i].isEmpty = 1;
    }
}

void hardCode(ESector sectores[]){
    ESector nuevoSector;

    nuevoSector.id = 1;
    strcpy(nuevoSector.descripcion, "RRHH");
    nuevoSector.isEmpty = 0;
    sectores[0] = nuevoSector;


    nuevoSector.id = 2;
    strcpy(nuevoSector.descripcion, "Sistemas");
    nuevoSector.isEmpty = 0;
    sectores[1] = nuevoSector;

    sectores[2].id = 3;
    strcpy(sectores[2].descripcion, "Administracion");
    sectores[2].isEmpty = 0;

    sectores[3].id = 4;
    strcpy(sectores[3].descripcion, "Compras");
    sectores[3].isEmpty = 0;

    sectores[4].id = 5;
    strcpy(sectores[4].descripcion, "Deposito");
    sectores[4].isEmpty = 0;

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


void alta(EEmpleado emp[], int cantidad){
    int i;

    for(i=0; i<cantidad; i++){
        if(emp[i].isEmpty == 1){
            printf("Legajo: ");
            scanf("%d", &emp[i].legajo);

            printf("Nombre: ");
            fflush(stdin);
            scanf("%s", emp[i].nombre);

            printf("Salario: ");
            scanf("%f", &emp[i].salario);

            printf("Dia: ");
            scanf("%d", &emp[i].fn.dia);

            printf("Mes: ");
            scanf("%d", &emp[i].fn.mes);

            printf("Año: ");
            scanf("%d", &emp[i].fn.anio);

            emp[i].isEmpty = 0;

            break;
        }
    }
}

void listar(EEmpleado emp[], int cantidad){
    int i;

    printf("Legajo\tNombre\t\t\tFechaNac\tSalario\n\n");

    for(i=0; i<cantidad; i++){
        if(emp[i].isEmpty == 0){
            printf("%d\t%s\t\t\t%d/%d/%d\t%.2f\n", emp[i].legajo, emp[i].nombre, emp[i].fn.dia, emp[i].fn.mes, emp[i].fn.anio, emp[i].salario);
        }
    }
}



