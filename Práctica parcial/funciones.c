#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu()
{
    int opcion;

    system("cls");
    printf("---ABM Pantallas---\n\n");
    printf("1-Alta\n");
    printf("2-Baja\n");
    printf("3-Modificar\n");
    printf("4-Listar\n");
    printf("5-Alta publicidad.\n");
    printf("6-Listar pantallas con publicidades.\n");
    printf("7-Modificar punlicacion.\n");
    printf("8-Cancelar contratacion.\n");
    printf("9-Salir\n");
    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarPantalla (ePantalla vec[], int tam)
{
    int i;

    for(i=0; i< tam; i++)
    {
        vec[i].estado = 0;
    }
}



void mostrarPantallas(ePantalla vec[], int tam)
{
    int i;

    system("cls");
    printf("---Lista de Pantallas---\n\n");
    printf("ID:\t\tPantalla:\tNombre:\tDireccion: \n\n");
    for(i=0; i< tam; i++)
    {
        if(vec[i].estado == 1)
        {
            printf("%d\t\t%s\t\t%s\t\t%s\n" , vec[i].id , vec[i].pantalla , vec[i].nombre , vec[i].direccion);
        }
    }
}


/*
void mostrarPantalla(ePantalla emp)
{
    printf("  %4d     %s     %c  %10.2f    %02d/%02d/%4d \n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio );
}
*/

int buscarLibre(ePantalla vec[], int tam)
{
    int indice = -1;
    int i;

    for(i=0; i < tam; i++)
    {
        if(vec[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarPantalla(ePantalla vec[], int tam, int id)
{
    int indice = -1;
    int i;

    for(i=0; i < tam; i++)
    {
        if(vec[i].estado !=0 && vec[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void altaPantalla(ePantalla vec[], int tam)
{

    ePantalla nuevaPantalla;
    int indice;

    system("cls");
    printf("---Alta Pantalla---\n\n");

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a pantallas nuevos.\n\n");
    }
    else
    {
        nuevaPantalla.id = indice + 1;

        nuevaPantalla.estado = 1;

        printf("Ingrese el tipo de pantalla (LCD o LED)");
        fflush(stdin);
        gets(nuevaPantalla.pantalla);
        while(strcmp("LCD" , nuevaPantalla.pantalla) != 0 && strcmp("LED" , nuevaPantalla.pantalla) != 0)
        {
            printf("No es un tipo de pantalla valido. Reingrese.");
            gets(nuevaPantalla.pantalla);
        }

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nuevaPantalla.nombre);

        printf("Ingrese direccion: ");
        fflush(stdin);
        gets(nuevaPantalla.direccion);

        vec[indice] = nuevaPantalla;

        printf("\nSu ID es %d. Alta exitosa!!!\n\n" , nuevaPantalla.id);

    }


}


void bajaPantalla(ePantalla vec[], int tam)
{
int id;
int esta;
char confirma;

system("cls");
printf("---Baja Pantalla---\n\n");

   printf("Ingrese id: ");
        scanf("%d", &id);

        esta = buscarPantalla(vec, tam, id);

        if(esta == -1)
        {
            printf("\nEl id %d no se encuentra en el sistema\n\n", id);

        }

        else
        {

                //mostrarEmpleado(vec[esta]);

            do
            {
                printf("\nConfirma baja? [s|n]: ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
            }
            while(confirma != 's' && confirma != 'n');

            if(confirma == 's')
            {
                vec[esta].estado = 0;
                printf("\nSe ha realizado la baja\n\n");
            }
            else
            {
                printf("\nSe ha cancelado la baja\n\n");
            }

        }
}



void modificaPantalla(ePantalla vec[], int tam){
    ePantalla nuevaPantalla;
    int id;
    int esta;
    char confirma;
    int salir = 0;

    system("cls");
    printf("---Modificar Pantalla---\n\n");

    printf("Ingrese id: ");
        scanf("%d", &id);

        esta = buscarPantalla(vec, tam, id);

        if(esta == -1)
        {
            printf("\nEl id %d no se encuentra en el sistema\n\n", id);

        }
        else{

                //mostrarEmpleado(vec[esta]);

        do{
            printf("\nConfirma modificacion? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }while(confirma != 's' && confirma != 'n');

        if(confirma == 's')
        {
            do
            {
                switch(menuModifica())
                {
                    case 1:
                        printf("Ingrese el nuevo tipo de pantalla: ");
                        gets(nuevaPantalla.pantalla);
                        strcpy(vec[esta].pantalla , nuevaPantalla.pantalla);
                        break;
                    case 2:
                        printf("Ingrese el nuevo nombre: ");
                        fflush(stdin);
                        gets(nuevaPantalla.nombre);
                        strcpy(vec[esta].nombre , nuevaPantalla.nombre);
                        break;
                    case 3:
                        printf("Ingrese la nueva direccion: ");
                        fflush(stdin);
                        gets(nuevaPantalla.direccion);
                        strcpy(vec[esta].direccion , nuevaPantalla.direccion);
                        break;
                    case 7:
                        salir = 1;
                        break;
                }

            }
            while(salir != 1);
            printf("\nSe ha realizado la modificacion\n\n");
            }
            else
            {
                printf("\nSe ha cancelado la modificacion\n\n");
            }
        }
}


int menuModifica()
{
    int opcion;

    system("cls");
    printf("---Modificar Empleados---\n\n");
    printf("1-Pantalla.\n");
    printf("2-Nombre.\n");
    printf("3-Direccion.\n");
    printf("7-Salir\n");
    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}



void altaPublicidad(ePublicidad pub[] , int tama , ePantalla pant[] , int tam)
{
    int indice;
    int pantalla;
    int id;
    ePublicidad publicidad;


    indice = indicePublicidad(pub , tama);

    if(indice == -1)
    {
        printf("No se pueden ingresar mas publicidades.");
        system("pause");
    }
    else
    {
        publicidad.estado = 1;
        printf("Ingrese el ID de la pantalla a agregar publicidad: ");
        scanf("%d" , &publicidad.idPantalla);

        pantalla = buscarPantalla(pant , tam , publicidad.idPantalla);

        if(pantalla == -1)
        {
            printf("El id de la pantalla no existe en el sistama.");
        }
        else
        {
            publicidad.idPublicidad = indice + 1;
            printf("Ingrese cuit: ");
            scanf("%d" , &publicidad.cuit);

            printf("Ingrese dias: ");
            scanf("%d" , &publicidad.dias);

            printf("Ingrese nombre del archivo: ");
            fflush(stdin);
            gets(publicidad.nombreArchivo);

            pub[indice] = publicidad;
        }
    }


}


void inicializarPublicidad(ePublicidad pub[] , int tamanio)
{
    int i;
    for(i=0 ; i < tamanio ; i++)
    {
        pub[i].estado = 0;
    }
}

int indicePublicidad(ePublicidad pub[] , int tamanio)
{
    int indice = -1;
    int i;

    for(i=0 ; i < tamanio ; i++)
    {
        if(pub[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void mostrarPantallasYPublicidades(ePantalla vec[] , int tam , ePublicidad pub[] , int tamanio)
{
    int i;
    int j;

    printf("PANTALLA:\tID PUBLICIDAD:\tNOMBRE:\n");
    for(i=0 ; i < tam ; i++)
    {
        for(j=0 ; j < tamanio ; j++)
        {
            if( vec[i].id == pub[j].idPantalla && vec[i].estado == 1 && pub[j].estado == 1)
            {
                //contador = contador + 1;
                //printf("si");
                //pub[j].idPublicidad++;
                printf("%d\t\t%d\t%s\n" , pub[j].idPantalla , pub[j].idPublicidad , pub[j].nombreArchivo);
                //printf("%d-%s\n" , pub[j].idPublicidad , pub[j].nombreArchivo);
            }
        }
    }
}


void modificarDias(ePublicidad vec[] , int tamanio)
{
    ePantalla nuevaPantalla;
    int cuit;

}


int buscarCuit(ePublicidad vec[] , int tamanio , int cuit)
{
    int i;
    int cuitExistente = -1;

    for(i=0 ; i < tamanio ; i++)
    {
        if(cuit == vec[i].cuit && vec[i].estado == 1)
        {
            cuitExistente = i;
        }
    }

    return cuitExistente;
}

void mostrarPublicidadesCuit(ePublicidad vec[] , int tamanio , ePantalla pan[] , int tam , int cuit)
{
    int i;

    printf("DIAS:\tCUIT:\tPANTALLA:\tID PUBLICIDAD:\tNOMBRE:\n");

    for(i=0 ; i < tamanio ; i++)
    {
        if( cuit == vec[i].cuit && vec[i].estado == 1)
        {
            //contador = contador + 1;
            //printf("si");
            //pub[j].idPublicidad++;
            printf("%d\t%d\t%d\t\t%d\t%s\n" , vec[i].dias , cuit , vec[i].idPantalla , vec[i].idPublicidad , vec[i].nombreArchivo);
            //printf("%d-%s\n" , pub[j].idPublicidad , pub[j].nombreArchivo);
        }
    }
}

int buscarIdPantalla(ePublicidad vec[] , int tam , int idPantalla)
{
    int i;
    int pantalla = -1;

    for(i=0 ; i < tam ; i++)
    {
        if(idPantalla == vec[i].idPantalla && vec[i].estado == 1)
        {
            pantalla = i;
            break;
        }
    }
    return pantalla;
}


void modificarPublicacion(ePublicidad vec[] , int tamanio , ePantalla pan[] , int tam)
{
    ePublicidad pub;
    int i;
    int cuitExistente;
    int pantallaExistente;
    char respuesta;

    printf("Ingrese su cuit: ");
    scanf("%d" , &pub.cuit);

    cuitExistente = buscarCuit(vec , tamanio , pub.cuit);

    if(cuitExistente == -1)
    {
        printf("El cuit %d nunca se ingreso en el sistema." , pub.cuit);
    }
    else
    {
        mostrarPublicidadesCuit(vec , tamanio , pan , tam , pub.cuit);

        printf("Ingrese el ID de la pantalla con los datos a cambiar: ");
        scanf("%d" , &pub.idPantalla);

        pantallaExistente = buscarIdPantalla(vec , tamanio , pub.idPantalla);

        if(pantallaExistente == -1)
        {
            printf("La pantalla nunca se ingreso en el sistema.");
        }
        else
        {
            printf("Los dias contratados son %d\n" , vec[pantallaExistente].dias);
            printf("Desea modificar los dias contratados?");
            fflush(stdin);
            scanf("%c" , &respuesta);

            if(respuesta == 's')
            {
                printf("Ingrese la nueva cantidad de dias: ");
                scanf("%d" , &pub.dias);

                vec[pantallaExistente].dias = pub.dias;
            }
            else
            {
            }
        }
    }

}

void cancelarContratacion(ePublicidad vec[] , int tam , ePantalla pan[] , int tamanio)
{
    int cuitIngresado;
    ePublicidad pub;
    int idPantallaExistente;
    char respuesta;

    printf("Ingrese el cuit con las contrataciones a eliminar: ");
    scanf("%d" , &pub.cuit);

    cuitIngresado = buscarCuit(vec , tam , pub.cuit);

    if(cuitIngresado == -1)
    {
        printf("El cuit nunca fue ingresado.");
    }
    else
    {
        mostrarPublicidadesCuit(vec , tam , pan , tamanio , pub.cuit);

        printf("Ingrese el id de la publicidad a dar de baja: ");
        scanf("%d" , &pub.idPantalla);

        idPantallaExistente = buscarIdPantalla(vec , tam , pub.idPantalla);

        if(idPantallaExistente == -1)
        {
            printf("El id de publicidad no existe.");
        }
        else
        {
            printf("Desea dar de baja la publicidad %d" , vec[idPantallaExistente].idPublicidad);
            fflush(stdin);
            scanf("%c" , &respuesta);

            if(respuesta == 's')
            {
                pub.estado = 0;
                vec[idPantallaExistente].estado = pub.estado;
            }
            else
            {

            }
        }
    }
}

