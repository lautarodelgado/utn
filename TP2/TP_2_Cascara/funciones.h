#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

void inicializarLibre(ePersona [] , int tam);

void agregarPersona(ePersona[] , int);

void mostrarDato(ePersona);

void mostrarPersonas(ePersona[] , int tam);

void ordenarPorNombre(ePersona[] , int tam);

void borrarPersona(ePersona[] , int);

void graficoEdades(ePersona[] , int);



/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[] , int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int tam ,int dni);

#endif // FUNCIONES_H_INCLUDED
