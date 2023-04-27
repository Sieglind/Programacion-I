#include <stdio.h>
#include <time.h>
#include "pila.h"

#define DIM 50

void cargarDatos(Pila pilaA, Pila *pilaB, Pila *pilaC);

int contarIntEnPila(Pila pila, int query);

int extraerEnteros(Pila *pila, int arrreglo[]);

void llenarArregloConRandoms(int arreglo[],int dimension);

int encontrarMayorSalteando(const int arreglo[], int validos, int *maximo);

int main() {
    srand(time(NULL));
    Pila pilaA,pilaB,pilaC;
    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&pilaC);
    int encontrados = 0;
    int query = 5;
    int arregloEncontrados[20] = {0};
    int extraidos = 0;
    int posicionMayor;
    int arregloA[DIM];
    int maximo = INT_MIN;

    ///Ejercicio 1
    cargarDatos(pilaA,&pilaB,&pilaC);
    mostrar(&pilaB);
    mostrar(&pilaC);

    ///Ejercicio 2
    encontrados = contarIntEnPila(pilaC,query);
    printf("Se encontraron %d numeros",encontrados);

    ///Ejercicio 3
    extraidos = extraerEnteros(&pilaC,arregloEncontrados);
    printf("Se extrajeron %d numeros",extraidos);

    ///Ejercicio 4
    llenarArregloConRandoms(arregloA,DIM);
    posicionMayor = encontrarMayorSalteando(arregloA,DIM, &maximo);
    printf("El mayor del arreglo vale %d y se encuentra en la posicion %d",maximo,posicionMayor);

    system("pause");
    return 0;
}

void cargarDatos(Pila pilaA, Pila *pilaB, Pila *pilaC) {
    int scanResult = 1;
    int datoIngresado;
    while (scanResult == 1) {
        printf("Ingrese un numero entero, cualquier otro valor para salir.");
        scanResult = scanf("%d", &datoIngresado);
        if (datoIngresado % 3 == 0) {
            datoIngresado % 2 != 0 ? apilar(&pilaA, datoIngresado) : apilar(pilaB, datoIngresado);
        } else {
            apilar(pilaC, datoIngresado);
        }
    }
    mostrar(&pilaA);
}

int contarIntEnPila(Pila pila, int query) {
    int hits = 0;
    while (!pilavacia(&pila)) {
        if (desapilar(&pila) == query) {
            hits++;
        }
    }
    return hits;
}

int extraerEnteros(Pila *pila, int arrreglo[]) {
    Pila aux;
    inicpila(pila);
    int i = 0;
    while (!pilavacia(pila)) {
        if (tope(pila) < 5 || 50 < tope(pila)) {
            apilar(&aux, desapilar(pila));
        } else {
            arrreglo[i] = desapilar(pila);
            i++;
        }
    }
    while (!pilavacia(&aux)) {
        apilar(pila, desapilar(&aux));
    }
    return i;
}

void llenarArregloConRandoms(int arreglo[],int dimension){
    for (int i=0;i<dimension;i++){
        arreglo[i] = rand();
    }
}

int encontrarMayorSalteando(const int arreglo[], int validos, int *maximo) {
    int saltos = validos%2 == 0 ? validos/2 : (validos-1)/2;
    int max = INT_MIN;
    int posicionMaximo;
    for (int i = 0;i <= saltos;i++){
        if (arreglo[validos-(2*saltos)] > max){
            max = arreglo[validos-(2*saltos)];
            posicionMaximo = validos-(2*saltos);
        }
    }
    *maximo = max;
    return posicionMaximo;
}