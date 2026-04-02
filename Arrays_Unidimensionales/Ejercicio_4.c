/*Escribe una función que retorne un puntero al máximo valor de un vector de “doubles”.
Si el vector está vacío debe retornar NULL. //cabecera de función: double * max (double * v, int tam);*/
#include <stdio.h>

#define TAM 3

void carga_vector(double * v, int tam){

    int i;
    double num;

    for (i=0; i<tam; i++){
        printf("v[%d] = ", i);
        scanf("%lf", v+i);
    }

}

double * max(double * v, int tam) {

    int i;
    double * pmax;

    if (tam == 0)
        return NULL;

    pmax = v;       //ASIGNO A LA POSICION 0 COMO LA QUE CONTIENE AL MÁXIMO VALOR

    for (i = 1; i < tam; i++) {
        if (*(v + i) > *pmax) {
            pmax = (v + i);
        }
    }

    return pmax;
}

int main() {

    double v[TAM] = {0};
    double * resultado;

    carga_vector(v, TAM);

    resultado = max(v, TAM);

    if (resultado != NULL)
        printf("Max: %f\n", *resultado);

    return 0;
}
