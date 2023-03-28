#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"


int main() {
    Pila main, auxiliar;
    int acumulador = 0;

    inicpila(&main);
    inicpila(&auxiliar);
    ///Esto es para obtener numeros aleatorios diferentes cada vez
    srand(time(NULL));

    ///Este FOR llena la pila con 10 numeros aleatorios
    for (int i = 0; i < 10; i++) {
        apilar(&main, rand());
    }

    ///En este while le sumo al acumulador el valor del tope de "main" y luego paso ese tope a la pila "auxiliar"
    while (!pilavacia(&main)) {
        acumulador = acumulador + tope(&main);
        apilar(&auxiliar, desapilar(&main));
    }
    ///Con este while devuelvo los valores de "auxiliar" a "main"
    while (!pilavacia(&auxiliar)) {
        apilar(&main, desapilar(&auxiliar));
    }

    ///Finalmente muestro la pila "main" y luego el valor de la suma
    mostrar(&main);
    printf("Suma de la pila = %d",acumulador);

    return 0;
}
