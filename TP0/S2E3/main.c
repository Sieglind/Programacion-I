#include <stdio.h>

#define SALARIO_COMPLETO 12000
#define VALOR_HORA 300
#define VALOR_HORA_EXTRA 400

int main() {
    int horasTrabajadas = 0;
    int salario = 0;

    printf("Ingrese la cantidad de horas trabajadas: ");
    scanf("%d", &horasTrabajadas);

    if (horasTrabajadas >= 40) {
        salario = SALARIO_COMPLETO + (horasTrabajadas - 400) * VALOR_HORA_EXTRA;
    } else {
        salario = horasTrabajadas * VALOR_HORA;
    }

    printf("El salario semanal correspondiente es de: $ %d.",salario);

    return 0;
}
