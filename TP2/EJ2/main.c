#include <stdio.h>
#include <time.h>
#include "pila.h"

int main() {
    Pila main, auxiliar;
    int cantidad = 35;
    int contador = 0;

    inicpila(&main);
    inicpila(&auxiliar);
    srand(time(NULL));

    for (int i = 0; i < cantidad; i++) {
        apilar(&main, rand());
    }

    while (!pilavacia(&main)) {
        apilar(&auxiliar, desapilar(&main));
        contador++;
    }

    while (!pilavacia(&auxiliar)) {
        apilar(&main, desapilar(&auxiliar));
    }

    printf("La cantidad de elementos era: %d\n",cantidad);
    printf("La cantidad contada es: %d",contador);

    return 0;
}
