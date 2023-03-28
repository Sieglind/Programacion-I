#include <stdio.h>
#include <time.h>
#include "pila.h"

int main() {
    Pila main, auxiliar;
    int acumulador = 0;
    int contador = 0;

    inicpila(&main);
    inicpila(&auxiliar);

    ///Esto es para obtener numeros aleatorios diferentes cada vez
    srand(time(NULL));

    ///Genero una pila con 25 elementos "aleatorios"
    for (int i = 0; i < 25; i++) {
        apilar(&main, rand());
    }

    ///Mientras "main" no este vacia, sumo el valor del tope de "main" al acumulador, y luego sumo 1 al contador, luego
    ///paso el tope de "main" al auxiliar
    while (!pilavacia(&main)) {
        acumulador = acumulador + tope(&main);
        contador++;
        apilar(&auxiliar, desapilar(&main));
    }
    ///Devuelvo el contenido de "auxiliar" a "main"
    while (!pilavacia(&auxiliar)) {
        apilar(&main, desapilar(&auxiliar));
    }

    ///Muestro resultados pero solo si se conto al menos un elemento (la pila no esta vacia)
    if (contador != 0) {
        printf("La cantidad de elementos es: %d\n",contador);
        printf("La suma de elementos vale: %d\n",acumulador);
        printf("El promedio es: %0.2f", (float) acumulador / (float) contador);
    } else {
        printf("La pila esta vacia");
    }

    return 0;
}
