#include <stdio.h>
#include "pila.h"

int main() {

    Pila mazo,jugadorA,jugadorB;

    inicpila(&mazo);
    inicpila(&jugadorA);
    inicpila(&jugadorB);

    int i;

    for (i=0;i<48;i++){
        apilar(&mazo,i);
    }

    while(!pilavacia(&mazo)){
        apilar(&jugadorA, desapilar(&mazo));
        apilar(&jugadorB, desapilar(&mazo));
    }

    mostrar(&jugadorA);
    mostrar(&jugadorB);

    return 0;
}
