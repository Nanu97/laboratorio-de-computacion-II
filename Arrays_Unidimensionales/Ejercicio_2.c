/*Dado un vector de dimensión N inicializado con valor0 (cero). Se debe pedir al usuario valor x (float)
y posición i para almacenar el dato. Los valores no se ingresan ordenados por posición. Se debe completar
el tamaño del vector. Si la posición está ocupada se vuelve a pedir el ingreso. Al finalizar, emitir el
contenido del vector indicando también la posición ocupada por cada número. Utiliza el ciclo while y funciones.*/
#include<stdio.h>

#define N 5

void carga_vector(float v[], int d){

    int cargados=0;
    int pos;
    int vector_pos[d];

    for (int i=0; i<d; i++){
        vector_pos[i] = 0;
    }

    while (cargados < d){
        printf("Ingrese la posicion: (Rango de 0 a %d)\n", d-1);
        scanf("%d", &pos);

        while (pos<0 || pos>=d){
            printf("Error. Posicion invalida\n");
            scanf("%d", &pos);
        }

        while (vector_pos[pos] == 1){
            printf("Posicion ocupada. Reintente\n");
            scanf("%d", &pos);

        while (pos<0 || pos>=d){
            printf("Error. Posicion invalida\n");
            scanf("%d", &pos);
        }

    }

        vector_pos[pos] = 1;

        printf("Ingrese el valor que ira a la posicion %d: \n", pos);
        scanf("%f", &v[pos]);

        cargados++;
    }

}

void emitir_vector(float v[], int d){

    int i;

    printf("\n");

    for (i=0; i<d; i++){
        printf("v[%d] = %.2f\n", i, v[i]);
    }

}

int main(){

    float v[N] = {0};

    carga_vector(v, N);
    emitir_vector(v, N);


return 0;
}
