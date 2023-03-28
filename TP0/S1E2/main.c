#include <stdio.h>

#define DISCOUNT 0.15

int main() {
    double totalCompra = 0;
    double totalConDescuento = 0;
    printf("Ingrese el total de la compra: ");
    scanf("%lf",&totalCompra);
    totalConDescuento = totalCompra * ((double)1-DISCOUNT);
    printf("El total a pagar es $ %lf",totalConDescuento);
    return 0;
}
