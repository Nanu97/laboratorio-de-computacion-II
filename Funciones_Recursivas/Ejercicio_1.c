#include <stdio.h>

int sumaRecursiva(int a, int b) {
    int s;

    printf("Entrando: f(%d, %d)\n", a, b);

    if (b == 0) {
        s = a;
        printf("Caso base: retorno %d\n", s);
    }
    else {
        s = sumaRecursiva(a, b - 1) + 1;
        printf("Volviendo: f(%d, %d) = %d\n", a, b, s);
    }

    return s;
}

int main(){

int resultado;

resultado = sumaRecursiva(3, 5);

printf("Resultado final: %d\n", resultado);

return 0;
}
