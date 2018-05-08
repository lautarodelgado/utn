#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edad;
    int r; // Respuesta
    r = getInt(&edad,"¿Cual es tu edad?","Rango valido [0 - 100]",1,100);
    if(r == 0)
    printf("La edad es: %d",edad);
    printf("Hello world!\n");
    return 0;
}
