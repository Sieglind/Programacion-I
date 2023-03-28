#include <stdio.h>
#include "pila.h"

#define PROMPT "Ingrese un numero: "

int main() {

    Pila dada, auxiliar;
    int numeroIngresado;
    int auxInt;

    inicpila(&dada);
    inicpila(&auxiliar);

    printf(PROMPT);
    auxInt = scanf("%d", &numeroIngresado);

    while (auxInt != 0) {
        apilar(&dada, numeroIngresado);
        printf(PROMPT);
        auxInt = scanf("%d", &numeroIngresado);
    }

    if (!pilavacia(&dada)) {
        while (!pilavacia(&dada)) {
            apilar(&auxiliar, desapilar(&dada));
        }
        auxInt = desapilar(&auxiliar);
        while (!pilavacia(&auxiliar)) {
            apilar(&dada, desapilar(&auxiliar));
        }
        apilar(&dada, auxInt);
    }

    mostrar(&dada);

    return 0;
}
