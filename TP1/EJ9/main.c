#include <stdio.h>
#include "pila.h"

#define PROMPT "Ingrese un valor entero: "

int main() {

    Pila pilaA, pilaB;

    inicpila(&pilaA);
    inicpila(&pilaB);

    int numeroIngresado;
    int scanResult;

    printf("Cargando PILA A\n");
    printf(PROMPT);
    scanResult = scanf("%d", &numeroIngresado);

    while (scanResult != 0) {
        apilar(&pilaA, numeroIngresado);
        printf(PROMPT);
        scanResult = scanf("%d", &numeroIngresado);
    }
    printf("PILA A cargada.\nCargando PILA B\n");

    fflush(stdin);

    printf(PROMPT);
    scanResult = scanf("%d", &numeroIngresado);

    while (scanResult != 0) {
        apilar(&pilaB, numeroIngresado);
        printf(PROMPT);
        scanResult = scanf("%d", &numeroIngresado);
    }
    printf("PILA B cargada.\nProcesando...");

    if (!pilavacia(&pilaA) && !pilavacia(&pilaB)) {
        while (!pilavacia(&pilaA) && !pilavacia(&pilaB)) {
            desapilar(&pilaA);
            desapilar(&pilaB);
            if (pilavacia(&pilaA)) {
                if (pilavacia(&pilaB)) {
                    printf("Ambas pilas tienen la misma longitud");
                } else {
                    printf("La pila A es mas corta que la pila B");
                }
            } else if (pilavacia(&pilaB)) {
                printf("La pila B es mas corta que la pila A");
            }
        }
    } else {
        printf("Una de las pilas esta vacia");
    }

    return 0;
}
