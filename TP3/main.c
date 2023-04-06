#include <stdio.h>
#include "pila.h"
#include <math.h>

#define ORIGEN "ORIGEN"
#define DESTINO "DESTINO"
#define PILA_VACIA "La pila %s esta vacia, por favor cargue datos.\n"

void cargarPila(Pila *);

void mostrarPila(char [], Pila);

void verificarPila(char[], Pila *);

void pasarTodo(Pila *, Pila *);

void copiarPila(Pila *, Pila *);

int sacarMinimo(Pila *);

void ordenarPila(Pila *, Pila *);

void insertarNumero(int, Pila *);

void insertarPila(Pila *, Pila *);

int addStackFirstTwo(Pila);

int contarElementos(Pila);

int sumarElementos(Pila);

float dividirElementos(int divisor, int dividendo);

float calcularPromedio(Pila);

int compilarNumero(Pila);

int main() {
    int scanResult = 1;
    int option;
    int auxiliar;

    Pila origen, destino;
    inicpila(&origen);
    inicpila(&destino);

    while (scanResult != 0) {
        option = 0;
        system("cls");
        printf("Que desea hacer?\n");
        printf("1 - Cargar una pila con datos.\n");
        printf("2 - Pasar todos los elementos de una pila a otra.\n");
        printf("3 - Copiar el contenido de una pila.\n");
        printf("4 - Sacar el minimo de una pila.\n");
        printf("5 - Ordernar Pila.\n");
        printf("6 - Insertar numero en pila ordenada.\n");
        printf("7 - Insertar una pila en otra pila ordenadamente.\n");
        printf("8 - Sumar primeros dos elementos de una pila.\n");
        printf("9 - Calcular promedio de valores de una pila.\n");
        printf("10 - Compilar un entero con los elementos de una pila.\n");
        scanResult = scanf("%d", &option);
        switch (option) {
            case 1:
                inicpila(&origen);
                cargarPila(&origen);
                mostrarPila(ORIGEN, origen);
                break;
            case 2:
                verificarPila(ORIGEN, &origen);
                inicpila(&destino);
                pasarTodo(&origen, &destino);
                mostrarPila(DESTINO, destino);
                break;
            case 3:
                verificarPila(ORIGEN, &origen);
                inicpila(&destino);
                copiarPila(&origen, &destino);
                mostrarPila(ORIGEN, origen);
                mostrarPila(DESTINO, destino);
                break;
            case 4:
                verificarPila(ORIGEN, &origen);
                mostrarPila(ORIGEN, origen);
                auxiliar = sacarMinimo(&origen);
                printf("El minimo de 'origen' es: %d\n", auxiliar);
                mostrarPila(ORIGEN, origen);
                break;
            case 5:
                verificarPila(ORIGEN, &origen);
                mostrarPila(ORIGEN, origen);
                ordenarPila(&origen, &destino);
                mostrarPila(DESTINO, destino);
                break;
            case 6:
                verificarPila(ORIGEN, &origen);
                mostrarPila(ORIGEN, origen);
                printf("Que numero desea insertar?: ");
                scanf("%d", &auxiliar);
                insertarNumero(auxiliar, &origen);
                mostrarPila(ORIGEN, origen);
                break;
            case 7:
                verificarPila(ORIGEN, &origen);
                verificarPila(DESTINO, &destino);
                mostrarPila(ORIGEN, origen);
                mostrarPila(DESTINO, destino);
                insertarPila(&origen, &destino);
                mostrarPila(DESTINO, destino);
                break;
            case 8:
                verificarPila(ORIGEN, &origen);
                mostrarPila(ORIGEN, origen);
                printf("\nLa suma de los primeros dos elementos da: %d", addStackFirstTwo(origen));
                break;
            case 9:
                verificarPila(ORIGEN, &origen);
                mostrarPila(ORIGEN, origen);
                printf("El promedio de valores de la pila es: %f \n", calcularPromedio(origen));
                break;
            case 10:
                verificarPila(ORIGEN, &origen);
                mostrarPila(ORIGEN, origen);
                printf("%d \n", compilarNumero(origen));
                break;
            default:
                scanResult = 0;
        }
        system("pause");
    }
    printf("\n");
    system("pause");
    return 0;
}


void cargarPila(Pila *pila) {
    int scanResult = 1;
    int enteroIngresado;
    while (scanResult != 0) {
        printf("Ingrese un numero entero: ");
        scanResult = scanf("%d", &enteroIngresado);
        if (scanResult != 0) {
            apilar(pila, enteroIngresado);
        }
        system("cls");
    }
    fflush(stdin);
}

void mostrarPila(char nombrePila[], Pila pila) {
    printf("%s : \n", nombrePila);
    while (!pilavacia(&pila)) {
        printf("%d ", desapilar(&pila));
    }
    printf("\n");
};

void verificarPila(char nombrePila[], Pila *pila) {
    if (pilavacia(pila)) {
        system("cls");
        printf(PILA_VACIA, nombrePila);
        cargarPila(pila);
    }
}

void pasarTodo(Pila *origen, Pila *destino) {
    while (!pilavacia(origen)) {
        apilar(destino, desapilar(origen));
    }
}

void copiarPila(Pila *origen, Pila *destino) {
    Pila auxiliar;
    inicpila(&auxiliar);
    pasarTodo(origen, &auxiliar);
    while (!pilavacia(&auxiliar)) {
        apilar(origen, tope(&auxiliar));
        apilar(destino, desapilar(&auxiliar));
    }
}

int sacarMinimo(Pila *origen) {
    Pila auxiliarA;
    inicpila(&auxiliarA);
    int minimo;
    minimo = desapilar(origen);
    while (!pilavacia(origen)) {
        if (minimo < tope(origen)) {
            apilar(&auxiliarA, desapilar(origen));
        } else {
            apilar(&auxiliarA, minimo);
            minimo = desapilar(origen);
        }
    }
    pasarTodo(&auxiliarA, origen);
    return minimo;
};

void ordenarPila(Pila *origen, Pila *destino) {
    while (!pilavacia(origen)) {
        apilar(destino, sacarMinimo(origen));
    }
}

void insertarNumero(int numero, Pila *pila) {
    Pila auxiliar;
    inicpila(&auxiliar);
    apilar(pila, numero);
    ordenarPila(pila, &auxiliar);
    copiarPila(&auxiliar, pila);
}

void insertarPila(Pila *origen, Pila *destino) {
    while (!pilavacia(origen)) {
        insertarNumero(desapilar(origen), destino);
    }
}

int addStackFirstTwo(Pila origen) {
    int suma = 0;
    for (int i = 0; i < 2; i++) {
        suma = suma + desapilar(&origen);
    }
    return suma;
}

int contarElementos(Pila origen) {
    int total = 0;
    while (!pilavacia(&origen)) {
        desapilar(&origen);
        total++;
    }
    return total;
}

int sumarElementos(Pila origen) {
    int suma = 0;
    while (!pilavacia(&origen)) {
        suma = suma + desapilar(&origen);
    }
    return suma;
}

float dividirElementos(int divisor, int dividendo) {
    return (float) divisor / (float) dividendo;
}

float calcularPromedio(Pila pila) {
    if (!pilavacia(&pila)) {
        return dividirElementos(sumarElementos(pila), contarElementos(pila));
    } else {
        printf("La pila esta vacía.");
        return 0;
    }
}

int compilarNumero(Pila origen) {
    int numero = 0;
    int digitos = contarElementos(origen);
    for (int i = 1; i <= digitos; i++) {
        numero = numero + (int) (pow(10, digitos - i) * desapilar(&origen));
    }
    return numero;
}