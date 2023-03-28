#include <stdio.h>
#include "pila.h"

#define PROMPT "Ingrese un numero entero: "

int main() {

    Pila dada, distintos;

    int numeroIngresado;
    printf(PROMPT);
    // scanf() retorna 0 si no pudo convertir el valor ingresado
    int scanResult = scanf("%d",&numeroIngresado);
    while(scanResult != 0){
        apilar(&dada,numeroIngresado);
        printf(PROMPT);
        scanResult = scanf("%d",&numeroIngresado);
    }
    printf("El dato ingresado no puede procesarse como entero.");
    while (!pilavacia(&dada)){
        if (tope(&dada) != 8){
            apilar(&distintos, desapilar(&dada));
        }
    }

    printf("Dada:\n");
    mostrar(&dada);
    printf("Distintos:\n");
    mostrar(&distintos);

    return 0;
}
