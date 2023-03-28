#include <stdio.h>
#include "pila.h"

#define PROMPT "Ingrese un numero entero:"

int main() {
    Pila origen,destino,aux;
    int numeroIngresado;
    int scanResult;

    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux);

    printf(PROMPT);
    scanResult = scanf("%d",&numeroIngresado);

    while (scanResult != 0){
        apilar(&origen,numeroIngresado);
        printf(PROMPT);
        scanResult = scanf("%d",&numeroIngresado);
    }

    while (!pilavacia(&origen)){
        apilar(&aux, desapilar(&origen));
    }
    while (!pilavacia(&aux)){
        apilar(&destino, desapilar(&aux));
    }

    mostrar(&destino);
    return 0;
}