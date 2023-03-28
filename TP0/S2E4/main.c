#include <stdio.h>

int main() {

    int numeroA = 0;
    int numeroB = 0;

    printf("Ingrese el primer numero:");
    scanf("%d", &numeroA);

    printf("Ingrese el segundo numero:");
    scanf("%d", &numeroB);

    if (numeroA < numeroB) {
        printf("%d < %d", numeroA, numeroB);
    } else if (numeroA > numeroB) {
        printf("%d < %d", numeroB, numeroA);
    } else {
        printf("%d = %d", numeroB, numeroA);
    }

    return 0;
}
