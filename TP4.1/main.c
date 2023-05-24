#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define FILAS "filas"
#define COLUMNAS "columnas"

void pedirDimension(int *valor, char dimension[]);

void cargarMatriz(int filas, int columnas, int matriz[filas][columnas]);

void mostrarMatriz(int filas, int columnas, int matriz[filas][columnas]);

void llenarMatrizConAleatorios(int filas, int columnas, int matriz[filas][columnas]);

int sumarElementosDeMatriz(int filas, int columnas, int matriz[filas][columnas]);

float promedioElementosDeMatriz(int filas, int columnas, int matriz[filas][columnas]);

bool encontrarEnMatriz(int filas, int columnas, int matriz[filas][columnas], int query);

void cargarPalabras(int filas, int letras, char palabras[filas][letras]);

void mostarPalabras(int palabras, int letras, char arrgelo[palabras][letras]);

int buscarPalabraEnMatriz(int filas, int letras, char palabras[filas][letras], char query[]);

void insertarPalabraOrdenada(int palabras, int letras, char arreglo[palabras][letras + 1], char palabra[letras + 1]);

void ordenarPalabras(int palabras, int letras, char arreglo[palabras][letras + 1]);

int determinante(int matriz[2][2]);

bool inversible(int matriz[2][2]);

void producto(int matrizA[2][2], int matrizB[2][5], int resultado[2][5]);

void inversa(int matriz[2][2], double inversa[2][2]);

void mostrarMatrizDouble(int filas, int columnas, double matriz[filas][columnas]);

int main() {
    srand(time(NULL));

    int palabras;
    int letras;

    pedirDimension(&palabras, "palabras");
    pedirDimension(&letras, "letras");

    char lista[palabras][letras + 1];
    cargarPalabras(palabras, letras, lista);
    mostarPalabras(palabras, letras, lista);

    system("pause");
    return 0;
}

void pedirDimension(int *valor, char dimension[]) {
    int scanResult = 0;
    while (scanResult == 0) {
        printf("Ingrese la cantidad de %s de la matriz:\n", dimension);
        scanResult = scanf("%d", valor);
        fflush(stdin);
        if (scanResult != 1) {
            system("cls");
            printf("El valor ingresado no es valido.\n");
            scanResult = 0;
        } else if (*valor < 1) {
            system("cls");
            printf("La dimension no puede ser menor a 1.\n");
            scanResult = 0;
        }
    }
}

void cargarMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese un valor para (%d,%d):\n", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
            system("cls");
        }
    }
}

void mostrarMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void llenarMatrizConAleatorios(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand();
        }
    }
}

int sumarElementosDeMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    int suma = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            suma = suma + matriz[i][j];
        }
    }
    return suma;
}

float promedioElementosDeMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    return (float) sumarElementosDeMatriz(filas, columnas, matriz) / (float) (filas * columnas);
}

bool encontrarEnMatriz(int filas, int columnas, int matriz[filas][columnas], int query) {
    bool encontrado;
    int i = 0;
    int j;
    while (i < filas && !encontrado) {
        j = 0;
        while (j < columnas && !encontrado) {
            if (matriz[i][j] == query) encontrado = true;
            j++;
        }
        i++;
    }
    return encontrado;
}

void cargarPalabras(int filas, int letras, char palabras[filas][letras + 1]) {
    for (int i = 0; i < filas; i++) {
        printf("Ingrese la palabra %d:\n", i + 1);
        gets(palabras[i]);
    }
    printf("\n");
}

void mostarPalabras(int palabras, int letras, char arreglo[palabras][letras + 1]) {
    for (int i = 0; i < palabras; i++) {
        printf(" - %s.\n", arreglo[i]);
    }
}

int buscarPalabraEnMatriz(int filas, int letras, char palabras[filas][letras], char query[]) {
    int i = 0;
    while (i < filas && strcmp(query, palabras[i]) != 0) {
        i++;
    }
    if (strcmp(query, palabras[i]) == 0) {
        return i;
    } else {
        return -1;
    }
}

int encontrarPalbraMinima(int inicio, int palabras, int letras, char arreglo[][letras]){
    int posicion = inicio;
    for (int i = palabras;z)
}

void ordernarPalabras(int palabras, int letras,)

        int determinante(int matriz[2][2]) {
    return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
}

bool inversible(int matriz[2][2]) {
    return determinante(matriz) != 0;
}

void producto(int matrizA[2][2], int matrizB[2][5], int resultado[2][5]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            int rIJ = 0;
            for (int k = 0; k < 2; k++) {
                rIJ = rIJ + (matrizA[i][k] * matrizB[k][j]);
            }
            resultado[i][j] = rIJ;
        }
    }
}

void inversa(int matriz[2][2], double inversa[2][2]) {
    int det = determinante(matriz);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            inversa[i][j] = (double) matriz[!j][!i] * pow(-1, i + j) * (double) 1 / det;
        }
    }
}

void mostrarMatrizDouble(int filas, int columnas, double matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf(" %lf ", matriz[i][j]);
        }
        printf("\n");
    }
}
