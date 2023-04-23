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

void mostrarArregloChar(char arreglo[], int validos);

bool encontrarCaracter(char arreglo[], int validos, char query);

int encontrarPosicion(char arreglo[], int validos, char query);

int insertarCharOrdenado(char arreglo[], int validos, char query);

char obtenerMaximo(char arreglo[], int validos);

bool arregloCharCapicua(char arreglo[], int validos);

void invertirArreglo(char arreglo[], int validos);

void llenarArregloRandomInt(int arreglo[], int dimension);

void ordernarArregloIntSeleccion(int arreglo[], int validos);

void ordernarArregloIntInsercion(int arreglo[], int validos);

int cargarRandomArregloCharOrdenado(char arreglo[]);

void juntarArreglosChar(char arregloA[], int validosA, char arregloB[], int validosB);

void vectorAcumulativo(int arreglo[],int validos);

int main() {
    srand(time(NULL));

    int dimensionA = 10;
    int arregloA[dimensionA];
    int validosA = 0;
    int auxiliar;
    Pila pila;
    inicpila(&pila);
    float arregloB[100];
    char arregloC[13] = {(char) 0};
    int validosC = 10;
    char arregloD[] = {'A', 'B', 'C', 'D', 'C', 'B', 'A'};
    int validosD = 7;
    char arregloE[] = {'E', 'F', 'G', 'G', 'F', 'E'};
    int validosE = 6;
    char arregloF[25];
    int validosF;
    char arregloG[25];
    int validosG;


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
    llenarArregloChar(arregloC);
    char query = (char) ((rand() % 25) + 65);
    bool found = encontrarCaracter(arregloC, validosC, query);
    mostrarArregloChar(arregloC, validosC);
    printf("El caracter: %c, %s encontro en el arreglo\n", query, found ? "se" : "no se");
    validosC = insertarCharOrdenado(arregloC, validosC, query);
    mostrarArregloChar(arregloC, validosC);
    printf("El mayor caracter del arreglo es: %c\n", obtenerMaximo(arregloC, validosC));
    printf("El arreglo %s capicua.\n", arregloCharCapicua(arregloC, validosC) ? "es" : "no es");
    mostrarArregloChar(arregloD, validosD);
    printf("El arreglo %s capicua.\n", arregloCharCapicua(arregloD, validosD) ? "es" : "no es");
    mostrarArregloChar(arregloE, validosE);
    printf("El arreglo %s capicua.\n", arregloCharCapicua(arregloE, validosE) ? "es" : "no es");
    invertirArreglo(arregloC, validosC);
    mostrarArregloChar(arregloC, validosC);
    llenarArregloRandomInt(arregloA, dimensionA);
    mostrarArreglo(arregloA, dimensionA);
    ordernarArregloIntSeleccion(arregloA, dimensionA);
    mostrarArreglo(arregloA, dimensionA);
    llenarArregloRandomInt(arregloA, dimensionA);
    mostrarArreglo(arregloA, dimensionA);
    ordernarArregloIntInsercion(arregloA, dimensionA);
    mostrarArreglo(arregloA,dimensionA);
    validosF = cargarRandomArregloCharOrdenado(arregloF);
    mostrarArregloChar(arregloF, validosF);
    validosG = cargarRandomArregloCharOrdenado(arregloG);
    mostrarArregloChar(arregloG, validosG);
    juntarArreglosChar(arregloF, validosF, arregloG, validosG);
    mostrarArreglo(arregloA,validosA);
    vectorAcumulativo(arregloA,validosA);
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
        if (i % 10 == 0) {
            printf("\n");
        }
        printf("%.2f ", arreglo[i]);
    }
    printf("\n");
}

void llenarArregloChar(char arreglo[]) {
    for (int i = 0; i < 12; i++) {
        arreglo[i] = (char) (65 + 2 * i);
    }
}

