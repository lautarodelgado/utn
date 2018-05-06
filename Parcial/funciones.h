#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//ESTRUCTURAS:
typedef struct
{
    int algo;
    char nombre[100];
    int legajo;
    int estado;
}eC;

typedef struct
{
    int idSector;
}eCC;


//FUNCIONES:
int menu();

void inicializar (eC [] , int);

int buscarLibre(eC [] , int);

void alta(eC [] , int);

int buscarAlgo(eC [] , int , int);

void baja(eC [] , int);

int menuModifica();

void modificacion(eC [] , int);

void mostrarDatos(eC [], int);





#endif // FUNCIONES_H_INCLUDED
