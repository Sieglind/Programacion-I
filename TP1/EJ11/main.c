#include <stdio.h>
#include "pila.h"

#define TOPE 10
#define PROMPT "Ingrese un numero entero: "

int main() {
    Pila modelo,dada,auxiliar;
    int numeroIngresado;
    int auxInt;

    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&auxiliar);

    for(auxInt = 0;auxInt<TOPE;auxInt++){
        apilar(&modelo,auxInt);
    }

    printf(PROMPT);
    auxInt = scanf("%d",&numeroIngresado);

    while (auxInt != 0){
        apilar(&dada,numeroIngresado);
        printf(PROMPT);
        auxInt = scanf("%d",&numeroIngresado);
    }

    while(!pilavacia(&dada)){
        if (tope(&dada) == tope(&modelo)){
            desapilar(&dada);
        } else {
            apilar(&auxiliar, desapilar(&dada));
        }
    }
    while (!pilavacia(&auxiliar)){
        apilar(&dada, desapilar(&auxiliar));
    }

    mostrar(&dada);

    return 0;
}
