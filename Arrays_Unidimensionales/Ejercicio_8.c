#include <stdio.h>

//Completa e implementa el siguiente programa. Después de cada asignación emite dirección y contenido.

int main(){

    int v[5];
    int *p;

    p = &v[0];

    *p = 1;
    printf("Direccion: %p | Valor: %d\n", p, *p);         //COMPLETADO  

    *(p+1) = 2;
    printf("Direccion: %p | Valor: %d\n", p+1, *(p+1));   //COMPLETADO

    *(p+2) = 3;
    printf("Direccion: %p | Valor: %d\n", p+2, *(p+2));   //COMPLETADO

return 0;
}
