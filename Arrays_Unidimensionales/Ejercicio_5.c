/*Construye una función tal que dados dos vectores de 5 elementos cada uno,
los concatene en un tercer un vector de 10 elementos.
Ej:

V1 = 2-56-7-8-30;

V2 = 7-80-2-4-13;

V3 = 2-56-7-8-30-7-80-2-4-13; */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carga_vector(int * v1, int * v2){

    int i;

    for (i=0; i<5; i++){
        v1[i] = rand() % 30;
        v2[i] = rand() % 30;
    }

}

    void concatenar(int * v1, int * v2, int * v3){

    int i;

    for (i=0; i<5; i++){
        v3[i] = v1[i];
    }

    for (i=5; i<10; i++){
        v3[i] = v2[i-5];
    }

}

void mostrar_vector(int * v1, int * v2, int * v3){

    int i;

    printf("V1 = ");
    for (i=0; i<5; i++){
        printf("%d", v1[i]);
        if (i<4){
            printf("-");
        }
    }

    printf("\nV2 = ");
    for (i=0; i<5; i++){
        printf("%d", v2[i]);
        if (i<4){
            printf("-");
        }
    }

    printf("\nV3 = ");
    for (i=0; i<10; i++){
        printf("%d", v3[i]);
        if (i<9){
            printf("-");
        }
    }
}
int main(){

    srand(time(NULL));
    int v1[5] = {0};
    int v2[5] = {0};
    int v3[10] = {0};

    carga_vector(v1, v2);
    concatenar(v1, v2, v3);
    mostrar_vector(v1, v2, v3);

    printf("\n");

return 0;
}
