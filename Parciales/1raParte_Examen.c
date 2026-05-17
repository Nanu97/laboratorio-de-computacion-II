/*
Nota:
    1. Los nombres de los campos de los struct son aclaratorios, pueden simplificase.
    2. Los nombres de los arrays son aclaratorios pueden simplificarse.
    3. No utilizar variables globales.
    4. No eliminar la consigna comentada.
    5. Al terminar, subir al campus solo el codigo fuente. No subir los .exe
*/
/*1era. parte del parcial

Tema: N-Z- Datos:  (FIL=5, COL=6, MES=30)*/

/*
Escenario: Una agencia de viajes tiene FIL sucursales.
Cada punto esta ubicado en barrios de CABA.
A fin de cada mes, se necesita procesar operaciones sobre los
ingresos obtenidos por los viajes vendidos.
Construir un programa en lenguaje C con las siguientes caracteristicas:
*/
/*
punto 1. Se define un array de dimesion FIL de tipo struct con los siguientes campos que se deben cargar con
datos en la misma linea, considerando que los ultimos 3, deben completarse con ceros:
Id_agencia - entero
barrio  - cadena
ingresos_por_dia -  array de flotantes de dimesion MES -> (inicialmente vacio)
total_del_mes - flotante -> (inicialmente campo vacio)
promedio_de_COL_meses - flotante -> (inicialmente campo vacio)
*/

//Alumno: Rodriguez, Nahuel

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FIL 5
#define COL 6
#define MES 30

typedef struct agencia{

    int id;
    char barrio[20];
    float ipd[MES];
    float totalMes;
    float promedio;

}agencia;

/*
punto 2. Se define un array de dimesion FIL de tipo struct con los siguientes campos que se deben cargar con
datos en la misma linea:
Id_agencia - entero
nombre_del_empleado � cadena
nombre_del_gerente � cadena
*/

typedef struct empleado{

    int id;
    char empleado[20];
    char gerente[20];

}empleado;

/* punto 3. Se define un puntero. Se crea un array din�mico de una dimensi�n
con FIL posiciones, luego se almacena el valor -1 en todas las posiciones
y se emite. Construir la funci�n de liberaci�n de memoria. */

int* creoAux(){

    int* vaux = (int*)malloc(FIL * sizeof(int));
    if (vaux == NULL){
        printf("Error: No hay suficiente espacio\n");
        exit(-1);
    }

    return vaux;
}

void cargoAux(int vaux[]){

    int i;

    for (i=0; i<FIL; i++){
        vaux[i] = -1;
    }
}

void emitoAux(int vaux[]){

    int i;

    printf("ARRAY DE POSICIONES\n\n");

    for (i=0; i<FIL; i++){
        printf("%d | ", vaux[i]);
    }
    printf("\n");
}

void liberoMemAux(int vaux[]){

    free(vaux);
}

/* punto 4. Se define un puntero a puntero Se crea una matriz din�mica de FIL filas por COL columnas,
luego se carga la matriz con valores aleatorios que representan
los totales de 6 meses anteriores por cada agencia y se emite.
Construir la funci�n de liberaci�n de memoria. */

float** creoMatriz(){

    int i;

    float** matriz = (float**)malloc(FIL * sizeof(float*));
        if (matriz == NULL){
            printf("Error: No hay suficiente espacio\n");
            exit(-1);
        }

    for (i=0; i<FIL; i++){
        matriz[i] = (float*)malloc(COL * sizeof(float));
        if (matriz[i] == NULL){
            printf("Error: No hay suficiente espacio\n");
            exit(-1);
        }
    }

    return matriz;
}

void cargoMatriz(float** m){

    int i, j;

    for (i=0; i<FIL; i++){
        for (j=0; j<COL; j++){
            m[i][j] = 10 + rand() % 90;
        }
    }
}

void emitoMatriz(float** m){

    int i, j;

    printf("\nVECTOR BIDIMENSIONAL DINAMICO\n");

    for (i=0; i<FIL; i++){
        printf("\n");
        for (j=0; j<COL; j++){
            printf("$%.2f | ", m[i][j]);
        }
    }
}

void liberoMemMatriz(float** m){

    int i;

    for (i=0; i<FIL; i++){
        free(m[i]);
    }

    free(m);
}

/* punto 5. Se carga, en forma aleatoria, el arrays de ingresos por d�a de cada agencia. */

void cargoIngresos(agencia a[]){

    int i, j;

    for (i=0; i<FIL; i++){
        for (j=0; j<MES; j++){
            a[i].ipd[j] = 10 + rand() % 30;
        }
    }
}

/* punto 6. Se emite array de agencias */

void emitoAgencia(agencia a[]){

    int i, j, k;

    printf("\n\n***************************\n");
    printf("INFORMACION DE LAS AGENCIAS\n");
    printf("***************************\n");

    for (i=0; i<FIL; i++){
        printf("\nID Agencia: %d\n", a[i].id);
        printf("Barrio: %s\n", a[i].barrio);

        printf("\nIngresos por dia:");

        for (j=0; j<MES; j++){
            if (j % 10 == 0){
                printf("\n");
            }
            printf("$%.2f | ", a[i].ipd[j]);
        }

        printf("\n\nTotal del Mes: $%.2f\n", a[i].totalMes);
        printf("Promedio de %d meses: $%.2f\n", COL, a[i].promedio);
        printf("\n");
        for (k=0; k<89; k++){
            printf("-");
        }
        printf("\n");
    }
}

/* punto 7. Se emite array de empleados*/

void emitoEmpleados(empleado b[]){

    int i;

    printf("\n************************\n");
    printf("INFORMACION DE EMPLEADOS\n");
    printf("************************\n");

    for (i=0; i<FIL; i++){
        printf("\nID Agencia: %d\n", b[i].id);
        printf("Nombre del empleado: %s\n", b[i].empleado);
        printf("Nombre del Gerente: %s\n", b[i].gerente);
    }
}

int main(){
    srand(time(NULL));

    //Punto 1*

    agencia ag[FIL] = {
        {1, "Palermo", {0}, 0, 0},
        {2, "Belgrano", {0}, 0, 0},
        {3, "Liniers", {0}, 0, 0},
        {4, "Nunez", {0}, 0, 0},
        {5, "Avellaneda", {0}, 0, 0}
    };

    //Punto 2*

    empleado emp[FIL] = {

        {1, "Nahuel", "Belen"},
        {2, "Sebastian", "Monica"},
        {3, "Lucas", "Agustina"},
        {4, "Pipo", "Leandro"},
        {5, "Marcos", "Julia"}
    };

    int* vauxiliar = NULL;
    vauxiliar = creoAux();
    cargoAux(vauxiliar);
    emitoAux(vauxiliar);

    float** matriz = NULL;
    matriz = creoMatriz();
    cargoMatriz(matriz);
    emitoMatriz(matriz);

    cargoIngresos(ag);
    emitoAgencia(ag);
    emitoEmpleados(emp);

    liberoMemAux(vauxiliar);
    liberoMemMatriz(matriz);

    return 0;
}
