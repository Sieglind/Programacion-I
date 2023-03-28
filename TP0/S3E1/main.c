#include <stdio.h>

int main() {

    int numeroA = 0;
    int numeroB = 0;

    printf("Ingrese el primero numero:");
    scanf("%d", &numeroA);
    printf("Ingrese el segundo numero:");
    scanf("%d", &numeroB);

    if (numeroA < numeroB) {
        printf("El resultado es: %d",numeroA+numeroB);
    } else if (numeroA > numeroB){
        printf("El resultado es: %d",numeroA-numeroB);
    } else {
        printf("El resultado es: %d",numeroA*numeroB);
    }

    return 0;
}
