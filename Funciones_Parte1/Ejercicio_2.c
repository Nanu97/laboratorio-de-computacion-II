#include <stdio.h>
#include <stdlib.h>

int maximo(int x, int y){ //Función que calcula el maximo entre dos numeros.

int max;

    if (x> y)
        max = x;
    else
        max = y;

return max;
}

int main()
{

int a, b, max;

printf("Ingrese dos numeros:\n");
scanf("%d %d", &a, &b);

    max = maximo(a, b);
    printf ("\nEl maximo de %d y %d es %d", a, b, max);

return 0;
}
