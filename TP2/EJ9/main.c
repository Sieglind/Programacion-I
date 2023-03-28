#include "funcionalidades.h"

int main() {
    Pila dada, dadaInvertida, auxiliar;

    inicpila(&dada);
    inicpila(&dadaInvertida);
    inicpila(&auxiliar);

    int auxInt;

    for (auxInt = 0; auxInt < 4; auxInt++) {
        apilar(&dada, auxInt + 1);
    }
    apilar(&dada,5);
    for (auxInt = 4; auxInt > 0; auxInt--) {
        apilar(&dada, auxInt);
    }

    while (!pilavacia(&dada)){
        apilar(&dadaInvertida, tope(&dada));
        pasar(&auxiliar,&dada);
    }
    pasarTodo(&dada,&auxiliar);

    while (!pilavacia(&dada) && tope(&dada) == tope(&dadaInvertida)){
        pasar(&auxiliar,&dada);
        desapilar(&dadaInvertida);
    }

    if (!pilavacia(&dada)) {
        printf("La pila dada no es capicua\n");
    } else {
        printf("La pila dada es capicua\n");
    }

    pasarTodo(&dada,&auxiliar);

    mostrar(&dada);

    return 0;
}