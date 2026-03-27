#include <stdio.h>

// Función recursiva que suma dos números enteros
int sumaRecursiva(int a, int b) {
    int s;

    if (b == 0)
        s = a;                     // caso base
    else
        s = sumaRecursiva(a, b - 1) + 1; // caso recursivo

    return s;
}

int main() {
    int a, b;

    printf("Ingrese el primer numero: ");
    scanf("%d", &a);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &b);

    printf("El resultado es: %d\n", sumaRecursiva(a, b));

    return 0;
}
