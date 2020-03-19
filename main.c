#include <stdio.h>
int i, j, longitud;

// Pedro Antonio Estévez Pérez

// Ejercicio 5

/* Diseñe una función en C que reciba un vector de números reales, v,
 * y devuelva la media, moda y mediana de sus elementos.*/

float media(float *vector,int longitud) // La suma no tiene ningún misterio
{
    float suma = 0;
    for (i=0; i<longitud; i++)
    {
        suma = suma + (*(vector+i));
    }
    float salida = suma / longitud;
    return salida;
}

float moda(float *vector,int longitud)
{
    /* La moda es simple de calcular en todos los casos menos uno.
     * Si tenemos más de un elemento con las mismas repeticiones. Lo que haré
     * será recorrer el vector y almacenar el numero de repeticiones en otro vector.
     * Luego lo recorreré para ver el mayor elemento. En el caso de que haya dos
     * elementos con las mismas repeticiones, si por ejemplo son 2, habrá 4 doses,
     * lo que significa que hay dos elementos con dos repeticiones y por tanto,
     * no hay moda. Esto es generalizable.*/

    int i, j, contador=0, salida, mayor;
    int repeticiones[500];

    for (i=0; i<longitud; i++)
    {
        for (j=0; j<longitud; j++)
        {
            if ((*(vector+i)) == (*(vector+j)))
               contador++;
        }
         repeticiones[i] = contador;
         contador = 0;
    }

    contador = 0;
    mayor = 1;
    salida = 0;
    for (i=0; i<longitud; i++)
    {
        if (repeticiones[i] > mayor)
        {
            mayor = repeticiones[i];
            salida = *(vector+i);
        }
        if (repeticiones[i] == mayor) // Esto resuelve el caso especial
        {
            contador++;
            if (contador == repeticiones[i] * 2)
                salida = 0;
        }
    }

    return salida;
}

float mediana(float *vector,int longitud)
{
    /* Para calcular la mediana, lo primero es ordenar el vector de menor a mayor.
     * El método que he usado es propio, es algo intermedio entre el de selección
     * y el de inserción. Una vez tenemos el vector ordenado, solo hay que ver si
     * es par o impar y operar*/

    int posicion, entrada=0, menor;
    float salida;

    for (i=0; i<longitud-1; i++)
    {
        menor = (*(vector+i));
        for (j=i+1; j<longitud; j++)
        {
            if ((*(vector+j)) < menor)
            {
                menor = (*(vector+j));
                posicion = j;
                entrada = 1;
            }
        }
        if (entrada == 1)
        {
            (*(vector+posicion)) = (*(vector+i));
            *(vector+i) = menor;
            entrada = 0;
        }
    }
    if (longitud%2 == 0)
    {
        return salida = ((*(vector+(longitud/2-1))) + (*(vector+(longitud/2))))/2;
    }
    else
    {
        int aux = longitud/2;
        return salida = *(vector+aux);
    }
}

float main(void)
{
    /* Introduciremos los datos y haremos tres llamadas a funciones para
     * resolver el ejercicio. Se puede hacer sin punteros, pero lo empecé a
     * hacer después de verlos, así que lo he resuelto con ellos
     * simplemente por praticarlos.*/

    while (1)
    {
        printf("Introduce la longitud del vector: ");
        scanf("%d", &longitud);
        if (longitud <= 0)
            printf("Introduce un numero valido.\n");
        else
            break;
    }

    float vector[longitud]; // Creamos el vector
    float *pvector;         // Creamos el puntero
    pvector = &vector[0];   // Los unimos

    for (i=0; i<longitud; i++)
    {
        printf("Introduce el elemento %d: ", i);
        scanf("%f", &(*(pvector+i)));
    }

    float salida_media = media(pvector,longitud);
    float salida_moda = moda(pvector,longitud);
    float salida_mediana = mediana(pvector,longitud);

    printf("La media es: %f\n", salida_media);
    if (salida_moda == 0)
        printf("No hay moda\n");
    else
        printf("La moda es: %f\n", salida_moda);
    printf("La mediana es: %f\n\n", salida_mediana);
}
