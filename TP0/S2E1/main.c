#include <stdio.h>

int main() {
    double notaA = 0;
    double notaB = 0;
    double notaC = 0;
    double promedio = 0;
    printf("Ingrese la primera nota: ");
    scanf("%lf", &notaA);
    printf("Ingrese la segunda nota: ");
    scanf("%lf", &notaB);
    printf("Ingrese la tercera nota: ");
    scanf("%lf", &notaC);

    promedio = (notaA + notaB + notaC) / 3;

    if (promedio >= 7) {
        printf("El alumno ha aprobado");
    } else {
        printf("El alumno ha desaprobado");
    }
    return 0;
}
