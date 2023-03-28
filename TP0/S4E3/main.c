#include <stdio.h>

#define INGRESO "Ingrese un numero: "

int main() {
    int numeroIngresado = 0;
    for (int i = 0; i < 10; i++) {
        printf(INGRESO);
        scanf("%d", &numeroIngresado);
        if (numeroIngresado>0){
            printf("%d",numeroIngresado);
        }
    }
    return 0;
}
