/*Escribe un programa en el que se defina un vector de 10 punteros a float,
se lean diez números en las ubicaciones en las que hacen referencia cada uno
de los punteros del vector de punteros. Cuando este completo, se sumen todos
los números y se almacene el resultado en una dirección a la que haga referencia
un puntero ajeno al vector. El programa deberá mostrar el contenido de todas
las variables, tanto los punteros como los datos de tipo float.*/
#include <stdio.h>

int main(){

    int i;
    float datos[10] = {0};
    float *p[10];
    float suma = 0;
    float *pres;

    for (i=0; i<10; i++){
        p[i] = &datos[i];
    }

    //Cargar valores
    printf("Ingrese 10 numeros:\n");
    for (i=0; i<10; i++){
        printf("p[%d] = ", i);
        scanf("%f", p[i]);
    }

    for (i=0; i<10; i++){
        suma += *p[i];
    }

    pres = &suma;

    printf("\n\t***RESULTADOS***\n");

    for (i=0; i<10; i++){

        printf("p[%d] --> Direccion: %p | Valor: %.2f\n", i, p[i], *p[i]);

        }

        printf("\nSuma:\n");

        printf("pres --> Direccion: %p | Valor: %.2f\n", pres, *pres);

return 0;
}
