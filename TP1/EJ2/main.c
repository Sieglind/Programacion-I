#include <stdio.h>
#include "pila.h"

#define PETICION "Ingrese un numero entero: "

int main() {
    int numeroIngresado;
    Pila origen, destino;

    inicpila(&origen);
    inicpila(&destino);

    printf(PETICION);
    // scanf() retorna 0 si no pudo convertir el valor ingresado
    int scanResult = scanf("%d", &numeroIngresado);
    while (scanResult != 0) {
        apilar(&origen, numeroIngresado);
        printf(PETICION);
        scanResult = scanf("%d", &numeroIngresado);
    }
    printf("El dato ingresado no puede procesarce como entero.");
    while (!pilavacia(&origen)){
        apilar(&destino, desapilar(&origen));
    }
    printf("La pila de origen resulta: \n");
    mostrar(&destino);
}
