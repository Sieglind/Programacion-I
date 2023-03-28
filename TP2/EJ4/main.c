#include <stdio.h>
#include <time.h>
#include "funcionalidades.h"
/**
 *La libreria "funcionalidades incluye varias funciones creadas por mi, y tambien incluye la libreria de pilas
 **/

int main() {
    ///Esto permite generar numeros aleatorios diferentes cada vez
    srand(time(NULL));

    Pila main, auxiliar;
    int minimo;

    inicpila(&main);
    inicpila(&auxiliar);

    ///Esta funcion es creada por mi, agrega 5 valores aleatorios a la pila "main"
    pilaEspecifica(&main, 5);

    ///Si la pila "main" no esta vacia...
    if (!pilavacia(&main)) {
        ///Asumo que mi minimo es el tope de la pila
        minimo = tope(&main);
        ///Mientras "main" no este vacia...
        while (!pilavacia(&main)) {
            ///Si el tope actual de "main" es menor que el minimo, se convierte en el nuevo minimo
            if (tope(&main) < minimo) {
                minimo = tope(&main);
            }
            ///Esta funcion es creada por mi, pasa un valor de la pila "main" a la "auxiliar"
            pasar(&auxiliar,&main);
        }
        ///Esta funcion es creada por mi, pasa el contenido de "auxiliar", de vuelta a "main"
        pasarTodo(&main,&auxiliar);

        ///Muestro la pila "main" y el valor minimo para comprobar
        mostrar(&main);
        printf("El valor minimo es: %d",minimo);
    } else {
        printf("La pila esta vacia");
    }

    return 0;
}
