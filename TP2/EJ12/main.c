#include <time.h>
#include "funcionalidades.h"

int main() {
    srand(time(NULL));

    Pila desordenada,ordenada,auxiliar;

    inicpila(&desordenada);
    inicpila(&ordenada);
    inicpila(&auxiliar);

///    Con este "FOR", creo una pila de tamaño entre cinco y diez con numeros aleatorios entre 1 y 20
    for (int i = 0; i < aleatorioAB(5,10);i++){
        apilar(&desordenada, aleatorioAB(1,20));
    }

    mostrar(&desordenada);
///Mientras la pila "desordenada no este vacia...
    while (!pilavacia(&desordenada)){
///     Si la pila ordenada esta vacia le coloco el tope de la pila desordenada
        if (pilavacia(&ordenada)) {
            pasar(&ordenada,&desordenada);
///         Luego paso lo que haya en la pila auxilliar si hay algo
            if (!pilavacia(&auxiliar)){
                pasarTodo(&ordenada,&auxiliar);
            }
        } else if (tope(&ordenada) > tope(&desordenada)) {
/**         Si el tope de la pila ordenada es mayor al de la pila desordenada
            Lo paso a la pila auxilliar, para comparar el tope de desordenada con el siguiente en la pila **/
            pasar(&auxiliar,&ordenada);
        } else {
/**         Si el tope de la pila ordenada es menor al de la pila desordenada
            Paso el tope de la pila desordenada a la pila ordenada **/
            pasar(&ordenada,&desordenada);
///         Luego paso lo que haya en la pila auxilliar si hay algo
            if (!pilavacia(&auxiliar)){
                pasarTodo(&ordenada,&auxiliar);
            }
        }
    }

    mostrar(&ordenada);

    return 0;
}
