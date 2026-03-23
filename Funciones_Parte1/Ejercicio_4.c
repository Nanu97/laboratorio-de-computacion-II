#include <stdio.h>
#include <stdlib.h>

double potencia(double base, int exp){ //Función que eleva un número a la "n" (siendo n>0).

int i;
double pot;

pot = 1;

for (i=0; i<exp; i++) pot = pot * base;

return pot;
}

int main(){

int n;
double x, pot;

printf("\nIntroduzca la base y el exponente: ");
scanf("%lf %d", &x, &n);

pot = potencia(x, n);

printf("\nLa potencia es %lf", pot);

return 0;
}
