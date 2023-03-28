#include <stdio.h>
#include "pila.h"

#define PROMPT "Ingrese un numero entero:"

int main() {
    Pila dada,auxA,auxB;
    int numeroIngresado;
    int scanResult;

    inicpila(&dada);
    inicpila(&auxA);
    inicpila(&auxB);

    printf(PROMPT);
    scanResult = scanf("%d",&numeroIngresado);

    while (scanResult != 0){
        apilar(&dada,numeroIngresado);
        printf(PROMPT);
        scanResult = scanf("%d",&numeroIngresado);
    }

    while(!pilavacia(&dada)){
        apilar(&auxA, desapilar(&dada));
    }
    while(!pilavacia(&auxA)){
        apilar(&auxB, desapilar(&auxA));
    }
    while(!pilavacia(&auxB)){
        apilar(&dada, desapilar(&auxB));
    }

    mostrar(&dada);

    return 0;
}