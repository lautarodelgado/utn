

/**
 * \brief Solicita un n�mero al usuario, compara si est� entre los rangos permitidos y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado.
 * \param menor: es valor m�s peque�o que puede adquirir el n�mero.
 * \param mayor: es el m�ximo valor que puede adquirir el n�mero.
 * \param mientras el n�mero no est� entre los rangos, vuelve a pedirlo.
 * \return El n�mero ingresado por el usuario
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
 * \brief Solicita un n�mero real al usuario, compara si est� entre los rangos permitidos y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado.
 * \param menor: es valor m�s peque�o que puede adquirir el n�mero.
 * \param mayor: es el m�ximo valor que puede adquirir el n�mero.
 * \param mientras el n�mero no est� entre los rangos, vuelve a pedirlo.
 * \return El n�mero ingresado por el usuario
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

