#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "pila.h"


int main() {

    Pila dada, auxA;
    srand(time(NULL));
    int randAux = rand()%15;
    bool parity = true;

    inicpila(&dada);
    inicpila(&auxA);

    for (int i = 0;i<randAux;i++){
        apilar(&dada,i+1);
    }

    while (!pilavacia(&dada)){
        apilar(&auxA, desapilar(&dada));
        if (!pilavacia(&dada)){
            apilar(&auxA, desapilar(&dada));
        } else {
            parity = false;
        }
    }
    printf("%d\n",randAux);
    printf("La pila dada es %s",parity ? "par":"impar");

    return 0;
}
