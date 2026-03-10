#include <stdio.h>
#include <stdlib.h>

/*Construye el siguiente programa, paso a paso:

a. Declara a, b y c variables enteras, y p, q y r variables puntero a entero.

b. Declara m, n variables de tipo float y s y t variables puntero a float.

c. Asigna a p la dirección de a y a q la dirección de b.

d. Asigna a b el valor 40 usando el puntero q. Mostrar el valor de b, la dirección de b , el valor de q, la dirección de q y el valor contenido en la dirección almacenada en q.

e. Ingresar desde teclado el valor de a usando su dirección almacenada. Mostrar el valor de a, la dirección de a, el valor de p, la dirección de p y el valor contenido en la dirección almacenada en p.

f. Asigna a r la dirección de a.

g. Asigna a la posición de memoria contenida en el puntero r el valor 200. Mostrar el valor de a, la dirección de a , el valor de p, la dirección de p y el valor contenido en la dirección almacenada en p, y el valor de r, la dirección de r y el valor
 contenido en la dirección almacenada en r.

h. Emite un mensaje indicando si el valor del puntero p es igual al valor del puntero q.

i. Ídem h indicando si el valor del puntero p es igual al valor del puntero r.

j. Declara una variable de tipo puntero a entero y una variable entera. Asígnale un valor a la variable entera. Guarda la dirección. Luego lee el contenido de la variable puntero y muéstralo en hexadecimal.*/

int main()
{

int a, b, c;
int *p, *q, *r;

float m, n;
float *s, *t;

p = &a;
q = &b;

*q = 40;

printf("\tINCISO D\n");
printf("\t********\n\n");
printf("Valor de b: %d\n", b);
printf("Direccion de b: %p\n", &b);
printf("Valor de q: %p\n", q);
printf("Direccion de q: %p\n", &q);
printf("Valor contenido en la direccion almacenada en q: %d\n\n", *q);

printf("\tINCISO E\n");
printf("\t********\n\n");
printf("Ingresa un valor para a: ");
scanf("%d", p);
printf("Valor de a: %d\n", a);
printf("Direccion de a: %p\n", &a);
printf("Valor de p: %p\n", p);
printf("Direccion de p: %p\n", &p);
printf("Valor contenido en la direccion almacenada en p: %d\n\n", *p);

printf("\tINCISO G\n");
printf("\t********\n\n");

r = &a;
*r = 200;

printf("Valor de a: %d\n", a);
printf("Direccion de a: %p\n", &a);
printf("Valor de p: %p\n", p);
printf("Direccion de p: %p\n", &p);
printf("Valor contenido en la direccion almacenada en p: %d\n", *p);
printf("Valor de r: %p\n", r);
printf("Direccion de r: %p\n", &r);
printf("Valor contenido en la direccion almacenada en r: %d\n\n", *r);

printf("\tINCISO H\n");
printf("\t********\n\n");

if (p == q) {
    printf("p y q apuntan a la misma direccion\n");
}
else {
    printf("p y q apuntan a direcciones diferentes\n");
}

printf("\n\tINCISO I\n");
printf("\t********\n\n");

if (p == r) {
    printf("p y r apuntan a la misma direccion\n");
}
else {
    printf("p y r apuntan a direcciones diferentes\n");
}

printf("\n\tINCISO J\n");
printf("\t********\n\n");

int *my_p;
int var;

var = 777;
my_p = &var;

printf("Contenido de la variable puntero en hexadecimal: %p\n", my_p);

    return 0;
}
