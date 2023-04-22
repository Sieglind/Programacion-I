#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "pila.h"

#define PROMPT "Ingrese enteros para cargar el arreglo\nInngrese cualquier otro valor para salir...\n"

int cargarArreglo(int arreglo[], int dimension);

void mostrarArreglo(int arreglo[], int validos);

int sumatoriaArreglo(int arreglo[], int validos);

void arregloAPila(int arreglo[], int validos, Pila *pila);

void llenarArregloFLoat(float arreglo[]);

void mostrarArregloFloat(float arreglo[]);

void llenarArregloChar(char arreglo[]);

void mostrarArregloChar(char arreglo[]);

bool encontrarCaracter(char arrgelo[], int validos, char query);

int encontrarPosicion(char arreglo[], int validos, char query);

int main() {
    srand(time(NULL));

    int dimensionA = 10;
    int arregloA[dimensionA];
    int validosA = 0;
    int auxiliar;
    Pila pila;
    inicpila(&pila);
    float arregloB[100];
    char arrgeloC[13] = {(char) 0};
    int validosC = 10;

    validosA = cargarArreglo(arregloA, dimensionA);
    printf("Se agregaron %d elementos.\n", validosA);
    mostrarArreglo(arregloA, validosA);
    auxiliar = sumatoriaArreglo(arregloA, validosA);
    printf("La suma de los elementos es: %d\n", auxiliar);
    mostrarArreglo(arregloA, validosA);
    arregloAPila(arregloA, validosA, &pila);
    llenarArregloFLoat(arregloB);
    mostrar(&pila);
    mostrarArregloFloat(arregloB);
    llenarArregloChar(arrgeloC);
    char query = (char) ((rand() % 25) + 65);
    bool found = encontrarCaracter(arrgeloC, validosC, query);
    mostrarArregloChar(arrgeloC);
    printf("El caracter: %c, %s encontro en el arreglo\n", query, found ? "se" : "no se");

    system("pause");
    return 0;
}

int cargarArreglo(int arreglo[], int dimension) {
    int scanResult = 1;
    int validos = 0;
    int auxiliar;
    while (scanResult == 1 && validos < dimension) {
        printf(PROMPT);
        printf("Ingrese un valor entero: ");
        scanResult = scanf("%d", &auxiliar);
        if (scanResult == 1) {
            arreglo[validos] = auxiliar;
            validos++;
        }
        fflush(stdin);
        system("cls");
    }
    return validos;
}

void mostrarArreglo(int arreglo[], int validos) {
    printf("El contenido del arreglo es:\n");
    for (int i = 0; i < validos; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

int sumatoriaArreglo(int arreglo[], int validos) {
    int auxiliar = 0;
    for (int i = 0; i < validos; i++) {
        auxiliar = auxiliar + arreglo[i];
    }
    return auxiliar;
}

void arregloAPila(int arreglo[], int validos, Pila *pila) {
    for (int i = 0; i < validos; i++) {
        apilar(pila, arreglo[i]);
    }
}

void llenarArregloFLoat(float arreglo[]) {
    for (int i = 0; i < 100; i++) {
        arreglo[i] = (float) rand() / rand();
    }
}

void mostrarArregloFloat(float arreglo[]) {
    printf("El contenido del arreglo es:\n");
    for (int i = 0; i < 100; i++) {
        printf("%.2f ", arreglo[i]);
    }
    printf("\n");
}

void llenarArregloChar(char arreglo[]) {
    for (int i = 0; i < 12; i++) {
        arreglo[i] = (char) (65 + 2*i);
    }
}

void mostrarArregloChar(char arreglo[]) {
    for (int i = 0; i < 13; i++) {
        printf("%c ", arreglo[i]);
    }
    printf("\n");
}

bool encontrarCaracter(char arrgelo[], int validos, char query) {
    bool found = false;
    int i = 0;
    while (i < validos && !found) {
        if (arrgelo[i] == query) {
            found = true;
        }
        i++;
    }

    return found;
}

int encontrarPosicion(char arreglo[], int validos, char query) {
    int posicion = 0;
    while((int) query < (int) arreglo[posicion] && posicion < validos){
        posicion++;
    }
    return posicion;
}

void insertarCharOrdenado(char arreglo[],int validos,char query){
    int posicion = encontrarPosicion(arreglo,validos,query);
    for ()
}