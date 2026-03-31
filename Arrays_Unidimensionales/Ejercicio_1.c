#include<stdio.h>

/*Carga del vector*/
void carga_vector(int v[], int d){
int i;
for(i = 0; i < d ; i++){
    printf("Ingrese valor en v[%d]\n", i) ;
    scanf("%d", &v[i]);
 }
}

/*emisión del contenido del vector*/
void emite_vector(int v[], int d){
int i;
for(i = 0; i < d ; i++)
     printf("v[%d]=%d\n", i, v[i]);
}

/*Suma de los elementos del vector*/
int suma_vector(int v[], int d){
int i,suma=0;

for(i = 0; i < d ; i++)
     suma = suma + v[i];

  return suma;
}

int minimo_vector(int v[], int d){
int min, i;

    min = v[0];

    for (i=1; i<d; i++){

        if (v[i] < min){
            min = v[i];
        }

    }

  return min;
}

int maximo_vector(int v[], int d){
int max, i;

    max = v[0];

    for (i=1; i<d; i++){

        if (v[i] > max){
            max = v[i];
        }
    }

    return max;
}

/*emisión de los elementos en las posiciones impares*/
void elem_pos_impar(int v[], int d){
int i;
printf("\nLos elementos en las posiciones impares son:\n");
for(i = 0; i < d ; i++){
    if (i%2 == 1)
         printf("v[%d]=%d\n", i, v[i]);
}
}

/*emisión de los elementos en las posiciones pares*/
void elem_pos_par(int v[], int d){
int i;
printf("\nLos elementos en las posiciones pares son:\n");
for(i = 0; i < d ; i++){
    if (i%2 == 0)
         printf("v[%d]=%d\n", i, v[i]);
}
}

int buscador(int v[], int d, int a){

int i = 0;

    while (i<d && v[i] != a){
        i++;
    }

    if (i == d){
        return -1;
    }
    else {
        return i+1;
    }

}

int main(){
  const int dim = 5;
  int v[dim];
  int suma;
  int minimo, maximo;
  float promedio;
  int apariciones = 0;
  int a, resultado;

/*a.	Cargar un vector de m elementos por teclado.
Debes considerar que no podrá superar el máximo de elementos de vector (m=dimensión).
*/
carga_vector(v, dim);

/*emitimos el contenido del vector para testear*/
emite_vector(v, dim);

/*b.	Calcular y emitir la suma de sus elementos. */
suma = suma_vector(v, dim);

printf("\nLa suma de los elementos del vector es %d\n", suma);

//c. Calcular y emitir el mínimo del vector.
minimo = minimo_vector(v, dim);

printf("\nEl valor minimo dentro del vector es %d\n", minimo);

//d. Calcular y emitir el promedio de los valores del vector y los valores de aquellos que superaron ese promedio.
promedio = (float)suma / dim;

printf("\nEl valor promedio de los valores del vector es %.2f\n", promedio);

printf("\nValores que superaron el promedio: ");

for (int i=0; i<dim; i++){

    if (v[i] > promedio){
        printf("%d ", v[i]);
    }

}

printf("\n");

//e. Emitir el valor máximo, indicar la cantidad de veces que apareció y el número de orden en que fue ingresado.
maximo = maximo_vector(v, dim);

for (int i=0; i<dim; i++){

    if (v[i] == maximo){
        apariciones++;
    }

}

printf("\nEl valor maximo dentro del vector es %d y aparece %d veces\n", maximo, apariciones);

printf("y se encuentra en las posiciones: ");
for (int i=0; i<dim; i++){

    if (v[i] == maximo){
        printf("%d ", i);
    }

}

printf("\n");

/*f.	Emitir los valores que son pares y los que están en posiciones impares (completar) */
elem_pos_impar(v, dim);

elem_pos_par(v, dim);

//g. Recorrer los elementos del vector hasta encontrar el número entero a que se ingresa por teclado.
// Deberá retornar el número de elementos que ha leído hasta encontrar a. Si no lo encontró emitir
// un mensaje al respecto.

printf("\nIngrese un valor entero 'a' que luego sera buscado dentro del array\n");
scanf("%d", &a);

resultado = buscador(v, dim, a);

if(resultado == -1){
    printf("\nEl numero %d no se encuentra dentro del vector!\n", a);
}
else{
    printf("\nSe han leido %d elementos hasta encontrar el valor buscado\n", resultado);
}

return 0;
}
