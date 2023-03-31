#include "funcionalidades.h"

int main() {
    Pila pilaA, pilaB, auxiliarB, auxiliarA, diferentes, pilaUnion;

    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&auxiliarA);
    inicpila(&auxiliarB);
    inicpila(&diferentes);
    inicpila(&pilaUnion);

    ///Este for carga la pila "pilaA" del 1 al 3, y la pila "pilaB" del 2 al 7
    for (int i = 1; i < 8; i++) {
        if (i < 4) {
            apilar(&pilaA, i);
        }
        if (1 < i) {
            apilar(&pilaB, i);
        }
    }

    ///En este ciclo while copio "pilaA" a "auxiliarA"
    while (!pilavacia(&pilaA)){
        apilar(&auxiliarA,tope(&pilaA));
        pasar(&pilaUnion,&pilaA);
    }
    ///pasarTodo(&destino,&origen) es una funcion mia, que pasa el contenido de "origen" a "destino"
    pasarTodo(&pilaA,&pilaUnion);

    ///En este ciclo while copio "pilaB" a "auxiliarB"
    while (!pilavacia(&pilaB)){
        apilar(&auxiliarB,tope(&pilaB));
        pasar(&pilaUnion,&pilaB);
    }
    pasarTodo(&pilaB,&pilaUnion);

    ///Aca tengo anidado dos ciclos while
    ///Tengo que quedarme con todos los elementos que esten en ambas pilas, pero sin repetirlos
    while (!pilavacia(&auxiliarA)){
        ///Mientras B no este vacia...
        while (!pilavacia(&auxiliarB)){
            ///SI el tope de A es igual al tope de B
            if (tope(&auxiliarA) == tope(&auxiliarB)){
                ///Me deshago del tope de B, porque esta repetido y no me sirve, lo desapilo
                desapilar(&auxiliarB);
            } else {
                ///Si no... paso el tope de B a la pila "diferentes"
                pasar(&diferentes,&auxiliarB);
            }
        }
        ///Devuelvo los diferentes a la pila "auxiliarB"
        pasarTodo(&auxiliarB,&diferentes);
        ///Paso el tope de A a la pila union y vuelvo a comparar los elementos de B con el nuevo tope de A
        pasar(&pilaUnion,&auxiliarA);
    }
    ///Ahora la pila union tiene todos los elementos de A, y le paso los elementos de B que no estaban ya en A
    pasarTodo(&pilaUnion,&auxiliarB);

    mostrar(&pilaA);
    mostrar(&pilaB);
    mostrar(&pilaUnion);

    return 0;
}