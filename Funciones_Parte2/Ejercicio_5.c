#include <stdio.h>
#include <stdlib.h>

/*Escribe dos funciones: Cada una de ellas debe calcular la superficie de un rectángulo
en función de la base y la altura (ambos datos tipo int). La primera función llamada area1()
recibe los argumentos por valor y la segunda, area2(), por referencia. Los resultado se deben emitir en la función main()*/

int area1(int b, int h){

return b * h;
}

void area2(int b, int h, int*sup){

    *sup = b * h;
}

int main(){

int b, h;
int res1, res2;

printf("Ingrese la base y la altura:\n");
scanf("%d %d", &b, &h);

//Paso por valor
res1 = area1(b, h);
printf("Superficie del rectangulo: %d metros cuadrados.\n", res1);

//Paso por referencia
area2(b, h, &res2);
printf("Superficie del rectangulo: %d metros cuadrados.\n", res2);


return 0;
}
