#include <stdio.h>
#include <time.h>
#include "funcionalidades.h"

int main() {
    srand(time(NULL));

    Pila main, auxiliar;
    int minimo;

    inicpila(&main);
    inicpila(&auxiliar);

    pilaEspecifica(&main, 5);

    if (!pilavacia(&main)) {
        minimo = tope(&main);
        while (!pilavacia(&main)) {
            if (tope(&main) < minimo) {
                minimo = tope(&main);
            }
            pasar(&auxiliar,&main);
        }
        pasarTodo(&main,&auxiliar);
        mostrar(&main);
        printf("El valor minimo es: %d",minimo);
    } else {
        printf("La pila esta vacia");
    }

    return 0;
}
