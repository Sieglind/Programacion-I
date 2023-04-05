#include <stdio.h>
#include <math.h>
#include "pila.h"

#define ORIGEN "ORIGEN"
#define DESTINO "DESTINO"
#define PILA_VACIA "La pila %s esta vacia, por favor cargue datos.\n"

void cargarPila(Pila *);

void verificarPila(char[],Pila*);

void pasarTodo(Pila *, Pila *);

void copiarPila(Pila *, Pila *);

int sacarMinimo(Pila *);

void ordenarPila(Pila *, Pila *);

void insertarNumero(int, Pila *);

void insertarPila(Pila *, Pila *);

int addStackFirstTwo(Pila *);

int contarElementos(Pila);

int sumarElementos(Pila);

float dividirElementos(int divisor, int dividendo);

float calcularPromedio(Pila);

double compilarNumero(Pila);

int main() {
    int scanResult = 1;
    int option;
    int auxiliar;

    Pila origen, destino;
    inicpila(&origen);
    inicpila(&destino);

    while (scanResult != 0) {
        option = 0;
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
        scanResult = scanf("%d", &option);
        switch (option) {
            case 1:
                cargarPila(&origen);
                break;
            case 2:
                verificarPila(ORIGEN,&origen);
                inicpila(&destino);
                pasarTodo(&origen, &destino);
                break;
            case 3:
                verificarPila(ORIGEN,&origen);
                copiarPila(&origen, &destino);
                break;
            case 4:
                verificarPila(ORIGEN,&origen);
                auxiliar = sacarMinimo(&origen);
                printf("%d", auxiliar);
            case 5:
                verificarPila(ORIGEN,&origen);
                ordenarPila(&origen, &destino);
                break;
            case 6:
                verificarPila(ORIGEN,&origen);
                printf("Que numero desea insertar?: ");
                scanf("%d",&auxiliar);
                insertarNumero(auxiliar, &destino);
                break;
            case 7:
                verificarPila(ORIGEN,&origen);
                verificarPila(DESTINO,&destino);
                insertarPila(&origen, &destino);
                break;
            case 8:
                verificarPila(ORIGEN,&origen);
                printf("%d", addStackFirstTwo(&origen));
                break;
            case 9:
                verificarPila(ORIGEN,&origen);
                printf("%f", calcularPromedio(origen));
                break;
            case 10:
                verificarPila(ORIGEN,&origen);
                printf("%lf", compilarNumero(origen));
                break;
            default:
                scanResult = 0;
        }
    }
    system("pause");
    return 0;
}


void cargarPila(Pila *pila) {
    int scanResult = 1;
    int enteroIngresado;
    while (scanResult != 0) {
        printf("Ingrese un numero entero: ");
        scanResult = scanf("%d", &enteroIngresado);
        system("cls");
        apilar(pila, enteroIngresado);
    }
    fflush(stdin);
}

void mostrarPila(Pila * pila){
    
};

void verificarPila(char nombrePila[],Pila * pila){
    if (pilavacia(pila)){
        printf(PILA_VACIA,nombrePila);
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
            apilar(&auxiliarA, tope(origen));
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

int addStackFirstTwo(Pila *origen) {
    Pila auxiliar;
    int suma = 0;
    inicpila(&auxiliar);
    for (int i = 0; i < 2; i++) {
        suma = suma + tope(origen);
        apilar(&auxiliar, desapilar(origen));
    }
    pasarTodo(&auxiliar, origen);
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

double compilarNumero(Pila origen) {
    double numero = 0;
    int digitos = contarElementos(origen);
    for (int i = digitos; -1 < i; i--) {
        numero = numero + pow(i, 10) * desapilar(&origen);
    }
    return numero;
}