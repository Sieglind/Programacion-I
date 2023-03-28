#include <stdio.h>

#define CANTIDAD_DE_NOTAS 7

int main() {
    int notaIngresada = 0;
    int sumaDeNotas = 0;
    for (int i =0;i<CANTIDAD_DE_NOTAS;i++){
        printf("Ingrese la nota:");
        scanf("%d",&notaIngresada);
        sumaDeNotas = sumaDeNotas+notaIngresada;
    }
    printf("El promedio del alumno es: %f",(float) sumaDeNotas/CANTIDAD_DE_NOTAS);

    return 0;
}
