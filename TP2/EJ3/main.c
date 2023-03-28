#include <stdio.h>
#include <time.h>
#include "pila.h"

int main() {
    Pila main, auxiliar;
    int acumulador = 0;
    int contador = 0;

    inicpila(&main);
    inicpila(&auxiliar);
    srand(time(NULL));

    for (int i = 0; i < 25; i++) {
        apilar(&main, rand());
    }

    while (!pilavacia(&main)) {
        acumulador = acumulador + tope(&main);
        contador++;
        apilar(&auxiliar, desapilar(&main));
    }
    while (!pilavacia(&auxiliar)) {
        apilar(&main, desapilar(&auxiliar));
    }

    if (contador != 0) {
        printf("La cantidad de elementos es: %d\n",contador);
        printf("La suma de elementos vale: %d\n",acumulador);
        printf("El promedio es: %0.2f", (float) acumulador / (float) contador);
    } else {
        printf("La pila esta vacia");
    }

    return 0;
}
