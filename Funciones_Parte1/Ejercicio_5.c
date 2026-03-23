#include <stdio.h>
#include <stdlib.h>

void tabla_multiplicar(int n){

int i;

for (i=1; i<=10; i++) {
    printf("%d * %d = %d\n", n, i, n*i);
}

}

int main () {

int n;

    printf("Ingresa un numero entero: ");
    scanf("%d", &n);

    printf("\nTabla de multiplicar del %d:\n", n);
    tabla_multiplicar(n);

return 0;
}
