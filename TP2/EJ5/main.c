#include <stdio.h>
#include <time.h>
#include "funcionalidades.h"
/**
 *La libreria "funcionalidades incluye varias funciones creadas por mi, y tambien incluye la libreria de pilas
 **/

int main() {
    srand(time(NULL));
    Pila main,insertar, auxiliar;

    inicpila(&main);
    inicpila(&auxiliar);
    inicpila(&insertar);

    ///En este FOR agrego valores ordenados a la pila "main" y valores aleatorios a la pila que quiero mezclar con main
    ///Originalmente el ejercicio pide solo insertar un elemento, pero como podia lo hice para una pila entera
    ///En el ejercicio 12 esto se vuelve muy util
    for (int i = 0; i < 10; i++) {
        apilar(&main,i+1);
        ///La funcion "aleatorioAB(x,y)" devuelve numeros aleatorios entre los valores x e y
        apilar(&insertar, aleatorioAB(1,10));
    }

    ///Si las pilas "main" e "insertar" no estan vacias...
    while (!pilavacia(&main) && !pilavacia(&insertar)) {
        ///Si el tope de la pila "insertar" es menor que el tope de "main"
        if (tope(&insertar) < tope(&main)) {
            ///Esta funcion fue creada por mi, pasa un valor de la pila "main" a la pila "auxiliar"
            pasar(&auxiliar,&main);
        } else {
            ///Si no, paso el tope de "insertar" a la pila "main"
            pasar(&main,&insertar);
            ///Y paso el contenido de la pila "auxiliar" a la pila "main"
            pasarTodo(&main,&auxiliar);
        }
    }

    mostrar(&main);

    return 0;
}
