#include <stdio.h>

#define DISCOUNT 0.2

int main() {
    double totalCompra = 0;
    double totalAPagar = 0;

    printf("Cual fue el total de la compra?: ");
    scanf("%lf", &totalCompra);

    if (totalCompra > 500) {
        totalAPagar = totalCompra * (1 - DISCOUNT);
    } else {
        totalAPagar = totalCompra;
    }

    printf("El total a pagar es de: $ %lf",totalAPagar);
}