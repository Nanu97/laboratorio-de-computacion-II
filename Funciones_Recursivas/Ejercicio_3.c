#include <stdio.h>

// Calcula el Máximo Común Divisor (MCD) de dos enteros usando recursividad
int mcd(int a, int b) {
    if (a == b)
        return a;
    else if (a < b)
        return mcd(a, b - a);
    else
        return mcd(a - b, b);
}

int main() {
    int a, b;

    printf("Ingrese el primer numero: ");
    scanf("%d", &a);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &b);

    printf("El MCD de %d y %d es: %d\n", a, b, mcd(a, b));

    return 0;
}
