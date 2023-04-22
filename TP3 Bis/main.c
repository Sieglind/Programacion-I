#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void showMenu();

int loadVariable(int *number);

void numberPrompt(int *number);

int getRandomNumber();

void showMaxAndMin(int, int, int);

int addUpto(int);

void showMultiplicationTable();

void invertNumber(int *);

void loadTwoNumbers(int *, int *);

void showCalculatorMenu();

void sumar(int, int);

void calculator();

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
            case 5:
                calculator();
                break;
            case 6:
                invertNumber(&numberA);
                printf("El numero invertido es: %d\n", numberA);
                break;
            case 7:
                loadTwoNumbers(&numberA, &numberB);
                break;
            default:
                scanResult = 0;
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
    printf("5 - Abrir calculador.\n");
    printf("6 - Cambiar el signo de una variable positiva.\n");
    printf("7 - Cargar dos variables.\n");
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

void showCalculatorMenu() {
    printf("Que operacion desea realizar?.\n");
    printf("1 - Suma");
    printf("2 - Resta");
    printf("3 - Multiplicacion");
    printf("4 - Division");
    printf("5 - Raiz Cuadrada");
    printf("6 - Elevar al cuadrado");
    printf("7 - Inversa");
    printf("8 - Sacar porcentaje");
}

void sumar(int numberA, int numberB) {
    printf("%d + %d = %d", numberA, numberB, numberA + numberB);
}

void restar(int numberA, int numberB) {
    printf("%d - %d = %d", numberA, numberB, numberA - numberB);
}

void multiply(int numberA, int numberB) {
    printf("%d x %d = %d", numberA, numberB, numberA * numberB);
}

void divide(int numberA, int numberB) {
    printf("%d : %d = %lf", numberA, numberB, (float) numberA / (float) numberB);
}

void root(int numberA) {
    printf("%d ^ 2 = %d", numberA, numberA * numberA);
}

void calculator() {
    int scanResult = 1;
    int option = 0;
    int numberA = 0;
    int numberB = 0;
    while (scanResult == 1) {
        showCalculatorMenu();
        scanResult = loadVariable(&option);
        switch (option) {
            case 1:
                loadTwoNumbers(&numberA, &numberB);
                sumar(numberA, numberB);
                break;
            case 2:
                loadTwoNumbers(&numberA, &numberB);
                restar(numberA, numberB);
                break;
            case 3:
                loadTwoNumbers(&numberA, &numberB);
                multiply(numberA, numberB);
                break;
            case 4:
                numberB = 0;
                numberPrompt(&numberA);
                while (numberB == 0) {
                    numberPrompt(&numberB);
                }
                divide(numberA, numberB);
                break;
            case 5:
                numberA = 0;
                while (numberA < 1) {
                    numberPrompt(&numberA);
                }
                elevar(numberA);
                break;
            case 6:

                break;
            default:
                scanResult = 0;
        }
        system("pause");
        system("cls");
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

void loadTwoNumbers(int *numberA, int *numberB) {
    numberPrompt(numberA);
    numberPrompt(numberB);
}