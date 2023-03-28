#include <stdio.h>

#define DESCUENTO_SIN_CAMISAS 0.1
#define DESCUENTO_CON_CAMISAS 0.2

int main() {
    int cantidadCamisas = 0;
    float totalCompra = 0;

    printf("Cuantas camisas compro?");
    scanf("%d", &cantidadCamisas);
    printf("Cuanto es el total de la compra?");
    scanf("%f",&totalCompra);

    if (cantidadCamisas >= 3){
        printf("El total a pagar es: $ %f",totalCompra*(1-DESCUENTO_CON_CAMISAS));
    } else {
        printf("El total a pagar es: $ %f",totalCompra*(1-DESCUENTO_SIN_CAMISAS));
    }

    return 0;
}
