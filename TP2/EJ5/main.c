#include <stdio.h>
#include <time.h>
#include "funcionalidades.h"

int main() {
    srand(time(NULL));
    Pila main,insertar, auxiliar;

    inicpila(&main);
    inicpila(&auxiliar);
    inicpila(&insertar);

    for (int i = 0; i < 10; i++) {
        apilar(&main,i+1);
        apilar(&insertar, aleatorioAB(1,10));
    }

    while (!pilavacia(&main) && !pilavacia(&insertar)) {
        if (tope(&insertar) < tope(&main)) {
            pasar(&auxiliar,&main);
        } else {
            pasar(&main,&insertar);
            pasarTodo(&main,&auxiliar);
        }
    }

    mostrar(&main);

    return 0;
}
