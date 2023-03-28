#include "funcionalidades.h"

int main() {

    Pila main, auxiliarA, auxiliarB;

    inicpila(&main);
    inicpila(&auxiliarA);
    inicpila(&auxiliarB);

    for (int i = 0; i < 5; i++) {
        leer(&main);
    }

    mostrar(&main);

    if (!pilavacia(&main)) {
        pasarTodo(&auxiliarB, &main);
        while (!pilavacia(&auxiliarB)) {
            int minimo = desapilar(&auxiliarB);
            while (!pilavacia(&auxiliarB)) {
                if (tope(&auxiliarB) < minimo) {
                    apilar(&auxiliarA,minimo);
                    minimo = desapilar(&auxiliarB);
                } else {
                    pasar(&auxiliarA,&auxiliarB);
                }
            }
            apilar(&main,minimo);
            pasarTodo(&auxiliarB, &auxiliarA);
        }
    }
    mostrar(&main);

    return 0;
}