void mostrarArregloChar(char arreglo[], int validos) {
    for (int i = 0; i < validos; i++) {
        printf("%c ", arreglo[i]);
    }
    printf("\n");
}

bool encontrarCaracter(char arreglo[], int validos, char query) {
    bool found = false;
    int i = 0;
    while (i < validos && !found) {
        if (arreglo[i] == query) {
            found = true;
        }
        i++;
    }

    return found;
}

int encontrarPosicion(char arreglo[], int validos, char query) {
    int posicion = 0;
    while (query > arreglo[posicion] && posicion < validos) {
        posicion++;
    }
    return posicion;
}

int insertarCharOrdenado(char arreglo[], int validos, char query) {
    int posicion = encontrarPosicion(arreglo, validos, query);
    for (int i = validos - 1; posicion <= i; i--) {
        arreglo[i + 1] = arreglo[i];
    }
    arreglo[posicion] = query;
    return ++validos;
}

char obtenerMaximo(char arreglo[], int validos) {
    char maximo = 0;
    for (int i = 0; i < validos; i++) {
        if (maximo < arreglo[i]) maximo = arreglo[i];
    }
    return maximo;
}

bool arregloCharCapicua(char arreglo[], int validos) {
    int auxA = 0;
    int auxB = validos - 1;
    while (arreglo[auxA] == arreglo[auxB] && auxA < auxB) {
        auxA++;
        auxB--;
    }
    return auxA >= auxB;
}

void invertirArreglo(char arreglo[], int validos) {
    char aux;
    int auxA = 0;
    int auxB = validos - 1;
    while (auxA < auxB) {
        aux = arreglo[auxA];
        arreglo[auxA] = arreglo[auxB];
        arreglo[auxB] = aux;
        auxA++;
        auxB--;
    }
}

void llenarArregloRandomInt(int arreglo[], int dimension) {
    for (int i = 0; i < dimension; i++) {
        arreglo[i] = rand() % 20;
    }
}

void ordernarArregloIntSeleccion(int arreglo[], int validos) {
    int aux;
    for (int i = 0; i < validos - 1; i++) {
        int min = INT_MAX;
        int posMin = 0;
        for (int j = i; j < validos; j++) {
            if (arreglo[j] < min) {
                min = arreglo[j];
                posMin = j;
            }
        }
        aux = arreglo[i];
        arreglo[i] = arreglo[posMin];
        arreglo[posMin] = aux;
    }
}

void ordernarArregloIntInsercion(int arreglo[], int validos) {
    int aux;
    for (int i = 1; i < validos; i++) {
        int j = i - 1;
        aux = arreglo[i];
        while (aux < arreglo[j] && 0 <= j) {
            arreglo[j + 1] = arreglo[j];
            arreglo[j] = aux;
            j--;
        }
    }
}

int cargarRandomArregloCharOrdenado(char arreglo[]) {
    int index = 0;
    int validos = 0;
    for (int i = 0; i < 25; i++) {
        if (rand() % 2 == 0) {
            arreglo[index] = (char) (65 + i);
            validos++;
            index++;
        }
    }
    return validos;
}

void juntarArreglosChar(char arregloA[], int validosA, char arregloB[], int validosB) {
    int dimensionAD = validosA + validosB;
    char arregloDestino[dimensionAD];
    int validosAD = validosA;
    for (int i = 0; i < validosAD; i++) {
        arregloDestino[i]=arregloA[i];
    }
    for(int i = 0 ; i < validosB;i++){
        validosAD = insertarCharOrdenado(arregloDestino,validosAD,arregloB[i]);
    }
    mostrarArregloChar(arregloDestino,validosAD);
}

void vectorAcumulativo(int arreglo[],int validos){
    int resultado[validos];
    resultado[0] = arreglo[0];
    for (int i = 1; i < validos; i++){
        resultado[i] = resultado[i-1] + arreglo[i];
    }
    mostrarArreglo(resultado,validos);
}