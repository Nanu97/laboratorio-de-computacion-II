#include <stdio.h>
#include <stdlib.h>

#define EMPLEADOS 8

void limpiarBuffer()
{
    int c;
    while ((c=getchar())!='\n'&&c!=EOF);
}

int main()
{

    int i;

    int legajo[EMPLEADOS];
    char nombre[EMPLEADOS][30];
    char sexo[EMPLEADOS];

    int horas[EMPLEADOS];
    int sueldoHora[EMPLEADOS];

    int sueldoBruto[EMPLEADOS];
    int sueldoNeto[EMPLEADOS];

    int obraSocial[EMPLEADOS];
    int jubilacion[EMPLEADOS];

    int totalHombres = 0;
    int totalMujeres = 0;

    int sumaHombres = 0;
    int sumaMujeres = 0;

    int totalObraSocial = 0;
    int totalJubilacion = 0;

    int mayor;
    int legajoMayor;

    printf("\t*****************************************\n");
    printf("\tPROGRAMA DE GESTION PARA PEQUENA COMPANIA\n");
    printf("\t*****************************************\n\n");

    //INGRESO DE DATOS
    for (i=0; i<EMPLEADOS; i++) {

        printf("EMPLEADO |%d|\n", i+1);
        printf("Numero de legajo(111-999): ");
        scanf("%d", &legajo[i]);
        limpiarBuffer();

        while (legajo[i]<111 || legajo[i]>999) {
            printf("Legajo invalido. Reingrese: ");
            scanf("%d", &legajo[i]);
            limpiarBuffer();
        }

    printf("Ingrese nombre: ");
    scanf("%s", nombre[i]);
    limpiarBuffer();

    printf("Sexo(M-F): ");
    scanf(" %c", &sexo[i]);
    limpiarBuffer();

    while (sexo[i] != 'M' && sexo[i] != 'F') {
        printf("Entrada invalida. Reingrese: ");
        scanf(" %c", &sexo[i]);
        limpiarBuffer();
    }

    printf("Cantidad de horas trabajadas: ");
    scanf("%d", &horas[i]);
    limpiarBuffer();

    while (horas[i]<0 || horas[i]>24) {
        printf("Horas invalidas. Reingrese: ");
        scanf("%d", &horas[i]);
        limpiarBuffer();
    }

    printf("Sueldo por hora: ");
    scanf("%d", &sueldoHora[i]);
    limpiarBuffer();
    printf("\n");

    while (sueldoHora[i]<=0) {
        printf("Sueldo invalido. Reingrese: ");
        scanf("%d", &sueldoHora[i]);
        limpiarBuffer();
    }

    //CÁLCULOS
    sueldoBruto[i] = sueldoHora[i] * horas[i];

    obraSocial[i] = sueldoBruto[i] * 3/100;
    jubilacion[i] = sueldoBruto[i] * 11/100;

    sueldoNeto[i] = sueldoBruto[i]-obraSocial[i]-jubilacion[i];

    totalObraSocial+=obraSocial[i];
    totalJubilacion+=jubilacion[i];

    if (sexo[i]=='M') {
        totalHombres++;
        sumaHombres+=sueldoNeto[i];
    } else {
        totalMujeres++;
        sumaMujeres+=sueldoNeto[i];
    }

    printf("Nombre: %s\n", nombre[i]);
    printf("Sueldo bruto: $%d\n", sueldoBruto[i]);
    printf("Sueldo neto: $%d\n\n", sueldoNeto[i]);

    }

    //RESUMEN DE DATOS

    printf("\tTOTAL DE PAGOS POR GENERO\n");
    printf("\t*************************\n");
    printf("Hombres: $%d\n", sumaHombres);
    printf("Mujeres: $%d\n\n", sumaMujeres);

    printf("\tSUELDO PROMEDIO\n");
    printf("\t***************\n");
    printf("Hombres: $%d\n", sumaHombres / totalHombres);
    printf("Mujeres: %d\n\n", sumaMujeres / totalMujeres);

    printf("\tNUMERO DE LEGAJO CON MAYORES INGRESOS\n");
    printf("\t*************************************\n");

    //BUSQUEDA DE MÁXIMOS
    mayor = sueldoNeto[0];
    legajoMayor = legajo[0];

    for (i=1; i<EMPLEADOS; i++) {

        if (sueldoNeto[i] > mayor) {
        mayor = sueldoNeto[i];
        legajoMayor = legajo[i];
        }

    }

    printf("Legajo numero |%d|\n\n", legajoMayor);

    printf("\tTOTAL DE DESCUENTOS POR OBRA SOCIAL\n");
    printf("\t***********************************\n");
    printf("$%d\n\n", totalObraSocial);

    printf("\tTOTAL DE DESCUENTOS POR JUBILACION\n");
    printf("\t**********************************\n");
    printf("$%d\n", totalJubilacion);

    return 0;
}
