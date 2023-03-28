#include <stdio.h>
#include <math.h>

#define INGRESO "Ingrese un numero: "
#define TERCERA "La tercera potencia es: %0.2lf \n"
#define CUARTA "La cuarta potencia es: %0.2lf \n"

int main() {
    double numeroIngresado = 0;
    for (int i = 0; i < 10; i++) {
        printf(INGRESO);
        scanf("%lf", &numeroIngresado);
        printf(TERCERA,pow(numeroIngresado,3));
        printf(CUARTA, pow(numeroIngresado,4));
    }
    return 0;
}
