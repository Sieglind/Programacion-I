#include <time.h>
#include <stdbool.h>
#include "funcionalidades.h"

int main() {
    srand(time(NULL));

    Pila main, auxiliarA;
    bool encontrado = false;

    inicpila(&main);
    inicpila(&auxiliarA);

    int query = aleatorioAB(1, 10);

    for (int i = 0; i < 10; i++) {
        apilar(&main, i + 1);
    }

    mostrar(&main);
    while (!pilavacia(&main) && !encontrado) {
        if (tope(&main) == query) {
            desapilar(&main);
            printf("Se elimino el elemento \"%d\" en la pila", query);
            encontrado = true;
        } else {
            pasar(&auxiliarA, &main);
        }
    }

    if (!pilavacia(&auxiliarA)) pasarTodo(&main, &auxiliarA);
    mostrar(&main);

    return 0;
}
