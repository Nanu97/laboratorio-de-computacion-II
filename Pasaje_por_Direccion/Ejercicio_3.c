#include <stdio.h>
#include <stdlib.h>

//Función para calcular máximo, mínimo y media implementando punteros.

void maxmin_media (int x1, int x2, int * max, int * min, float * var_media);

int main(){

    int a=0, b=0, max=0, min=0;
    float var_media;

    printf("Ingrese dos numeros: \n");
    scanf("%d %d", &a, &b);

    maxmin_media(a, b, &max, &min, &var_media);
    printf("Maximo: %d y Minimo: %d\n", max, min);
    printf("La media entre ambos numeros es igual a %.2f\n", var_media);

return 0;
}

void maxmin_media (int x1, int x2, int * max, int * min, float * var_media){

if (x1 > x2) {
    *max = x1;
    *min = x2;
}
    else {
        *max = x2;
        *min = x1;
    }

    *var_media = (float)(x1+x2)/2;

}
