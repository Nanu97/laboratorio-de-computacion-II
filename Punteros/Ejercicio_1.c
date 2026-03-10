#include <stdio.h>
#include <stdlib.h>


int main()
{

int a, b, * pa;

    a = 5;
    pa = &a;
    b = *pa;

    printf("a = %d\n", a);
    printf("Direccion de memoria de a: %p\n", pa);
    printf("b = %d\n", b);

int i,j, *p;

    p = &i;
    *p = 21;
    p = &j;
    *p = 1;

    printf("Direccion de memoria de i: %p\n", &i);
    printf("Valor de i = %d\n", i);
    printf("Direccion de memoria de j: %p\n", &j);
    printf("Valor de j = %d\n", j);

    return 0;
}
