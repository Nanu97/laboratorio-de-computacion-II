/*Dado el array dinámico a de 5 elementos de tipo int, indicar qué instrucciones
se deben sustituir por el comentario |***Sustituir por el código correcto***| para
ampliar a 10 su número de elementos, sin perder la información que ya existía
almacenada en el array original y rellenando a 0 los nuevos elementos.
Suponer que no existirán problemas de falta de memoria.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
int *a=(int *)malloc(5*sizeof(int)), *b, i;

for (i=0; i<5; i++) a[i]=i*2; // son los valores iniciales del array

/* Sustituir por el código correcto */
b = (int*)malloc(10*sizeof(int));
for (i=0; i<5; i++) b[i] = a[i];
for (i=5; i<10; i++) b[i] = 0;
free(a);
a = b;

for (i=0; i<10; i++)
   printf("%d ", a[i]);

free(a);
return 0;
}
