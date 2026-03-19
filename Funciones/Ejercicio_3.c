#include <stdio.h>
#include <stdlib.h>

int factorial(int n){ //Función que calcula el factorial de un número.

int i;
long fact;

fact = 1;

for (i=1; i<=n; i++) fact = fact * i;

return fact;
}

int main(){

int n;
int fact;

printf ("Ingrese un numero entero positivo:\n");
scanf ("%d", &n);

fact = factorial(n);
printf ("\nEl factorial de %d es: %ld\n",n,factorial(n));

return 0;
}
