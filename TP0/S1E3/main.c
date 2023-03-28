#include <stdio.h>

void main(void) {
    int cantidadDeVarones = 0;
    int cantidadDeMujeres = 0;
    int totalDeAlumnos = 0;
    double porcentajeDeVarones = 0;
    double porcentajeDeMujeres = 0;

    printf("Ingrese la cantidad de alumnos: \n");
    scanf("%d",&cantidadDeVarones);
    printf("Ingrese la cantidad de alumnas: \n");
    scanf("%d",&cantidadDeMujeres);

    totalDeAlumnos = cantidadDeVarones + cantidadDeMujeres;
    porcentajeDeVarones = (double) cantidadDeVarones/totalDeAlumnos * 100;
    porcentajeDeMujeres = (double) cantidadDeMujeres/totalDeAlumnos * 100;

    printf("El total de alumnos es: %d\n",totalDeAlumnos);
    printf("El porcentaje de varones es: %lf %\n",porcentajeDeVarones);
    printf("El porcentaje de mujeres es: %lf %\n",porcentajeDeMujeres);

}
