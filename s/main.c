#include <stdio.h>
#include <stdlib.h>

int getInt(char[] , int);

int main()
{
    char dato[15];

    printf("Ingrese numero: ");
    fflush(stdin);
    scanf("%s" , dato);
    getInt(dato , 15);

    return 0;
}

int getInt(char la[] , int tam)
{
    int i;
    int flag = 0;
    int nro;
    for(i=0 ; i < strlen(la) ; i++)
    {
        if(!isdigit(la[i]))
        {
            flag = 1;

            while(flag == 1)
            {
                flag = 0;
                printf("ERROR. Reingrese numero: ");
                fflush(stdin);
                scanf("%s" , la);

                for(i=0 ; i < strlen(la) ; i++)
                {
                    if(!isdigit(la[i]))
                    {
                        flag = 1;
                    }
                }
            }
        }
    }

    if(flag == 0)
    {
        nro = atoi(la);
        if(nro < 0 || nro > 100000000)
        {
            printf("Reingrese: ");
            scanf("%d" , &nro);
        }
    }

    printf("%d" , nro);

}
