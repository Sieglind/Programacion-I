#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void showMenu();

int loadVariable(int *number);

void numberPrompt(int *number);

int getRandomNumber();

void showMaxAndMin(int, int, int);

int addUpto(const int);

void showMultiplicationTable();

void invertNumber(int *);

int main() {
    srand(time(NULL));
    int scanResult = 1;
    int option = 0;
    int numberA = 0;
    int numberB = 0;
    int numberC = 0;

    while (scanResult == 1) {
        option = 0;
        showMenu();
        scanResult = loadVariable(&option);
        switch (option) {
            case 1:
                printf("%d\n", getRandomNumber());
                break;
            case 2:
                numberPrompt(&numberA);
                numberPrompt(&numberB);
                numberPrompt(&numberC);
                showMaxAndMin(numberA, numberB, numberC);
                break;
            case 3:
                numberPrompt(&numberA);
                printf("%d\n", addUpto(numberA));
            case 4:
                showMultiplicationTable();
                break;
            case 6:
                invertNumber(&numberA);
                printf("El numero invertido es: %d\n",numberA);
                break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}

void showMenu() {
    printf("Que desea hacer?\n");
    printf("1 - Obtener un numero random entre 0 y 100.\n");
    printf("2 - Determinar el maximo de entre 3 numeros.\n");
    printf("3 - Sumar desde cero hasta cierto numero.\n");
    printf("4 - Mostrar una tabla de multiplicar.\n");
    printf("6 - Cambiar el signo de una variable positiva.\n");
}

int getRandomNumber() {

    return rand() % 100;
};

int loadVariable(int *number) {

    int scanResult = scanf("%d", number);
    fflush(stdin);

    return scanResult;
}

void numberPrompt(int *number) {
    int scanResult = 0;
    while (scanResult == 0) {
        printf("Ingrese un numero entero: \n");
        scanResult = loadVariable(number);
    }
}

void determineMinOrMax(const int *number, int *min, int *max) {

    if (*number < *min) {
        *min = *number;
    }
    if (*max < *number) {
        *max = *number;
    }
}

void showMaxAndMin(int numberA, int numberB, int numberC) {
    int min = INT_MAX;
    int max = INT_MIN;

    determineMinOrMax(&numberA, &min, &max);
    determineMinOrMax(&numberB, &min, &max);
    determineMinOrMax(&numberC, &min, &max);

    printf("El minimo de los numeros ingresados es:\n");
    printf("%d\n", min);

    printf("El maximo de los numeros ingresados es:\n");
    printf("%d\n", max);
}

int addUpto(int number) {
    int sum = 0;
    for (int i = 1; i < number; i++) {
        sum = sum + i;
    }
    return sum;
}

void showMultiplicationTable() {
    int table = 0;
    while (table < 1 || 9 < table) {
        printf("Ingrese un numero del 1 al 9: ");
        scanf("%d", &table);
        fflush(stdin);
    }
    for (int i = 1; i <= 9; i++) {
        printf("%d x %d = %d\n", table, i, table * i);
    }
}

void invertNumber(int *number) {
    *number = INT_MIN;
    while (*number < 0) {
        printf("Ingrese un entero mayor a 0: ");
        loadVariable(number);
    }
    *number = 0 - *number;
}