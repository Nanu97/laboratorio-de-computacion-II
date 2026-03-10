#include <stdio.h>
#include <stdlib.h>

/*
a) ¿Qué valor tiene a al finalizar el programa? 0.002
b) ¿Qué valor tiene b al finalizar el programa? 0.003
c) ¿Qué valor tiene c al finalizar el programa? 0.003
d) ¿Qué valor tiene (*pa) al finalizar el programa? 0.002
e) ¿Qué valor tiene (*pb) al finalizar el programa? 0.003
*/

int main()
{

float a = 0.001, b = 0.003;
float c, *pa, *pb;
pa = &a;
*pa = 2 * a;
pb = &b;
c = 3 * (*pb - *pa);

printf("Valor de a: %.3f\n", a);
printf("Valor de b: %.3f\n", b);
printf("Valor de c: %.3f\n", c);
printf("Valor de *pa: %.3f\n", *pa);
printf("Valor de *pb: %.3f\n", *pb);

    return 0;
}
