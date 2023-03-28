#include <stdio.h>
#include "pila.h"

#define LIMITE 5

int main() {
    Pila limite, dada, mayores, menores;

    inicpila(&limite);
    inicpila(&dada);
    inicpila(&mayores);
    inicpila(&menores);

    int auxInt;

    apilar(&limite,LIMITE);

    for (auxInt = 0; auxInt < 10; auxInt++) {
        apilar(&dada,auxInt+1);
    }

    while (!pilavacia(&dada)){
        if (tope(&dada) < tope(&limite)){
            apilar(&menores, desapilar(&dada));
        } else {
            apilar(&mayores, desapilar(&dada));
        }
    }
    mostrar(&mayores);
    mostrar(&menores);

    return 0;
}