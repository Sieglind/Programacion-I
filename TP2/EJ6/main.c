#include "funcionalidades.h"
/**
 *La libreria "funcionalidades incluye varias funciones creadas por mi, y tambien incluye la libreria de pilas
 **/

int main() {

    Pila main, auxiliarA, auxiliarB;

    inicpila(&main);
    inicpila(&auxiliarA);
    inicpila(&auxiliarB);

    ///Aqui le pido al usuario que ingrese 5 valores enteros
    for (int i = 0; i < 5; i++) {
        leer(&main);
    }

    mostrar(&main);

    //SI LEES ESTO AVISAME

    ///Si la pila no esta vacia...
    if (!pilavacia(&main)) {
        ///Esta funcion fue creada por mi, pasa el contenido de "main" a "auxiliarB"
        pasarTodo(&auxiliarB, &main);
        ///Mientras "auxiliarB" no este vacia...
        while (!pilavacia(&auxiliarB)) {
            ///Asumo que el minimo es el tope de la pila "auxiliarB"
            int minimo = desapilar(&auxiliarB);
            ///Mientras "auxiliarB" no este vacia...
            while (!pilavacia(&auxiliarB)) {
                ///Si el tope actual de "auxiliarB" es menor que el minimo
                if (tope(&auxiliarB) < minimo) {
                    ///Guardo el valor actual del minimo en la pila "auxiliarA" y asigno el tope actual de "auxiliarB" como nuevo minimo
                    apilar(&auxiliarA,minimo);
                    minimo = desapilar(&auxiliarB);
                } else {
                    ///Si no, paso el tope actual de "auxiliarB" a "auxiliarA"
                    pasar(&auxiliarA,&auxiliarB);
                }
            }
            ///El minimo que obtuve en el while interno, lo apilo en "main"
            apilar(&main,minimo);
            ///Vuelvo todos los valores de "auxiliarA" a "auxiliarB" para buscaro el siguiente minimo
            pasarTodo(&auxiliarB, &auxiliarA);
        }
    }
    ///Finalmente muestro la pila ordenada
    mostrar(&main);

    return 0;
}
