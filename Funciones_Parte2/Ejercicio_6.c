#include <stdio.h>

#define PI 3.14

//PROGRAMA DE CÁLCULO DE SUPERFICIES

int lee_opcion(int * op){
    scanf("%d", op);

    while (*op < 0 || *op > 5){
        printf("Opcion invalida. Intente de nuevo...\n");
        scanf("%d", op);
    }

return *op;
}

void menu(){

printf("\tCALCULO DE SUPERFICIES\n");
printf("\t**********************\n\n");
printf("1. Cuadrado\n");
printf("2. Circulo\n");
printf("3. Rectangulo\n");
printf("4. Trapecio\n");
printf("5. Triangulo\n");
printf("0. Salir del programa\n");

}

int cuadrado(int * lado){
    printf("Ingrese la longitud del lado del cuadrado:\n");
    scanf("%d", lado);

    return (*lado) * (*lado);
}

float circulo(int * radio){
    printf("Ingrese el radio del circulo:\n");
    scanf("%d", radio);

    return PI * (*radio) * (*radio);
}

int rectangulo(int * base, int * altura){
    printf("Ingrese la base y la altura del rectangulo:\n");
    scanf("%d %d", base, altura);

    return (*base) * (*altura);
}

float trapecio(int * b1, int * b2, int * altura){
    printf("Longitud de las bases A y B:\n");
    scanf("%d %d", b1, b2);
    printf("Altura del trapecio:\n");
    scanf("%d", altura);

    return (float)((*b1 + *b2) * (*altura))/2;
}

float triangulo(int * base, int * altura){
    printf("Ingrese base y altura del triangulo:\n");
    scanf("%d %d", base, altura);

    return (float)((*base) * (*altura))/2;
}

int main(){

int op;
int lado, radio, base, base1, base2, altura;
int res1, res3;
float res2, res4, res5;

do {

menu();

printf("Ingrese una opcion: ");
lee_opcion(&op);

switch (op){

case 1:
    res1 = cuadrado(&lado);
    printf("Area del cuadrado: %d metros cuadrados.\n", res1);
    break;

case 2:
    res2 = circulo(&radio);
    printf("Area del circulo: %.2f metros cuadrados.\n", res2);
    break;

case 3:
    res3 = rectangulo(&base, &altura);
    printf("Area del rectangulo: %d metros cuadrados.\n", res3);
    break;

case 4:
    res4 = trapecio(&base1, &base2, &altura);
    printf("Area del trapecio: %.2f metros cuadrados.\n", res4);
    break;

case 5:
    res5 = triangulo(&base, &altura);
    printf("Area del triangulo: %.2f metros cuadrados.\n", res5);
    break;

    }

} while (op != 0);

printf("Saliendo...\nGracias por utilizar nuestro programa!\n");

return 0;
}
