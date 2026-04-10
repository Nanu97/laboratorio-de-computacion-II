/*Ingresar un entero positivo N desde teclado, construir una función para validar el número,
generar en una función un array de N reales, otra función con carga aleatoria y otra para emitirlo.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void validacion(int * n){

    while ((scanf("%d", n) != 1) || *n <= 0){
        printf("Error. Ingrese un numero entero positivo:\n");
        //Limpiar buffer
        while (getchar() != '\n');
    }

}

float *generar_vector(int n){

    float * vector;
    vector = (float*)malloc(n * sizeof(float));

    if (vector == NULL){
        printf("Error: No se pudo reservar memoria\n");
        return NULL;
    }

    return vector;

}

void carga_aleatoria(float * v, int n){

    int i;

    for (i=0; i<n; i++){
        v[i] = (float)(rand() % 100);
    }

}

void emitir_vector(float * v, int n){

    int i;

    for (i=0; i<n; i++){
        printf("vector[%d] = %.2f\n", i, *(v+i));
    }
    printf("\n");
}

int main(){

    srand(time(NULL));
    int n;
    float * vector;

    printf("Ingrese un numero entero positivo:\n");

    validacion(&n);
    vector = generar_vector(n);

    if (vector == NULL){
        return 1;
    }

    carga_aleatoria(vector, n);
    emitir_vector(vector, n);

    free(vector);

return 0;
}
