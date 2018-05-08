#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct
{
    char pantalla[10];
    char nombre[20];
    char direccion[41];
    float precio;
    int estado;
    int id;

} ePantalla;

typedef struct
{
    int idPantalla;
    int idPublicidad;
    int cuit;
    int dias;
    char nombreArchivo[41];
    int estado;
}ePublicidad;


int menu();
void inicializarPantalla(ePantalla[], int);
void mostrarPantallas(ePantalla[], int);
void mostrarPantalla(ePantalla);
int buscarLibre(ePantalla[], int);
void altaPantalla(ePantalla vec[], int tam);
int buscarPantalla(ePantalla[], int, int);
void bajaPantalla(ePantalla[], int);
void modificaPantalla(ePantalla[], int);
int menuModifica();

void altaPublicidad(ePublicidad[] , int , ePantalla[] ,int);

void inicializarPublicidad(ePublicidad[], int);

int indicePublicidad(ePublicidad[] , int);

void mostrarPantallasYPublicidades(ePantalla[] , int ,  ePublicidad[] , int);

void modificarDias(ePublicidad[] , int);

int buscarCuit(ePublicidad[] , int , int);

void modificarPublicacion(ePublicidad[] , int , ePantalla[] , int);

void mostrarPublicidadesCuit(ePublicidad[] , int , ePantalla[] , int , int);

int buscarIdPantalla(ePublicidad[] , int , int);

void cancelarContratacion(ePublicidad[] , int , ePantalla[] , int);







#endif // FUNCIONES_H_INCLUDED

