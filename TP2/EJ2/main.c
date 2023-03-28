#include <stdio.h>
#include <time.h>
#include "pila.h"

int main() {
    Pila main, auxiliar;
    ///Elegi 35 elementos por que si
    int contador = 0;

    inicpila(&main);
    inicpila(&auxiliar);

    ///Esto es para obtener numeros aleatorios diferentes cada vez
    srand(time(NULL));
    int cantidad = rand();

    ///En este FOR lleno la pila con numeros aleatorios
    for (int i = 0; i < cantidad; i++) {
        apilar(&main, rand());
    }

    ///En este while cada vez que paso un elemento de "main" a "auxiliar" le sumo 1 al contador (asi cuento)
    while (!pilavacia(&main)) {
        apilar(&auxiliar, desapilar(&main));
        contador++;
    }

    ///Devuelvo los valores de "auxiliar" a "main"
    while (!pilavacia(&auxiliar)) {
        apilar(&main, desapilar(&auxiliar));
    }

    ///Muestro la cantidad original y la contada para verificar
    printf("La cantidad de elementos era: %d\n",cantidad);
    printf("La cantidad contada es: %d",contador);

    return 0;
}
