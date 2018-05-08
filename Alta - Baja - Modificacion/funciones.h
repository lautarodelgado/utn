#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//ESTRUCTURAS:
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[51];
    char sexo;
    float sueldo;
    int isEmpty;
    eFecha fechaIngreso;
    int idSector;
}eEmpleado;

typedef struct
{
    int id;
    char descripcion[51];
    int isEmpty;
}eSector;

//FUNCIONES:
//GENERA MENU:
int menu();

int menuModificacion();
//INICIALIZA INDICES EN 1 (PARA QUE ESTEN VACIOS)
void inicializarEmpleados(eEmpleado[] , int);
//BUSCA UN INDICE VACIO
int buscarLibre(eEmpleado[] , int);
//AGREGA UN EMPLEADO
void alta(eEmpleado[], int);
//IMPRIME LOS DATOS DE LOS EMPLEADOS
void listar(eEmpleado[], int);

void listarUno(eEmpleado);
//BUSCA UN EMPLEADO POR NUMERO DE LEGAJO
int buscarEmpleado(eEmpleado[] , int , int);
//BAJA:
void bajaPorLegajo(eEmpleado[] , int);

void hardCode(eSector[]);



#endif // FUNCIONES_H_INCLUDED

