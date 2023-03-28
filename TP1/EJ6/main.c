#include <stdio.h>
#include "pila.h"

#define PROMPT "Ingrese un numero entero:"

int main() {
    Pila dada, pilaAux;
    int intAux;
    int scanResult;

    inicpila(&dada);
    inicpila(&pilaAux);

    printf(PROMPT);

    scanResult = scanf("%d", &intAux);
    while (scanResult != 0){
        apilar(&dada,intAux);
        printf(PROMPT);
        scanResult = scanf("%d",&intAux);
    }

    if (!pilavacia(&dada)){
        intAux = desapilar(&dada);
        while (!pilavacia(&dada)){
            apilar(&pilaAux, desapilar(&dada));
        }
        apilar(&dada,intAux);
        while (!pilavacia(&pilaAux)){
            apilar(&dada, desapilar(&pilaAux));
        }
    }

    mostrar(&dada);

    return 0;
}
