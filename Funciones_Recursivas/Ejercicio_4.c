#include <stdio.h>

// Calcula el término n de la sucesión de Fibonacci usando recursividad
int fibonacci(int n) {
    if (n == 1)
        return 1;
    else if (n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    printf("Ingrese la posicion n (n >= 1): ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Error: n debe ser mayor o igual a 1\n");
        return 1;
    }

    printf("El termino %d de Fibonacci es: %d\n", n, fibonacci(n));

    return 0;
}
