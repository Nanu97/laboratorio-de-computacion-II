/*Ídem anterior, pero los elementos de los dos vectores deben emitirse intercalados.
Ej: Ej: V4 = 2-7-56-80-7-2-8-4-30-13;*/
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

void intercalar(int * v1, int * v2, int * v3){

    int i, j=0, k=0;

    for (i=0; i<10; i++){

        if (i % 2 == 0){
            v3[i] = v1[j];
            j++;
        }
        else {
            v3[i] = v2[k];
            k++;
        }

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
    intercalar(v1, v2, v3);
    mostrar_vector(v1, v2, v3);

    printf("\n");

return 0;
}
