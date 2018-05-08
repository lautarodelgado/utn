#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    float numero2;

    numero = getInt("Ingrese un numero: " , 0 , 100000000000);
    printf("%d" , numero);

    numero2 = getFloat("Ingrese un numero real: " , 0 , 10000000);
    printf("%.2f" , numero2);

    return 0;
}


