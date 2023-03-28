#include <stdio.h>

#define PREGUNTA "De que numero quiere ver la tabla de multiplicar? "
#define FILA "%d x %d = %d \n"

int main() {
    int numeroIngresado = 0;
    printf(PREGUNTA);
    scanf("%d", &numeroIngresado);
    for (int i=1;i<=10;i++){
        printf(FILA,numeroIngresado,i,numeroIngresado*i);
    }
    return 0;
}
