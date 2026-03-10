#include <stdio.h>
#include <stdlib.h>

//Cuál es el valor final de todas las variables en este programa?

int main ()
{

int a , b , *p , *q , *r ;
char c , d , *m , *n ;

a = 5 ;
b = 7 ;
q = &a ;
p = q ;
*p = b ; //Modifica tanto a "b" como a "a".
printf ( " % d\n " , *q ) ;
r = &b ;
*r = *q ;
printf ( " a = %d , b = %d , *p = %d , *q = %d , *r = %d\n", a, b, *p, *q, *r) ;
c = 'A' ;
d = 'B' ;
m = &c ;
n = &d ;
*m = *n ; //Se asigna el valor que guarda "n" a todas las demas variables.
printf(" c = %c , d = %c , *m = %c , *n = %c\n", c, d, *m, *n);

return 0 ;
}
