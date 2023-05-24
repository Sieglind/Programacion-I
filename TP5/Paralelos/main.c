#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <process.h>

#define DIM_LEGAJOS 20
#define DIM_NOMBRES 30

int cargarLegajos(int dimension,
                  int letras,
                  int legajos[dimension],
                  char nombres[dimension][letras],
                  int anios[dimension]);

void mostrarPorLegajo(int dimesion,
                      int letras,
                      int validos,
                      int legajos[],
                      char nombres[dimesion][letras],
                      int anios[dimesion],
                      int query);

int encontrarLegajo(int validos, const int legajos[], int query);

int main() {
    int legajos[DIM_LEGAJOS];
    char nombres[DIM_LEGAJOS][DIM_NOMBRES];
    int anios[DIM_LEGAJOS];

    int legajosValidos = cargarLegajos(DIM_LEGAJOS, DIM_NOMBRES, legajos, nombres, anios);

    mostrarPorLegajo(DIM_LEGAJOS,DIM_NOMBRES,legajosValidos,legajos,nombres,anios,23);

    system("pause");
    return 0;
}

bool continuar() {
    char option;
    do {
        printf("Desea continuar? y/n. ");
        option = getch();
    } while (option != 'y' && option != 'n');
    return option == 'y';
}

int cargarLegajos(int dimension,
                  int letras,
                  int legajos[dimension],
                  char nombres[dimension][letras],
                  int anios[dimension]) {
    int validos = 0;
    int scanResult = 0;
    do {
        while (scanResult == 0) {
            printf("Ingrese un numero de legajo: ");
            scanResult = scanf("%d", &legajos[validos]);
        }
        scanResult = 0;
        do {
            fflush(stdin);
            printf("Ingrese el nombre del alumno: ");
        } while (strlen(gets(nombres[validos])) > 29);
        while (scanResult == 0) {
            printf("Ingrese un numero de anios: ");
            scanResult = scanf("%d", &anios[validos]);
        }
        scanResult = 0;
    } while (continuar() && (validos <= dimension));
    return validos;
}

int encontrarLegajo(int validos, const int legajos[], int query) {
    int posicion = 0;
    while (posicion < validos && legajos[posicion] != query) {
        posicion++;
    }
    return posicion;
}

void mostrarPorLegajo(int dimesion,
                      int letras,
                      int validos,
                      int legajos[],
                      char nombres[dimesion][letras],
                      int anios[dimesion],
                      int query) {
    int legajo = encontrarLegajo(validos, legajos, query);
    printf("\nLegajo: %d\n",legajos[legajo]);
    printf("\nNombre: %s\n",nombres[legajo]);
    printf("\nEdad: %d\n",anios[legajo]);
}

void ordenarLegajosAlfabeticamente()