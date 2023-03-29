#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funcionalidades.h"

int main() {
    srand(time(NULL));

    Pila mazo, jugadorA, jugadorB, auxiliarA, auxiliarB, puntosA, puntosB;

    inicpila(&mazo);
    inicpila(&jugadorA);
    inicpila(&jugadorB);
    inicpila(&auxiliarA);
    inicpila(&auxiliarB);
    inicpila(&puntosA);
    inicpila(&puntosB);

    bool mano,ganoA;

    int auxA = 0;
    int auxB = 0;

    for (int i = 1; i <= 48; i++) {
        switch (aleatorioAB(1, 4)) {
            case 1: {
                apilar(&jugadorA, i);
                break;
            }
            case 2: {
                apilar(&jugadorB, i);
                break;
            }
            case 3: {
                apilar(&puntosA, i);
                break;
            }
            case 4: {
                apilar(&puntosB, i);
                break;
            }
        }
    }
    pasarTodo(&mazo, &jugadorA);
    pasarTodo(&mazo, &jugadorB);
    pasarTodo(&mazo, &puntosA);
    pasarTodo(&mazo, &puntosB);

    for (int i = 0; i < 12; i++) {
        mano = (i % 2 != 0);
        if (mano) {
            pasar(&jugadorA, &mazo);
            pasar(&jugadorA, &mazo);
            pasar(&jugadorB, &mazo);
            pasar(&jugadorB, &mazo);
        } else {
            pasar(&jugadorB, &mazo);
            pasar(&jugadorB, &mazo);
            pasar(&jugadorA, &mazo);
            pasar(&jugadorA, &mazo);
        }
        for (int j = 0;j<2;j++){
            auxA = auxA + tope(&jugadorA);
            auxB = auxB + tope(&jugadorB);
        }
        if ((mano && auxA == auxB) || auxB < auxA){
            pasarTodo(&puntosA,&jugadorA);
            pasarTodo(&puntosA,&jugadorB);
        } else {
            pasarTodo(&puntosB,&jugadorA);
            pasarTodo(&puntosB,&jugadorB);
        }
    }
    mostrar(&puntosA);
    mostrar(&puntosB);

}