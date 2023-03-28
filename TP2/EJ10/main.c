#include "funcionalidades.h"

int main() {
    Pila pilaA, pilaB, auxiliarB, auxiliarA, diferentes, pilaUnion;

    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&auxiliarA);
    inicpila(&auxiliarB);
    inicpila(&diferentes);
    inicpila(&pilaUnion);

    for (int i = 1; i < 8; i++) {
        if (i < 4) {
            apilar(&pilaA, i);
        }
        if (1 < i) {
            apilar(&pilaB, i);
        }
    }

    while (!pilavacia(&pilaA)){
        apilar(&auxiliarA,tope(&pilaA));
        pasar(&pilaUnion,&pilaA);
    }
    pasarTodo(&pilaA,&pilaUnion);

    while (!pilavacia(&pilaB)){
        apilar(&auxiliarB,tope(&pilaB));
        pasar(&pilaUnion,&pilaB);
    }
    pasarTodo(&pilaB,&pilaUnion);

    while (!pilavacia(&auxiliarA)){
        while (!pilavacia(&auxiliarB)){
            if (tope(&auxiliarA) == tope(&auxiliarB)){
                desapilar(&auxiliarB);
            } else {
                pasar(&diferentes,&auxiliarB);
            }
        }
        pasarTodo(&auxiliarB,&diferentes);
        pasar(&pilaUnion,&auxiliarA);
    }
    pasarTodo(&pilaUnion,&auxiliarB);

    mostrar(&pilaA);
    mostrar(&pilaB);
    mostrar(&pilaUnion);

    return 0;
}