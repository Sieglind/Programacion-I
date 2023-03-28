#include <time.h>
#include "funcionalidades.h"

int main() {
    srand(time(NULL));

    Pila ordenadaA, ordenadaB,resultante, auxiliarA, auxiliarB, auxiliarC;

    inicpila(&ordenadaA);
    inicpila(&ordenadaB);
    inicpila(&resultante);
    inicpila(&auxiliarA);
    inicpila(&auxiliarB);
    inicpila(&auxiliarC);

    for (int i = 1; i < aleatorioAB(5, 10); i++) {
        apilar(&ordenadaA, 2 * i);
    }

    for (int i = 1; i < aleatorioAB(5, 10); i++) {
        apilar(&ordenadaB, 2 * i - 1);
    }

    while (!pilavacia(&ordenadaA) && !pilavacia(&ordenadaB)){
        if (tope(&ordenadaA) < tope(&ordenadaB)){
            apilar(&auxiliarC, tope(&ordenadaB));
            pasar(&auxiliarB,&ordenadaB);
        } else {
            apilar(&auxiliarC, tope(&ordenadaA));
            pasar(&auxiliarA,&ordenadaA);
        }
    }
    pasarTodo(&ordenadaA,&auxiliarA);
    pasarTodo(&ordenadaB,&auxiliarB);
    pasarTodo(&resultante,&auxiliarC);

    mostrar(&ordenadaA);
    mostrar(&ordenadaB);
    mostrar(&resultante);

    return 0;
}
