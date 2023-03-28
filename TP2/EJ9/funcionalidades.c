#include <stdlib.h>
#include <time.h>
#include "funcionalidades.h"

//Devuelve un entero aleatorio
int aleatorio(void) {
    return rand();
}

//Devuelve un entero aleatorio entre "limiteInferior" y "limiteSuperior"
int aleatorioAB(int limiteInferior, int limiteSuperior) {
    return (aleatorio() % (limiteSuperior - limiteInferior + 1) + limiteInferior);
}

void llenarPila(P_Pila pila, int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        apilar(pila, aleatorio());
    }
}

void pilaRandom(P_Pila pila) {
    llenarPila(pila, aleatorioAB(1, 50));
};

void pialRandomN(P_Pila pila, int tamanio) {
    llenarPila(pila, tamanio);
}

void pasar(P_Pila destino, P_Pila origen) {
    apilar(destino, desapilar(origen));
}

void pasarTodo(P_Pila destino, P_Pila origen) {
    while (!pilavacia(origen)) {
        pasar(destino, origen);
    }
}