#include <stdio.h>

//Simulador Básico de Cajero Automático

void mostrar_menu(){

    printf("\tCAJERO AUTOMATICO\n");
    printf("\t*****************\n\n");
    printf("1- Sacar Dinero\n");
    printf("2- Depositar Dinero\n");
    printf("3- Consultar Saldo\n");
    printf("4- Cambiar Clave\n");

}

float retirar_dinero(){

float monto;

    printf("Ingrese el monto que desea retirar: ");
    scanf("%f", &monto);

    while (monto <=0) {
        printf("No puede retirar una cantidad menor o igual a cero. Intente de nuevo\n");
        scanf("%f", &monto);
    }

    return monto;
}

float depositar_dinero(){

float deposito;

    printf("Ingrese el monto que desea depositar: ");
    scanf("%f", &deposito);

     while (deposito <=0) {
        printf("No puede depositar una cantidad menor o igual a cero. Intente de nuevo\n");
        scanf("%f", &deposito);
    }

    return deposito;
}

int cambiar_clave(){

int nueva_clave;
int vieja_clave;

    printf("Contrasena actual: \n");
    scanf("%d", &vieja_clave);

    printf("\nNueva contrasena: \n");
    scanf("%d", &nueva_clave);

    while (nueva_clave == vieja_clave){
        printf("La nueva contrasena no puede ser igual a la anterior. Intente de nuevo\n");
        scanf("%d", &nueva_clave);
    }

    return nueva_clave;
}

int main(){

int op=0, tipo=0, clave;
float retiro, deposito;

    mostrar_menu();
    printf("Ingrese una opcion (1-4):\n");
    scanf("%d", &op);

    while (op<1 || op>4) {
        printf("Opcion invalida. Intente de nuevo\n");
        scanf("%d", &op);
    }

switch (op){

case 1:
    retiro = retirar_dinero();
    printf("Importe retirado: $%.2f\n", retiro);
    break;

case 2:
    deposito = depositar_dinero();
    printf("Importe depositado (en pesos argentinos): $%.2f\n", deposito);
    break;

case 3:
    printf("Seleccione el tipo de cuenta que desea consultar: ");
    printf("1) Caja de Ahorro o 2) Cuenta Corriente\n");
    scanf("%d", &tipo);

    while (tipo != 1 && tipo != 2){
        printf("Opcion invalida. Intente de nuevo\n");
        scanf("%d", &tipo);
    }

    if (tipo == 1){
        printf("Saldo disponible en Caja de Ahorro: $7500\n");
    } else {
        printf("Saldo disponible en Cuenta Corriente: $25760.46\n");
    }

    break;

case 4:
    clave = cambiar_clave();
    printf("Cambio de clave realizado con exito!\n");
    printf("Su nueva clave es: %d\n", clave);
    break;

}

return 0;
}
