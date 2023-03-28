#include <stdio.h>

#define INTERES 0.02

int main() {
    double dineroInvertido = 0;
    printf("Ingrese la cantidad de dinero que desea invertir: ");
    scanf("%lf",&dineroInvertido);

    double interesGanado = dineroInvertido * INTERES;

    printf("EL interes ganado este mes sera de: $ %.2f .",interesGanado);
    return 0;
}
