/*Escribe una función que reciba un vector de enteros y su tamaño, y retorne la cantidad de números impares que contiene.
Trabaja con notación de punteros y utiliza ciclo while. //cabecera de función: int impares (int * v, int tam);*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAM 10

int impares(int * v, int tam){

    int i;
    int num;
    int cant_impares=0;

    for (i=0; i<tam; i++){

        num = 1 + rand() % 20;
        v[i] = num;
        printf("v[%d] = %d\n", i, num);

        if (v[i] % 2 == 1){
            cant_impares++;
        }
    }

    return cant_impares;
}

int main(){

    srand(time(NULL));
    int v[TAM] = {0};
    int cant_impares;

    cant_impares = impares(v, TAM);

    printf("\nEl vector tiene %d numeros impares\n", cant_impares);

return 0;
}
