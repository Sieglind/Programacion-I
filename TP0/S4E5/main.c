#include <stdio.h>

#define CANTIDAD_DE_NOTAS 40
#define INGRESO "Ingrese una nota: "

int main() {
    int notaIngresada = 0;
    int notaMasBaja = 10;
    int sumaDeNotas = 0;

    for (int i=0;i<CANTIDAD_DE_NOTAS;i++){
        printf(INGRESO);
        scanf("%d",&notaIngresada);
        sumaDeNotas = sumaDeNotas + notaIngresada;
        if (notaIngresada < notaMasBaja){
            notaMasBaja = notaIngresada;
        }
    }

    printf("El promedio de notas del curso es: %0.2lf ",(float)sumaDeNotas/CANTIDAD_DE_NOTAS);
    printf("La nota mas baja fue: %d",notaMasBaja);

    return 0;
}
