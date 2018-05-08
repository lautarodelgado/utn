

/**
 * \brief Solicita un número al usuario, compara si está entre los rangos permitidos y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado.
 * \param menor: es valor más pequeño que puede adquirir el número.
 * \param mayor: es el máximo valor que puede adquirir el número.
 * \param mientras el número no esté entre los rangos, vuelve a pedirlo.
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[] , int minimo , int maximo)
{
    int auxiliar;

    do
    {
        printf("%s" , mensaje);
        scanf("%d" , &auxiliar);
    }
    while(auxiliar < minimo || auxiliar > maximo);

    return auxiliar;
}


/**
 * \brief Solicita un número real al usuario, compara si está entre los rangos permitidos y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado.
 * \param menor: es valor más pequeño que puede adquirir el número.
 * \param mayor: es el máximo valor que puede adquirir el número.
 * \param mientras el número no esté entre los rangos, vuelve a pedirlo.
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje [] , int minimo , int maximo)
{
    float auxiliar;

    do
    {
        printf("%s" , mensaje);
        scanf("%f" , &auxiliar);
    }
    while(auxiliar < minimo || auxiliar > maximo);

    return auxiliar;
}

