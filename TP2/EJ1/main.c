#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"


int main() {
    Pila main, auxiliar;
    int acumulador = 0;

    inicpila(&main);
    inicpila(&auxiliar);
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        apilar(&main, rand());
    }

    while (!pilavacia(&main)) {
        acumulador = acumulador + tope(&main);
        apilar(&auxiliar, desapilar(&main));
    }
    while (!pilavacia(&auxiliar)) {
        apilar(&main, desapilar(&auxiliar));
    }

    mostrar(&main);
    printf("Suma de la pila = %d",acumulador);

    return 0;
}
