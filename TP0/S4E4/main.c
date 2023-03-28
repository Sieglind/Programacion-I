#include <stdio.h>

#define INGRESO "Ingrese un numero negativo: "

int main() {
    int numeroIngresado = 0;
    for (int i = 0; i < 15; i++) {
        printf(INGRESO);
        scanf("%d", &numeroIngresado);
        printf("%d", -numeroIngresado);
    }
    return 0;
}
