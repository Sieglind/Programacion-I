#include <stdio.h>

#define TEXTO "El mayor numero es: %d"

int main() {
    int numeroA = 0;
    int numeroB = 0;
    int numeroC = 0;
    printf("Ingrese el primer numero:");
    scanf("%d", &numeroA);
    printf("Ingrese el segundo numero:");
    scanf("%d", &numeroB);
    printf("Ingrese el tercer numero:");
    scanf("%d", &numeroC);

    if(numeroC < numeroA){
        if (numeroB < numeroA){
            printf(TEXTO,numeroA);
        } else {
            printf(TEXTO,numeroB);
        }
    } else if (numeroC < numeroB){
        printf(TEXTO,numeroB);
    } else {
        printf(TEXTO,numeroC);
    }

    return 0;
}
