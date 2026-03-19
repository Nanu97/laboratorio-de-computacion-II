#include <stdio.h>
#include <stdlib.h>

//Función para calcular el máximo y mínimo implementando punteros.

void maxmin (int x1, int x2, int * max, int * min){

if (x1 > x2) {
    *max = x1;
    *min = x2;
}
    else {
        *max = x2;
        *min = x1;
    }

}

int main(){

    int a=0, b=0, max=0, min=0;

    printf("Ingrese dos numeros: \n");
    scanf("%d %d", &a, &b);

    maxmin(a, b, &max, &min);
    printf("El maximo entre %d y %d es %d. El minimo es %d\n", a, b, max, min);

return 0;
}
