#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<string.h>

#define FIL 4
#define COL 6
#define T 10

/* punto 1. */

typedef struct competidor{

    int id;
    char provincia[20];
    float tiempos[T];
    float promT;
    float maxProm;

}competidor;

/* punto 2.*/

typedef struct instructor{

    int id;
    char nombreCompetidor[20];
    char nombreInstructor[20];

}instructor;

/* punto 3. */

int* creoVecAux(){

    int* vaux = (int*)malloc(FIL * sizeof(int));
    if (vaux == NULL){
        printf("Insuficiente espacio de memoria\n");
        exit(-1);
    }
    return vaux;
}

void cargoVecAux(int vaux[]){

    int i;

    for (i=0; i<FIL; i++){
        vaux[i] = -1;
    }
}

void emiteVecAux(int vaux[]){

    int i;

    for (i=0; i<FIL; i++){
        printf("%d | ", vaux[i]);
    }
    printf("\n");
}

/*punto 4. */


/* punto 5. */

void cargaTiempos(competidor a[]){

    int i, j;

    for (i=0; i<FIL; i++){
        for (j=0; j<T; j++){
            a[i].tiempos[j] = 10 + rand() % 90;
        }
    }
}

/* punto 6.*/

void emiteComp(competidor a[]){

    int i, j;

    printf("\n***Competidores***\n");
    printf("------------------");

    for (i=0; i<FIL; i++){
        printf("\nID: %d | Provincia: %s\n", a[i].id, a[i].provincia);
        printf("Tiempos: ");
        for (j=0; j<T; j++){
            printf("%.2f | ", a[i].tiempos[j]);
        }
        printf("\nPromedio de tiempos del mes: %.2f\n", a[i].promT);
        printf("Maximo Promedio: %.2f\n", a[i].maxProm);
    }
}

/* punto 7.*/

void emiteIns(instructor b[]){

    int i;
    printf("\n***Instructores***\n");
    printf("------------------");

    for (i=0; i<FIL; i++){
        printf("\nID: %d\n", b[i].id);
        printf("Competidor a su cargo: %s\n", b[i].nombreCompetidor);
        printf("Instructor: %s\n", b[i].nombreInstructor);
    }
}

/* punto 8. */

void promedio_10Tiempos(competidor a[]){

    int i, j;
    float suma;

    for (i=0; i<FIL; i++){
        suma = 0.0;
        for (j=0; j<T; j++){
            suma += a[i].tiempos[j];
        }
        a[i].promT = (float)suma/T;
    }
}

/* punto 9. */

void promensual(competidor a[], float** m){

    int i, j;
    float max;

    for (i=0; i<FIL; i++){
        max = -9999;
        for (j=0; j<COL; j++){
            if (m[i][j] > max){
                max = m[i][j];
            }
        }
        a[i].maxProm = max;
    }
}

/* punto 10. */

int condicional(competidor a[], int vaux[]){

    int i;
    int c = 0;

    for (i=0; i<FIL; i++){
        if (a[i].promT < a[i].maxProm){
            vaux[c] = i;
            c++;
        }
    }
    return c;
}

/* punto 11 */

void cumpleCondicion(competidor a[], instructor b[], int vaux[], int cant){

    int i, j;
    int pos;

    printf("\nLas provincias que cumplieron la condicion fueron:\n");

    for (i=0; i<cant; i++){
        pos = vaux[i];
        for (j=0; j<FIL; j++){
            if (a[pos].id == b[j].id){
                printf("%s - cuyo instructor fue: %s\n", a[pos].provincia, b[j].nombreInstructor);
            }
        }
    }
}

/* punto 12 */

void ordenarComp(competidor a[]){

    int i, j, cambio;
    competidor aux;

    for (i=0; i<FIL-1; i++){
        cambio = 0;
        for (j=0; j<FIL-(i+1); j++){
            if (strcmp(a[j].provincia, a[j+1].provincia) > 0){
                aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
                cambio = 1;
            }
        }
        if (!cambio){
            break;
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

int main(){
srand(time(NULL));
/*1era. parte del primer parcial*/

/*
punto 1. Una organizacion de torneos deportivos, tiene inscriptos competidores, cada uno
representa provincias del pais. Para procesar los datos se construye un programa
y se define un array de FIL (dimension) struct con los siguientes datos:
*/
    competidor comp[FIL] = {
            {1, "Cordoba", {0}, 0, 0},
            {2, "Salta", {0}, 0, 0},
            {3, "Mendoza", {0}, 0, 0},
            {4, "Chubut", {0}, 0, 0}
    };

/*
punto 2. Ademas se construye otro array con los datos personales del instructor y competidor:
*/

    instructor ins[FIL] = {
            {4, "Aranda", "Zeballos"},
            {1, "Merentiel", "Gimenez"},
            {2, "Bareiro", "Romero"},
            {3, "Paredes", "Herrera"}
    };

/* punto 3. Se define, carga y emite dinamicamente un tercer array de enteros de
dimension = FIL que se inicializara con -1.*/

    int* vauxiliar = NULL;
    vauxiliar = creoVecAux();
    cargoVecAux(vauxiliar);
    emiteVecAux(vauxiliar);


/* punto 4. Por otra parte, se crea, almacenan en una array bidimensional dinamico de FIL filas
por COL columnas, y emiten, los promedios mensuales -obtenidos con anterioridad- por competidor (carga aleatoria)*/

    int i, j;

    float** matriz = NULL;
    matriz = (float**)malloc(FIL * sizeof(float*));
    if (matriz == NULL){
        printf("Insuficiente espacio de memoria\n");
        exit(-1);
    }

    for (i=0; i<FIL; i++){
        matriz[i] = (float*)malloc(COL * sizeof(float));
        if (matriz[i] == NULL){
            printf("Insuficiente espacio de memoria\n");
            exit(-1);
        }
    }

    for (i=0; i<FIL; i++){
        for (j=0; j<COL; j++){
            matriz[i][j] = 10 + rand() % 50;
        }
    }

/* punto 5. carga en forma aleatoria los tiempos de cada competidor del array comp*/

cargaTiempos(comp);
promedio_10Tiempos(comp);
promensual(comp, matriz);

/* punto 6. emite array de de competidores */

emiteComp(comp);

/* punto 7. emite array de de instructores */

emiteIns(ins);

/*2da parte del primer parcial*/

/* punto 8. Funcion que reciba  el vector de competidores y
cargue en el campo promT, el promedio del array tiempo */



/* punto 9. Funcion que reciba  el vector de competidores, la matriz de tiempos
mensuales y cargue en el campo 'maxprom', el maximo promedio de los tiempos
de los meses procesados.*/



/* punto 10. Funcion que reciba  el vector de competidores, el vector de enteros
y cargue en este vector, las posiciones de los registros del vector de competidores,
 cuyo  promT no supere al maxprom. Los datos deben almacenarse en forma contigua.*/

int cant;
cant = condicional(comp, vauxiliar);
printf("\nCantidad de competidores cuyo promT fue menor al maxProm: %d\n", cant);

/* punto 11. Funcion que reciba  el vector de competidores, vector de
instructor, vector de posiciones y la cantidad retornada en la funcion
anterior (en cant) y emita el campo provincia de los competidores
y el campo instructor.*/

cumpleCondicion(comp, ins, vauxiliar, cant);

/* punto 12. Funcion que reciba el vector de competidores y lo ordene por provincia
en forma ascendente.*/

ordenarComp(comp);
emiteComp(comp);

    free(vauxiliar);
    liberoMemMatriz(matriz);
    return 0;
}
