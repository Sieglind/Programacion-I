#include <stdio.h>
#include <stdlib.h>

#define FILAS "filas"
#define COLUMNAS "columnas"

void pedirDimension(int *valor, char dimension[]);

void cargarMatriz(int filas, int columnas, int matriz[filas][columnas]);

void mostrarMatriz(int filas, int columnas, int matriz[filas][columnas]);

int main() {
    int filasA;
    int columnasA;

    pedirDimension(&filasA, FILAS);
    pedirDimension(&columnasA, COLUMNAS);

    printf("%d\n", filasA);
    printf("%d\n", columnasA);
    int matrizA[filasA][columnasA];
    cargarMatriz(filasA, columnasA, matrizA);
    mostrarMatriz(filasA, columnasA, matrizA);

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
    printf("asdasd");
    system("pause");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese un valor para (%d,%d):\n", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf(" %d ",matriz[i][j]);
        }
        printf("\n");
    }
}