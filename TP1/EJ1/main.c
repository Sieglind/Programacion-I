#include <stdio.h>
#include "pila.h"

int main() {

    Pila dada, aux1, aux2;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    int i;

    for ( i = 0;i<5;i++){
        leer(&dada);
    }

    for (i = 0;i<3;i++){
        apilar(&aux1, desapilar(&dada));
    }

    for (i = 0;i<2;i++){
        apilar(&aux2, desapilar(&dada));
    }

    mostrar(&aux1);
    mostrar(&aux2);

    return 0;
}
