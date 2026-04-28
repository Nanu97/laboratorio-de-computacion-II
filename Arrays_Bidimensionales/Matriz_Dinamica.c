//Creación de una matriz dinámica y cálculos variados.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define F 2
#define C 3

int** creoMatriz(){

    int i;
    int** m = (int**)malloc(F * sizeof(int*));
    if (m == NULL){
        printf("Insuficiente espacio de memoria\n");
        exit(-1);
    }

    for (i=0; i<F; i++){
        m[i] = (int*)malloc(C * sizeof(int));
        if (m[i] == NULL){
            printf("Insuficiente espacio de memoria\n");
            exit(-1);
        }
    }
    return m;
}

void cargoMatriz(int** m){

    int i, j;

    for (i=0; i<F; i++){
        for (j=0; j<C; j++){
            m[i][j] = rand () % 10;
        }
    }
}

void emitoMatriz(int** m){

    int i, j;

    for (i=0; i<F; i++){
        printf("\n");
        for (j=0; j<C; j++){
            printf("%d | ", m[i][j]);
        }
    }
    printf("\n");
}

void liberoMemMatriz(int** m){

    int i;

    for (i=0; i<F; i++){
        free(m[i]);
    }
    free(m);
}

int contadorCeros(int** m){

    int i, j;
    int ceros = 0;

    for (i=0; i<F; i++){
        for (j=0; j<C; j++){
            if (m[i][j] == 0){
                ceros++;
            }
        }
    }
    return ceros;
}

int* creoVecAux(){

    int* vaux = (int*)malloc(C * sizeof(int));
    if (vaux == NULL){
        printf("Insuficiente espacio de memoria\n");
        exit(-1);
    }
    return vaux;
}

int* creoVecAux2(){

    int* vaux2 = (int*)malloc(F * sizeof(int));
    if (vaux2 == NULL){
        printf("Insuficiente espacio de memoria\n");
        exit(-1);
    }
    return vaux2;
}

void cargoVecAux(int** m, int vaux[]){

    int i, j;

    for (i=0; i<C; i++){
        int mayor = 0;
        for (j=0; j<F; j++){
            if (m[j][i] > m[mayor][i]){
                mayor = j;
            }
        }
        vaux[i] = mayor;
    }
}

void cargoVecAux2(int** m, int vaux2[]){

    int i, j;

    for (i=0; i<F; i++){
        int mayor = 0;
        for (j=0; j<C; j++){
            if (m[i][j] > m[i][mayor]){
                mayor = j;
            }
        }
        vaux2[i] = mayor;
    }
}

void emitoMaxColumna(int** m, int vaux[]){

    int i;
    int max=0;

    printf("\n***Maximos por columna***\n");
    printf("-------------------------\n");
    for (i=0; i<C; i++){
        max = vaux[i];
        printf("Columna %d: el maximo es %d\n", i, m[max][i]);
    }
}

void emitoMaxFila(int** m, int vaux2[]){

    int i;
    int max=0;

    printf("\n***Maximos por fila***\n");
    printf("----------------------\n");
    for (i=0; i<F; i++){
        max = vaux2[i];
        printf("Fila %d: el maximo es %d\n", i, m[i][max]);
    }
}

int minMatriz(int** m){

    int i, j;
    int min = m[0][0];

    for (i=0; i<F; i++){
        for (j=0; j<C; j++){
            if (m[i][j] < min){
                min = m[i][j];
            }
        }
    }
    return min;
}

float promMatriz(int** m){

    int i, j;
    int suma=0;
    float prom=0.0;

    for (i=0; i<F; i++){
        for (j=0; j<C; j++){
            suma+= m[i][j];
        }
    }
    prom = (float)suma/(F*C);
    return prom;
}

float* creoVecAux3(){

    float* vaux3 = (float*)malloc(C * sizeof(float));
    if (vaux3 == NULL){
        printf("Insuficiente espacio de memoria\n");
        exit(-1);
    }
    return vaux3;
}

void cargoVecAux3(int** m, float vaux3[]){

    int i, j;
    float suma = 0.0;
    float prom = 0.0;

    for (i=0; i<C; i++){
        suma = 0.0;
        for (j=0; j<F; j++){
            suma+= m[j][i];
        }
        vaux3[i] = (float)suma/F;
    }
}

void emitoPromCol(float vaux3[]){

    int i;

    printf("\n***Promedio por columna***\n");
    printf("--------------------------\n");
    for (i=0; i<C; i++){
        printf("Columna %d: Promedio --> %.2f\n", i, vaux3[i]);
    }
}

float* creoVecAux4(){

    float* vaux4 = (float*)malloc(F * sizeof(float));
    if (vaux4 == NULL){
        printf("Insuficiente espacio de memoria\n");
        exit(-1);
    }
    return vaux4;
}

void cargoVecAux4(int** m, float vaux4[]){

    int i, j;
    float suma = 0.0;
    float prom = 0.0;

    for (i=0; i<F; i++){
        suma = 0.0;
        for (j=0; j<C; j++){
            suma+= m[i][j];
        }
        vaux4[i] = (float)suma/C;
    }
}

void emitoPromFil(float vaux4[]){

    int i;

    printf("\n***Promedio por fila***\n");
    printf("-----------------------\n");
    for (i=0; i<F; i++){
        printf("Fila %d: Promedio --> %.2f\n", i, vaux4[i]);
    }
}

int main(){
    srand(time(NULL));

    printf("MATRIZ DE %d x %d\n", F, C);

    int** matriz = NULL;
    matriz = creoMatriz();
    cargoMatriz(matriz);
    emitoMatriz(matriz);
    int ceros;
    ceros = contadorCeros(matriz);

    printf("\nLa cantidad de ceros dentro de la matriz es: %d\n", ceros);

    int* vauxiliar = NULL;
    vauxiliar = creoVecAux();
    cargoVecAux(matriz, vauxiliar);
    emitoMaxColumna(matriz, vauxiliar);

    int* vauxiliar2 = NULL;
    vauxiliar2 = creoVecAux2();
    cargoVecAux2(matriz, vauxiliar2);
    emitoMaxFila(matriz, vauxiliar2);
    int minimo;
    minimo = minMatriz(matriz);

    printf("\nEl valor minimo perteneciente a la matriz es: %d\n", minimo);

    float promedio;
    promedio = promMatriz(matriz);

    printf("\nEl promedio de la matriz es: %.2f\n", promedio);

    float* vauxiliar3 = NULL;
    vauxiliar3 = creoVecAux3();
    cargoVecAux3(matriz, vauxiliar3);
    emitoPromCol(vauxiliar3);

    float* vauxiliar4 = NULL;
    vauxiliar4 = creoVecAux4();
    cargoVecAux4(matriz, vauxiliar4);
    emitoPromFil(vauxiliar4);

    free(vauxiliar);
    free(vauxiliar2);
    free(vauxiliar3);
    free(vauxiliar4);
    liberoMemMatriz(matriz);

    return 0;
}
