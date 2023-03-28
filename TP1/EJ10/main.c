#include <stdio.h>
#include "pila.h"

#define PROMPT "Ingrese un entero: "

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
            if (desapilar(&pilaA) != desapilar(&pilaB)) {
                printf("Las pilas tienen distintos valores");
            }
        }

        if (!pilavacia(&pilaA) || !pilavacia(&pilaB)) {
            printf("Las pilas tienen distinto tamaño");
        }

    } else {

        if (!pilavacia(&pilaA) || !pilavacia(&pilaB)) {
            printf("Las pilas tienen distinto tamaño");
        } else {
            printf("Una de las pilas esta vacia");
        }

    }
    return 0;
}
