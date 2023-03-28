#include <time.h>
#include "funcionalidades.h"

int main() {
    srand(time(NULL));

    Pila main, auxiliarA;

    inicpila(&main);
    inicpila(&auxiliarA);

    int query = aleatorioAB(1, 10);

    for (int i = 0; i < 10; i++) {
        apilar(&main, i + 1);
    }


    while (!pilavacia(&main)) {
        if (tope(&main) == query) {
            printf("Se encontro el elemento \"%d\" en la pila", query);
            break;
        } else {
            pasar(&auxiliarA, &main);
        }
    }

    if (!pilavacia(&auxiliarA)) pasarTodo(&main, &auxiliarA);
    mostrar(&main);

    return 0;
}
