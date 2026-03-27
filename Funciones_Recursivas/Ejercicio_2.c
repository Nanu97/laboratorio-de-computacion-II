#include <stdio.h>

// Función recursiva que imprime los factores primos de un número
void factoresPrimos(int n, int d) {

    if (n == 1) {
        return; // caso base
    }

    if (n % d == 0) {
        printf("%d\n", d);
        factoresPrimos(n / d, d);
    } else {
        factoresPrimos(n, d + 1);
    }
}

int main() {
    int numero = 12;

    printf("Factores primos de %d:\n", numero);
    factoresPrimos(numero, 2);

    return 0;
}
