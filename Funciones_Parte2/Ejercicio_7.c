#include <stdio.h>

//Programa de procesamiento de datos y cálculo de ganancias.

int id_producto(int id){
    printf("Numero de identificacion del producto:\n");
    scanf("%d", &id);

    while (id < 0 || id > 999){
        printf("Ingreso invalido... Intente nuevamente\n");
        scanf("%d", &id);
    }

    return id;
}

float calculo_ganancias(float costo, float venta, int cantidad){

    return (venta - costo) * cantidad;
}

int main(){

int id=0, cant=0;
int prod_procesado=0;
float c=0, v=0;
float tot_ganancias=0;

    do {

    id = id_producto(id);

    if (id != 0){
    prod_procesado++;

    printf("Precio de costo:\n");
    scanf("%f", &c);

    printf("Precio de venta:\n");
    scanf("%f", &v);

    printf("Cantidad vendida:\n");
    scanf("%d", &cant);

    tot_ganancias += calculo_ganancias(c, v, cant);
    }

    } while (id != 0);

    printf("Se procesaron %d productos, las ganancias obtenidas fueron $%.2f\n", prod_procesado, tot_ganancias);

return 0;
}
