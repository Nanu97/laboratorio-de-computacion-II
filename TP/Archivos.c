//TRABAJO PRACTICO DE ARCHIVOS
//DOCENTE: HENCEK, MONICA
//AUTOR: RODRIGUEZ, NAHUEL DAMIAN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct plataforma{

    int id;
    char nombrePlataforma[30];
    int activo; //1 para disponible, 0 para "borrado" (Baja lógica)

}plataforma;

typedef struct videojuego{

    int idJuego; //ID único para buscar/modificar
    int idPlataforma; //Relación con plataforma
    char titulo[50];
    float precioCosto; //Lo que costó comprarlo
    float precioVenta; //A cuánto se vende (calculado)
    float margen; //Porcentaje de ganancia (ej: 30 para 30%)
    int stock;
    float valorStock; //Campo calculado: precio *stock
    int activo; //1 para disponible, 0 para "borrado" (Baja lógica)

}videojuego;

//--------------------------------------------------------------
/*FUNCION PARA CREAR ARCHIVOS BINARIOS. SI EL ARCHIVO NO EXISTE,
LO CREA*/
//--------------------------------------------------------------

void crearBinario(char nombreArchivo[]){

    FILE* archivo;

    archivo = fopen(nombreArchivo, "rb");

    if (archivo == NULL){
        archivo = fopen(nombreArchivo, "wb");

        if (archivo == NULL){
            printf("Error al crear el archivo\n");
            return;
        }

        printf("Archivo creado exitosamente\n");
        }
        else {
            printf("El archivo ya existe\n");
        }

    fclose(archivo);
    }
    
//-------------------------------------------------------    
/*FUNCION PARA PASAR CARACTERES O STRINGS A MAYUSCULAS*/
//-------------------------------------------------------

void mayusculizar(char texto[]){

    int i=0;

    while (texto[i] != '\0'){
        texto[i] = toupper(texto[i]);
        i++;
    }
}

//---------------------------------------------------------
/*FUNCION PARA DAR DE ALTA UNA PLATAFORMA DE VIDEOJUEGOS*/
//---------------------------------------------------------

void altaPlataforma(){

    FILE* archivo;
    plataforma p;
    plataforma aux;

    int id_aux;
    char nombre_aux[30];
    int repetido;
    int nombreRepetido;

    printf("\n---Alta de Plataforma---\n\n");

    do {

        repetido = 0;

        printf("Ingrese ID: ");

    while(scanf("%d", &id_aux) != 1){

        printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
    }

        archivo = fopen("plataforma.dat", "rb");

        while(fread(&aux, sizeof(plataforma), 1, archivo) == 1){

            if(id_aux == aux.id){

                repetido = 1;
            }
        }

        fclose(archivo);

        if(repetido){

            printf("Error: ID repetido\n");
        }

    } while(repetido);

    p.id = id_aux;

    do {

        nombreRepetido = 0;

        printf("Ingrese nombre de plataforma: ");
        scanf("%s", nombre_aux);

        mayusculizar(nombre_aux);

        archivo = fopen("plataforma.dat", "rb");

        while(fread(&aux, sizeof(plataforma), 1, archivo) == 1){

            if(strcmp(nombre_aux, aux.nombrePlataforma) == 0){

                nombreRepetido = 1;
            }
        }

        fclose(archivo);

        if(nombreRepetido){

            printf("Error: Esta plataforma ya esta registrada\n");
        }

    } while(nombreRepetido);

    strcpy(p.nombrePlataforma, nombre_aux);

    p.activo = 1;

    archivo = fopen("plataforma.dat", "ab");

    fwrite(&p, sizeof(plataforma), 1, archivo);

    fclose(archivo);

    printf("Plataforma guardada correctamente\n");
}

//----------------------------------------------------------------
/*FUNCION PARA DAR DE BAJA LOGICA UNA PLATAFORMA DE VIDEOJUEGOS.
EL CAMPO "ACTIVO" PASARA A SER 0 (CERO).
PUEDE SER REACTIVADO MAS ADELANTE*/
//----------------------------------------------------------------

void bajaLogicaPlataforma(){

    FILE* archivo;
    plataforma p;
    int id;
    int existe = 0;

    printf("\n---Baja de Plataforma---\n\n");

    printf("Ingrese ID de la plataforma que desea dar de baja: ");

    while(scanf("%d", &id) != 1){

        printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
    }

    archivo = fopen("plataforma.dat", "rb+");

    while(fread(&p, sizeof(plataforma), 1, archivo) == 1){

        if(id == p.id){
            existe = 1;
            if (p.activo == 0){
                printf("Error: La plataforma ya ha sido dada de baja\n");
                break;
            }
            else {
                fseek(archivo, -sizeof(plataforma), SEEK_CUR);
                p.activo = 0;
                fwrite(&p, sizeof(plataforma), 1, archivo);
                printf("Plataforma dada de baja exitosmente\n");
                break;
            }
        }
    }

    if (!existe){
        printf("Error: el ID no existe\n");
    }

    fclose(archivo);
}

//------------------------------------------------------
/*FUNCION PARA MOSTRAR UN LISTADO DE LAS PLATAFORMAS*/
//------------------------------------------------------

void listarPlataformas(){

    FILE* archivo;
    plataforma p;

    archivo = fopen("plataforma.dat", "rb");

    printf("\nID\t\tPlataforma\t\tActivo\n");
    printf("----------------------------------------------\n");

    fread(&p,sizeof(plataforma),1,archivo);
        while(!feof(archivo)) {
            printf("%-15d %-15s %13d\n", p.id, p.nombrePlataforma, p.activo);
            fread(&p,sizeof(plataforma),1,archivo);
        }
        fclose(archivo);
}

//----------------------------------------------------------
/*FUNCION PARA REACTIVAR (PONER CAMPO "ACTIVO" EN 1 (UNO)
UNA PLATAFORMA DADA DE BAJA CON ANTERIORIDAD*/
//----------------------------------------------------------

void reactivarPlataforma(){

    FILE* archivo;
    plataforma p;
    int id;
    int existe = 0;

    printf("\n---Reactivacion de Plataforma---\n\n");

    printf("Ingrese ID de la plataforma que desea reactivar: ");

    while(scanf("%d", &id) != 1){

        printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
    }

    archivo = fopen("plataforma.dat", "rb+");

    while(fread(&p, sizeof(plataforma), 1, archivo) == 1){

        if(id == p.id){
            existe = 1;
            if (p.activo == 1){
                printf("Error: La plataforma se encuentra actualmente activa\n");
                break;
            }
            else {
                fseek(archivo, -sizeof(plataforma), SEEK_CUR);
                p.activo = 1;
                fwrite(&p, sizeof(plataforma), 1, archivo);
                printf("Plataforma reactivada exitosamente\n");
                break;
            }
        }
    }

    if (!existe){
        printf("Error: el ID no existe\n");
    }

    fclose(archivo);
}

//-------------------------------------------------------------
/*FUNCION PARA LISTAR AQUELLAS PLATAFORMAS QUE ESTAN ACTIVAS,
ES DECIR QUE POSEEN SU CAMPO "ACTIVO" EN 1 (UNO)*/
//-------------------------------------------------------------

void listarPlataformasActivas(){

    FILE* archivo;
    plataforma p;

    archivo = fopen("plataforma.dat", "rb");

    printf("\nID\t\tPlataforma\t\tActivo\n");
    printf("----------------------------------------------\n");

    fread(&p,sizeof(plataforma),1,archivo);
        while(!feof(archivo)) {
            if (p.activo == 1){
            printf("%-15d %-15s %13d\n", p.id, p.nombrePlataforma, p.activo);
            }
            fread(&p,sizeof(plataforma),1,archivo);
        }
        fclose(archivo);
}

//---------------------------------------------------
/*FUNCION PARA CALCULAR EL COSTO DE UN VIDEOJUEGO*/
//---------------------------------------------------

float precioCosto(){

    float costo;

    do{

    printf("Ingrese el precio de costo: ");

    while(scanf("%f", &costo) != 1){

        printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
    }

    if (costo <= 0){
        printf("Error: Debe ingresar un costo mayor a cero\n");
    }


    } while (costo <= 0);

    return costo;
}

//---------------------------------------------------------------
/*FUNCION PARA AGREGAR EL MARGEN DE GANANCIA QUE DESEA OBTENER
EN BASE A UN DETERMINADO VIDEOJUEGO*/
//---------------------------------------------------------------

float margenPretendido(){

    float margen;

    do{

    printf("Ingrese el porcentaje de ganancia (entre 10 y 100): ");

    while(scanf("%f", &margen) != 1){

        printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
    }

    if (margen < 10 || margen > 100){
        printf("Margen invalido\n");
    }

    } while (margen < 10 || margen > 100);

    return margen;
}

//--------------------------------------------------
/*FUNCION PARA ALMACENAR EL STOCK DISPONIBLE DE UN
DETERMINADO JUEGO*/
//--------------------------------------------------

int stock(){

    int st;

    do{

    printf("Stock disponible: ");

    while(scanf("%d", &st) != 1){

        printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
    }

    if (st < 0){
        printf("No se permiten valores negativos\n");
    }

    } while (st < 0);

    return st;
}

//----------------------------------------------------------------
/*CALCULA EL VALOR TOTAL DEL STOCK DISPONIBLE DE UN VIDEOJUEGO*/
//----------------------------------------------------------------

float calculoStock(float costo, int st){

    float valorSt;

    valorSt = costo * st;

    return valorSt;
}

//-------------------------------------------------------------
/*FUNCION PARA DETERMINAR A CUANTO DEBE VENDER UN DETERMINADO
VIDEOJUEGO PARA OBTENER EL MARGEN DE GANANCIA PRETENDIDO*/
//-------------------------------------------------------------

float precioVenta(float costo, float margen){

    float venta;

    venta = costo + ((costo * margen)/100);

    return venta;
}

//------------------------------------------
/*FUNCION PARA DAR DE ALTA UN VIDEOJUEGO*/
//------------------------------------------

void altaJuego(){

    FILE* archivo;
    videojuego v;
    videojuego aux;
    plataforma p;
    int repetido;
    int existePlataforma;
    int id_aux;
    int plataforma_aux;
    char nombreJuego_aux[50];
    int nombreRepetido;

    printf("\n---Alta de Videojuego---\n\n");

    do {

        repetido = 0;

        printf("Ingrese ID del juego: ");

        while(scanf("%d", &id_aux) != 1){

        printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
    }

        archivo = fopen("videojuegos.dat", "rb");

        while(fread(&aux, sizeof(videojuego), 1, archivo) == 1){

            if(id_aux == aux.idJuego){

                repetido = 1;
            }
        }
        fclose(archivo);

        if(repetido){

            printf("Error: ID repetido\n");
        }

    } while(repetido);

    v.idJuego = id_aux;

    printf("\nPlataformas disponibles:\n");

    listarPlataformasActivas();

    do{

        existePlataforma = 0;

        printf("\nIngrese ID de plataforma: ");

        while(scanf("%d", &plataforma_aux) != 1){

        printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
    }

        archivo = fopen("plataforma.dat", "rb");

        while(fread(&p, sizeof(plataforma), 1, archivo) == 1){

            if(plataforma_aux == p.id && p.activo == 1){

                existePlataforma = 1;
                break;
            }
        }
        fclose(archivo);

        if(!existePlataforma){

            printf("Error: Plataforma inexistente o inactiva\n");
        }

    } while(!existePlataforma);

    v.idPlataforma = plataforma_aux;

    int c;
    while((c = getchar()) != '\n' && c != EOF);

    do{

    nombreRepetido = 0;

    printf("Ingrese el nombre del juego: ");

    fgets(nombreJuego_aux, 50, stdin);
    nombreJuego_aux[strcspn(nombreJuego_aux, "\n")] = '\0';

    mayusculizar(nombreJuego_aux);

    archivo = fopen("videojuegos.dat", "rb");

    while(fread(&aux, sizeof(videojuego), 1, archivo) == 1){

        if(strcmp(nombreJuego_aux, aux.titulo) == 0){

            nombreRepetido = 1;
        }
    }

    fclose(archivo);

        if(nombreRepetido){

            printf("Error: Ese juego ya pertenece a la base de datos\n");
        }

    } while(nombreRepetido);

    strcpy(v.titulo, nombreJuego_aux);

    v.precioCosto = precioCosto();
    v.margen = margenPretendido();
    v.precioVenta = precioVenta(v.precioCosto, v.margen);
    v.stock = stock();
    v.valorStock = calculoStock(v.precioCosto, v.stock);
    v.activo = 1;

    archivo = fopen("videojuegos.dat", "ab");

    fwrite(&v, sizeof(videojuego), 1, archivo);

    fclose(archivo);

    printf("Videojuego cargado exitosamente\n");

}

//----------------------------------------------------------
/*FUNCION PARA MOSTRAR UNA LISTA DE TODOS LOS VIDEOJUEGOS,
YA SEA QUE ESTEN ACTIVOS O INACTIVOS (BAJA LOGICA)*/
//----------------------------------------------------------

void listarTodos(){

    FILE* archivoP;
    FILE* archivoV;
    plataforma p;
    videojuego v;
    int tieneJuegos;

    archivoP = fopen("plataforma.dat", "rb");

    while(fread(&p, sizeof(plataforma), 1, archivoP) == 1){

        printf("\nPlataforma: %s\n", p.nombrePlataforma);
        printf("------------------------------------------\n");

        tieneJuegos = 0;

        archivoV = fopen("videojuegos.dat", "rb");

            while(fread(&v, sizeof(videojuego), 1, archivoV) == 1){

                if(v.idPlataforma == p.id){
                    tieneJuegos = 1;

                    printf("*%s | ", v.titulo);
                    printf("Costo: $%.2f | ", v.precioCosto);
                    printf("Margen: %.2f%% | ", v.margen);
                    printf("Venta: $%.2f\n", v.precioVenta);
                }
            }

            if(!tieneJuegos){
                printf("No hay juegos cargados en esta plataforma\n");
            }

        fclose(archivoV);
    }
    fclose(archivoP);
}

//--------------------------------------------------------
/*FUNCION PARA LISTAR LOS VIDEOJUEGOS DE UNA DETERMINADA
PLATAFORMA. SOLO APARECERAN AQUELLOS CUYO ESTADO SE
ENCUENTRE ACTIVO*/
//--------------------------------------------------------

void listarPorPlataforma(){

    FILE* archivoP;
    FILE* archivoV;
    plataforma p;
    videojuego v;
    int idPlat;
    int existe = 0;
    int tieneJuegos = 0;

    listarPlataformasActivas();

    printf("\nIngrese el ID de la plataforma cuya lista de juegos desea desplegar: ");

    while(scanf("%d", &idPlat) != 1){

        printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
    }

    archivoP = fopen("plataforma.dat", "rb");

    while(fread(&p, sizeof(plataforma), 1, archivoP) == 1){

        if (p.id == idPlat && p.activo == 1){
            existe = 1;

            printf("\nPlataforma: %s\n", p.nombrePlataforma);
            printf("---------------------------------------\n");

            archivoV = fopen("videojuegos.dat", "rb");

            while(fread(&v, sizeof(videojuego), 1, archivoV) == 1){

                if (v.idPlataforma == idPlat && v.activo == 1){
                    tieneJuegos = 1;

                    printf("* %s | ", v.titulo);
                    printf("Costo: $%.2f | ", v.precioCosto);
                    printf("Margen: %.2f%% | ", v.margen);
                    printf("Venta: $%.2f\n", v.precioVenta);
                }
            }
            fclose(archivoV);

            if (!tieneJuegos){
                printf("No hay juegos cargados en esta plataforma\n");
            }
            break;
        }
    }
    fclose(archivoP);

    if (!existe){
        printf("Plataforma inexistente o inactiva\n");
    }
}

//----------------------------------------------------
/*FUNCION REPORTE DE ALERTA DE BAJO STOCK.
SE ENLISTARAN AQUELLOS JUEGOS CUYO STOCK DISPONIBLE
SEA MENOR A LA CANTIDAD DE 5*/
//----------------------------------------------------

void listarBajoStock(){

    FILE* archivoV;
    FILE* archivoP;
    videojuego v;
    plataforma p;
    int bajoStock = 0;

    printf("\n---REPORTE DE ALERTA DE BAJO STOCK---\n");

    archivoV = fopen("videojuegos.dat", "rb");

    while(fread(&v, sizeof(videojuego), 1, archivoV) == 1){

        if(v.activo == 1 && v.stock < 5){
            bajoStock = 1;

            archivoP = fopen("plataforma.dat", "rb");

            while(fread(&p, sizeof(plataforma), 1, archivoP) == 1){

                if(p.id == v.idPlataforma){

                    printf("\nJuego: %s\n", v.titulo);
                    printf("Plataforma: %s\n", p.nombrePlataforma);
                    printf("Stock disponible: %d\n", v.stock);
                    break;
                }
            }
            fclose(archivoP);
        }
    }
    fclose(archivoV);

    if(!bajoStock){
        printf("\nNo hay videojuegos con bajo stock\n");
    }
}

//----------------------------------
/*MENU DE GESTION DE VIDEOJUEGOS*/
//----------------------------------

void listarVideojuegos(){

    int op;

    do{

        printf("\n1) Listar todos\n");
        printf("2) Listar por Plataforma\n");
        printf("3) Listar los juegos que tienen menos de 5 unidades en stock\n");
        printf("0) Salir\n");

        printf("Ingrese una opcion: ");

        while(scanf("%d", &op) != 1){

        printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
    }

        while (op < 0 || op > 3){
            printf("La opcion ingresada no es valida, reintente: ");
            scanf("%d", &op);
        }

    switch (op){

        case 1:
            listarTodos();
            break;

        case 2:
            listarPorPlataforma();
            break;

        case 3:
            listarBajoStock();
            break;

        case 0:
            printf("Saliendo...\n");
            break;
        }

    } while (op != 0);

}

//-----------------------------------------------
/*FUNCION PARA BUSCAR UN DETERMINADO VIDEOJUEGO
EN BASE A SU NUMERO DE ID*/
//-----------------------------------------------

void buscarPorID(){

    FILE* archivo;
    videojuego v;
    int juegoBuscado;
    int encontrado = 0;

    printf("\nIngrese ID del videojuego: ");

    while(scanf("%d", &juegoBuscado) != 1){

        printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
    }

    archivo = fopen("videojuegos.dat", "rb");

    while(fread(&v, sizeof(videojuego), 1, archivo) == 1){

        if(v.idJuego == juegoBuscado){
            encontrado = 1;

            if(v.activo == 1){

                printf("\nINFORMACION DEL VIDEOJUEGO\n");
                printf("----------------------------\n");
                printf("ID: %d\n", v.idJuego);
                printf("Titulo: %s\n", v.titulo);
                printf("Costo: $%.2f\n", v.precioCosto);
                printf("Margen de ganancia: %.2f%%\n", v.margen);
                printf("Precio de venta: $%.2f\n", v.precioVenta);
                printf("Stock: %d\n", v.stock);
            }

            else{
                printf("El videojuego se encuentra inactivo\n");
            }
            break;
        }
    }
    fclose(archivo);
    if(!encontrado){
        printf("No existe un videojuego con ese ID\n");
    }
}

//---------------------------------------------------------
/*FUNCION PARA BUSCAR UN VIDEOJUEGO EN BASE A SU NOMBRE*/
//---------------------------------------------------------

void buscarPorTitulo(){

    FILE* archivo;
    videojuego v;
    char buscarTitulo[50];
    int encontrado = 0;

    printf("\nIngrese nombre del videojuego: ");

    int c;
    while((c = getchar()) != '\n' && c != EOF);

    fgets(buscarTitulo, 50, stdin);
    buscarTitulo[strcspn(buscarTitulo, "\n")] = '\0';

    mayusculizar(buscarTitulo);

    archivo = fopen("videojuegos.dat", "rb");

    while(fread(&v, sizeof(videojuego), 1, archivo) == 1){

        if(strcmp(v.titulo, buscarTitulo) == 0){

            encontrado = 1;

            if(v.activo == 1){

                printf("\nINFORMACION DEL VIDEOJUEGO\n");
                printf("----------------------------\n");
                printf("ID: %d\n", v.idJuego);
                printf("Titulo: %s\n", v.titulo);
                printf("Costo: $%.2f\n", v.precioCosto);
                printf("Margen de ganancia: %.2f%%\n", v.margen);
                printf("Precio de venta: $%.2f\n", v.precioVenta);
                printf("Stock: %d\n", v.stock);
            }
            else{
                printf("El videojuego se encuentra inactivo\n");
            }
            break;
        }
    }
    fclose(archivo);

    if(!encontrado){
        printf("No existe un videojuego con ese titulo\n");
    }
}

//-----------------------------------
/*MENU DE BUSQUEDA DE VIDEOJUEGOS*/
//-----------------------------------

void buscarVideojuego(){

    int op;

    do{

        printf("\n1) Buscar por ID\n");
        printf("2) Buscar por titulo\n");
        printf("0) Salir\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &op);

        while(op < 0 || op > 2){

            printf("Opcion invalida, reintente: ");
            scanf("%d", &op);
        }

        switch(op){

            case 1:
                buscarPorID();
                break;

            case 2:
                buscarPorTitulo();
                break;

            case 0:
                printf("Saliendo...\n");
                break;
        }
    } while(op != 0);
}

//---------------------------------------------------
/*FUNCION PARA MODIFICAR EL STOCK DE UN DETERMINADO
VIDEOJUEGO*/
//---------------------------------------------------

void modificarStock(){

    FILE* archivo;
    videojuego v;
    char buscarTitulo[50];
    int stock2;
    int encontrado = 0;

    printf("\nIngrese el nombre del videojuego: ");

    int c;
    while((c = getchar()) != '\n' && c != EOF);

    fgets(buscarTitulo, 50, stdin);
    buscarTitulo[strcspn(buscarTitulo, "\n")] = '\0';

    mayusculizar(buscarTitulo);

    archivo = fopen("videojuegos.dat", "rb+");

    while(fread(&v, sizeof(videojuego), 1, archivo) == 1){

        if(strcmp(v.titulo, buscarTitulo) == 0){

            encontrado = 1;

            if(v.activo == 0){

                printf("No puede modificar un videojuego inactivo\n");
                break;
            }

            printf("\nNombre del juego: %s\n", v.titulo);
            printf("Stock actual: %d\n", v.stock);

            do{

                printf("Ingrese el nuevo valor de stock: ");

                while(scanf("%d", &stock2) != 1){

        printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
    }

                if(stock2 < 0){

                    printf("No se permiten valores negativos\n");
                }

            } while(stock2 < 0);

            v.stock = stock2;

            v.valorStock = calculoStock(v.precioCosto, v.stock);

            fseek(archivo, -sizeof(videojuego), SEEK_CUR);

            fwrite(&v, sizeof(videojuego), 1, archivo);

            printf("Stock modificado con exito\n");

            break;
        }
    }

    fclose(archivo);

    if(!encontrado){

        printf("No existe un videojuego con ese titulo\n");
    }
}

//--------------------------------------------------------
/*FUNCION PARA MODIFICAREL MARGEN DE GANANCIA DE UN JUEGO
QUE SERA BUSCADO POR SU NUMERO DE ID*/
//--------------------------------------------------------

void modificarMargenID(){

    FILE* archivo;
    videojuego v;
    int buscarID;
    int encontrado = 0;
    float margen2;
    char confirmacion;

    printf("\n---MODIFICAR MARGEN POR ID---\n");

    printf("\nIngrese ID del videojuego: ");

    while(scanf("%d", &buscarID) != 1){

        printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
    }

    archivo = fopen("videojuegos.dat", "rb+");

    while(fread(&v, sizeof(videojuego), 1, archivo) == 1){

        if(v.idJuego == buscarID){

            encontrado = 1;

            if(v.activo == 0){

                printf("No se puede modificar un videojuego inactivo\n");
                break;
            }

            printf("\nNombre del juego: %s\n", v.titulo);
            printf("Margen actual: %.2f%%\n", v.margen);

            do{

                printf("Ingrese nuevo margen (entre 10 y 100): ");

                while(scanf("%f", &margen2) != 1){

            printf("Error: Debe ingresar un numero\n");

            int c;
            while((c = getchar()) != '\n' && c != EOF);
    }

                if(margen2 < 10 || margen2 > 100){
                    printf("Margen invalido\n");
                }

            } while(margen2 < 10 || margen2 > 100);

            printf("\nEsta seguro que desea modificar el margen de ganancia?\n");
            printf("Presione S para confirmar // Presione cualquier otra tecla para cancelar\n");
            scanf(" %c", &confirmacion);

            confirmacion = toupper(confirmacion);

            if(confirmacion == 'S'){
                v.margen = margen2;
                v.precioVenta = precioVenta(v.precioCosto, v.margen);

                fseek(archivo, -sizeof(videojuego), SEEK_CUR);

                fwrite(&v, sizeof(videojuego), 1, archivo);

                printf("Margen modificado exitosamente\n");
                printf("Nuevo precio de venta: $%.2f\n", v.precioVenta);
            }
            else{
                printf("Operacion cancelada\n");
            }

            break;
        }
    }
    fclose(archivo);

    if(!encontrado){

        printf("No existe un videojuego con ese ID\n");
    }
}

//-------------------------------------------------------
/*FUNCION PARA MODIFICAR EL MARGEN DE GANANCIA DE TODOS
LOS VIDEOJUEGOS PERTENECIENTES A UNA DETERMINADA
PLATAFORMA.*/
//-------------------------------------------------------

void modificarMargenPlataforma(){

    FILE* archivoV;
    FILE* archivoP;
    videojuego v;
    plataforma p;
    int idPlat;
    int existe = 0;
    float margen2;
    char confirmacion;

    listarPlataformasActivas();

    printf("\nIngrese ID de la plataforma: ");

    while(scanf("%d", &idPlat) != 1){

    printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

    archivoP = fopen("plataforma.dat", "rb");

    while(fread(&p, sizeof(plataforma), 1, archivoP) == 1){

        if(p.id == idPlat && p.activo == 1){

            existe = 1;

            printf("\nPlataforma: %s\n", p.nombrePlataforma);
            break;
        }
    }

    fclose(archivoP);

    if(!existe){

        printf("Plataforma inexistente o inactiva\n");
        return;
    }

    do{

        printf("Ingrese nuevo margen (entre 10 y 100): ");

        while(scanf("%f", &margen2) != 1){

    printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

        if(margen2 < 10 || margen2 > 100){
            printf("Margen invalido\n");
        }

    } while(margen2 < 10 || margen2 > 100);

    printf("\nEsta seguro que desea modificar el margen de ganancia?\n");
    printf("Presione S para confirmar // Presione cualquier otra tecla para cancelar\n");
    scanf(" %c", &confirmacion);

    confirmacion = toupper(confirmacion);

    if(confirmacion != 'S'){
        printf("Operacion cancelada\n");
        return;
    }

    printf("Margenes actualizados correctamente!\n");

    archivoV = fopen("videojuegos.dat", "rb+");

    while(fread(&v, sizeof(videojuego), 1, archivoV) == 1){

        if(v.idPlataforma == idPlat && v.activo == 1){
            v.margen = margen2;
            v.precioVenta = precioVenta(v.precioCosto, v.margen);

            fseek(archivoV, -sizeof(videojuego), SEEK_CUR);

            fwrite(&v, sizeof(videojuego), 1, archivoV);

            fseek(archivoV, 0, SEEK_CUR);
        }
    }
    fclose(archivoV);

}

//-----------------------------------------
/*MENU PARA MODIFICAR CAMPOS RELACIONADOS
A LOS VIDEOJUEGOS*/
//-----------------------------------------

void modificar(){

    int op;

    do{

        printf("\n1) Modificar stock por nombre\n");
        printf("2) Modificar margen por ID\n");
        printf("3) Modificar margen de una plataforma\n");
        printf("0) Salir\n");
        printf("Seleccione una opcion: ");

        while(scanf("%d", &op) != 1){

    printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

        while(op < 0 || op > 3){

            printf("Opcion invalida, reintente: ");
            scanf("%d", &op);
        }

        switch(op){

            case 1:
                modificarStock();
                break;

            case 2:
                modificarMargenID();
                break;

            case 3:
                modificarMargenPlataforma();
                break;

            case 0:
                printf("Saliendo...\n");
                break;
        }

    } while(op != 0);
}

//------------------------------------------------------
/*FUNCION PARA DAR DE BAJA LOGICA UN DETERMINADO JUEGO
QUE SERA BUSCADO POR SU NUMERO DE ID*/
//------------------------------------------------------

void bajaJuegoID(){

    FILE* archivo;
    videojuego v;
    int id;
    int encontrado = 0;
    char confirmacion;

    printf("\nIngrese ID del videojuego: ");

    while(scanf("%d", &id) != 1){

        printf("Error: Debe ingresar un numero\n");

        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }

    archivo = fopen("videojuegos.dat", "rb+");

    while(fread(&v, sizeof(videojuego), 1, archivo) == 1){

        if(v.idJuego == id){

            encontrado = 1;

            if(v.activo == 0){

                printf("El juego ya esta inactivo\n");
                break;
            }

            printf("\nNombre del juego: %s\n", v.titulo);

            printf("Esta seguro que desea dar de baja el videojuego?\n");
            printf("Presione S para confirmar // Presione cualquier otra tecla para cancelar\n");

            scanf(" %c", &confirmacion);

            confirmacion = toupper(confirmacion);

            if(confirmacion == 'S'){

                v.activo = 0;

                fseek(archivo, -sizeof(videojuego), SEEK_CUR);

                fwrite(&v, sizeof(videojuego), 1, archivo);

                printf("Videojuego dado de baja correctamente\n");
            }
            else{
                printf("Operacion cancelada\n");
            }

            break;
        }
    }

    fclose(archivo);

    if(!encontrado){
        printf("No existe un videojuego con ese ID\n");
    }
}

//-----------------------------------------------------
/*FUNCION PARA DAR DE BAJA LOGICA UN DETERMINADO JUEGO
QUE SERA BUSCADO POR SU NOMBRE*/
//-----------------------------------------------------

void bajaJuegoTitulo(){

    FILE* archivo;
    videojuego v;
    char titulo[50];
    int encontrado = 0;
    char confirmacion;

    printf("\nIngrese nombre del videojuego: ");

    int c;
    while((c = getchar()) != '\n' && c != EOF);

    fgets(titulo, 50, stdin);
    titulo[strcspn(titulo, "\n")] = '\0';

    mayusculizar(titulo);

    archivo = fopen("videojuegos.dat", "rb+");

    while(fread(&v, sizeof(videojuego), 1, archivo) == 1){

        if(strcmp(v.titulo, titulo) == 0){
            encontrado = 1;

            if(v.activo == 0){
                printf("El juego ya esta inactivo\n");
                break;
            }

            printf("\nNombre del juego: %s\n", v.titulo);
            printf("Esta seguro que desea dar de baja el videojuego?\n");
            printf("Presione S para confirmar // Presione cualquier otra tecla para cancelar\n");

            scanf(" %c", &confirmacion);

            confirmacion = toupper(confirmacion);

            if(confirmacion == 'S'){

                v.activo = 0;

                fseek(archivo, -sizeof(videojuego), SEEK_CUR);

                fwrite(&v, sizeof(videojuego), 1, archivo);

                printf("Videojuego dado de baja correctamente\n");
            }
            else{
                printf("Operacion cancelada\n");
            }

            break;
        }
    }
    fclose(archivo);

    if(!encontrado){
        printf("No existe un videojuego con ese nombre\n");
    }
}

//-------------------------------------------------------------
/*ESTA FUNCION DARA DE BAJA UNA DETERMINADA PLATAFORMA Y TODOS
LOS VIDEOJUEGOS QUE SE ENCUENTREN EN ELLA*/
//-------------------------------------------------------------

void bajaPlataformaCompleta(){

    FILE* archivoP;
    FILE* archivoV;
    plataforma p;
    videojuego v;
    int idPlat;
    int encontrada = 0;
    char confirmacion;

    listarPlataformasActivas();

    printf("\nIngrese ID de la plataforma: ");

    while(scanf("%d", &idPlat) != 1){

        printf("Error: Debe ingresar un numero\n");

        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }

    archivoP = fopen("plataforma.dat", "rb+");

    while(fread(&p, sizeof(plataforma), 1, archivoP) == 1){

        if(p.id == idPlat){

            encontrada = 1;

            if(p.activo == 0){

                printf("La plataforma ya esta inactiva\n");

                fclose(archivoP);

                return;
            }

            printf("\nPlataforma: %s\n", p.nombrePlataforma);
            printf("Esta seguro que desea eliminar la plataforma y todos sus videojuegos?\n");
            printf("Presione S para confirmar // Presione cualquier otra tecla para cancelar\n");
            scanf(" %c", &confirmacion);

            confirmacion = toupper(confirmacion);

            if(confirmacion != 'S'){
                printf("Operacion cancelada\n");
                fclose(archivoP);

                return;
            }
            p.activo = 0;

            fseek(archivoP, -sizeof(plataforma), SEEK_CUR);

            fwrite(&p, sizeof(plataforma), 1, archivoP);

            break;
        }
    }
    fclose(archivoP);

    if(!encontrada){
        printf("Plataforma inexistente\n");
        return;
    }

    archivoV = fopen("videojuegos.dat", "rb+");

    while(fread(&v, sizeof(videojuego), 1, archivoV) == 1){

        if(v.idPlataforma == idPlat && v.activo == 1){
            v.activo = 0;

            fseek(archivoV, -sizeof(videojuego), SEEK_CUR);

            fwrite(&v, sizeof(videojuego), 1, archivoV);

            fseek(archivoV, 0, SEEK_CUR);
        }
    }
    fclose(archivoV);

    printf("Plataforma y videojuegos dados de baja correctamente\n");
}

//------------------------------------------------------------
/*MENU DESTINADO A LA BAJA LOGICA DE UN DETERMIINADO JUEGO*/
//------------------------------------------------------------

void bajaLogicaJuego(){

    int op;

    do{

        printf("\n---BAJA LOGICA---\n\n");

        printf("1) Baja de videojuego por ID\n");
        printf("2) Baja de videojuego por titulo\n");
        printf("3) Baja de plataforma y todos sus videojuegos\n");
        printf("0) Salir\n");

        printf("Seleccione una opcion: ");

        while(scanf("%d", &op) != 1){

            printf("Error: Debe ingresar un numero\n");

            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }

        while(op < 0 || op > 3){

            printf("Opcion invalida, reintente: ");

            while(scanf("%d", &op) != 1){

                printf("Error: Debe ingresar un numero\n");

                int c;
                while((c = getchar()) != '\n' && c != EOF);
            }
        }
        switch (op){

            case 1:
                bajaJuegoID();
                break;

            case 2:
                bajaJuegoTitulo();
                break;

            case 3:
                bajaPlataformaCompleta();
                break;

            case 0:
                printf("Saliendo...\n");
                break;
        }
    } while(op != 0);
}

//----------------------------------------------------------
/*FUNCION PARA CREAR UN BACKUP DEL ARCHIVO DE VIDEOJUEGOS*/
//----------------------------------------------------------

void backup(){

    FILE* og;
    FILE* backup;
    videojuego v;

    og = fopen("videojuegos.dat", "rb");

    if(og == NULL){
        printf("Error al abrir archivo original\n");
        return;
    }

    backup = fopen("videojuegos_bak.dat", "wb");

    if(backup == NULL){
        printf("Error al crear backup\n");
        fclose(og);
        return;
    }

    while(fread(&v, sizeof(videojuego), 1, og) == 1){

        fwrite(&v, sizeof(videojuego), 1, backup);
    }

    fclose(og);
    fclose(backup);
    printf("Backup realizado correctamente\n");
}

//-----------------------------------------------------------
/*FUNCION PARA RESTAURAR EL ARCHIVO ORIGINAL DE VIDEOJUEGOS
UTILIZANDO LOS DATOS ALMACENADOS EN EL BACKUP*/
//-----------------------------------------------------------

void restaurar(){

    FILE* backup;
    FILE* og;
    videojuego v;

    backup = fopen("videojuegos_bak.dat", "rb");

    if(backup == NULL){
        printf("No existe un archivo de backup\n");
        return;
    }

    og = fopen("videojuegos.dat", "wb");

    if(og == NULL){
        printf("Error al restaurar archivo\n");
        fclose(backup);

        return;
    }

    while(fread(&v, sizeof(videojuego), 1, backup) == 1){

        fwrite(&v, sizeof(videojuego), 1, og);
    }

    fclose(backup);
    fclose(og);
    printf("Restauracion completada con exito\n");
}

//---------------------------------------------------------------
/*FUNCION PARA MOSTRAR UN LISTADO DE AQUELLOS VIDEOJUEGOS DADOS
DE BAJA LOGICA (CAMPO "ACTIVO" EN 0 (CERO)*/
//---------------------------------------------------------------

int listarInactivos(){

    FILE* archivo;
    videojuego v;
    int inactivos = 0;

    archivo = fopen("videojuegos.dat", "rb");

    printf("\n---VIDEOJUEGOS INACTIVOS---\n\n");

    while(fread(&v, sizeof(videojuego), 1, archivo) == 1){

        if(v.activo == 0){
            inactivos = 1;
            printf("ID: %d | NOMBRE: %s\n", v.idJuego, v.titulo);
        }
    }

    fclose(archivo);

    if(!inactivos){
        printf("Actualmente no hay videojuegos inactivos\n");
    }
    return inactivos;
}

//---------------------------------------------------
/*FUNCION PARA BORRAR DEFINITIVAMENTE UN VIDEOJUEGO
DE LA BASE DE DATOS.
ACLARACION: EL JUEGO EN CUESTION DEBERA HABER
SIDO DADO DE BAJA LOGICA PREVIAMENTE*/
//---------------------------------------------------

void bajaFisicaJuego(){

    FILE* og;
    FILE* aux;
    FILE* bajas;
    videojuego v;
    int eliminar;
    int encontrado = 0;

    if (!listarInactivos()){
        return;
    }

    printf("\nIngrese el ID del videojuego que desea eliminar definitivamente: ");

    while(scanf("%d", &eliminar) != 1){

        printf("Error: Debe ingresar un ID\n");

        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }

    og = fopen("videojuegos.dat", "rb");

    if(og == NULL){
        printf("Error al abrir videojuegos.dat\n");
        return;
    }

    aux = fopen("temporal.dat", "wb");

    if(aux == NULL){
        printf("Error al crear archivo auxiliar\n");
        fclose(og);

        return;
    }

    bajas = fopen("bajas_videojuegos.txt", "a");

    if(bajas == NULL){
        printf("Error al crear archivo de bajas\n");
        fclose(og);
        fclose(aux);

        return;
    }

    while(fread(&v, sizeof(videojuego), 1, og) == 1){

        if(v.idJuego == eliminar && v.activo == 0){
            encontrado = 1;

            fprintf(bajas, "ID: %d | TITULO: %s\n", v.idJuego, v.titulo);
            printf("Videojuego eliminado definitivamente\n");
        }
        else{
            fwrite(&v, sizeof(videojuego), 1, aux);
        }
    }

    fclose(og);
    fclose(aux);
    fclose(bajas);

    remove("videojuegos.dat");
    rename("temporal.dat", "videojuegos.dat");

    if(!encontrado){
        printf("No existe un videojuego inactivo con ese ID\n");
    }
}

//------------------------------------------------------------
/*FUNCION PARA MOSTRAR UNA LISTA DE AQUELLOS JUEGOS BORRADOS
DE LA BASE DE DATOS. ES DECIR, DADOS DE BAJA FISICA*/
//------------------------------------------------------------

void listarBajas(){

    FILE* archivo;
    char registro[200];

    archivo = fopen("bajas_videojuegos.txt", "r");

    if(archivo == NULL){
        printf("No existe archivo de bajas\n");
        return;
    }

    printf("\n---LISTADO DE BAJAS FISICAS---\n\n");

    while(fgets(registro, sizeof(registro), archivo) != NULL){
        printf("%s", registro);
    }

    fclose(archivo);
}

//----------------------------------
/*MENU DE GESTION DE PLATAFORMAS*/
//----------------------------------

void controlPlataforma(){

    int op;

    do{
        printf("\n***GESTION DE PLATAFORMAS***\n\n");
        printf("1) Alta\n");
        printf("2) Baja Logica\n");
        printf("3) Listar\n");
        printf("4) Reactivar\n");
        printf("0) Salir\n");
        printf("Ingrese la operacion a realizar: ");

        while(scanf("%d", &op) != 1){

    printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

        while (op < 0 || op > 4){
            printf("Opcion invalida, reintente: ");
            scanf("%d", &op);
        }

    switch(op){

    case 1:
        altaPlataforma();
        break;

    case 2:
        bajaLogicaPlataforma();
        break;

    case 3:
        listarPlataformas();
        break;

    case 4:
        reactivarPlataforma();
        break;

    case 0:
        printf("Saliendo...\n");
        break;
    }

    } while (op != 0);
}

//----------------------------------
/*MENU DE GESTION DE VIDEOJUEGOS*/
//----------------------------------

void menuVideojuegos(){

    char op;

    do{
        printf("\n***GESTION DE VIDEOJUEGOS***\n\n");
        printf("A) Alta de juego\n");
        printf("L) Listar videojuegos\n");
        printf("B) Buscar videojuego\n");
        printf("M) Modificar\n");
        printf("F) Baja Logica\n");
        printf("K) Backup\n");
        printf("R) Restaurar\n");
        printf("X) Baja Fisica\n");
        printf("Z) Listado de Bajas\n");
        printf("S) Salir\n");
        printf("Seleccione una opcion: ");
        scanf(" %c", &op);
        op = toupper(op);

        while (op != 'A' && op != 'L' && op != 'B' && op != 'M' && op != 'F'
            && op != 'K' && op != 'R' && op != 'X' && op != 'Z' && op != 'S'){
            printf("Opcion invalida, reintente\n");
            scanf(" %c", &op);
            op = toupper(op);
        }

    switch (op){

    case 'A':
        altaJuego();
        break;

    case 'L':
        listarVideojuegos();
        break;

    case 'B':
        buscarVideojuego();
        break;

    case 'M':
        modificar();
        break;

    case 'F':
        bajaLogicaJuego();
        break;

    case 'K':
        backup();
        break;

    case 'R':
        restaurar();
        break;

    case 'X':
        bajaFisicaJuego();
        break;

    case 'Z':
        listarBajas();
        break;

    case 'S':
        printf("Saliendo...\n");
        break;
    }

    } while (op != 'S');
}

//-----------------------------
/*MENU PRINCIPAL DEL SISTEMA*/
//-----------------------------

void menuPrincipal(){

    int op;

    do{
        printf("\n***MENU PRINCIPAL***\n");
        printf("--------------------\n\n");
        printf("1) Gestion de Plataformas\n");
        printf("2) Gestion de Videojuegos\n");
        printf("0) Salir\n");
        printf("Elija una opcion: ");

        while(scanf("%d", &op) != 1){

    printf("Error: Debe ingresar un numero\n");

    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

        while(op < 0 || op > 2){
            printf("Opcion invalida, reintente\n");
            scanf("%d", &op);
        }

    switch(op){

    case 1:
        controlPlataforma();
        break;

    case 2:
        menuVideojuegos();
        break;

    case 0:
        printf("Saliendo...\n");
        printf("Gracias por utilizar nuestro sistema!\n");
        break;
    }

    } while (op != 0);
}

//---------------------
/*PROGRAMA PRINCIPAL*/
//---------------------

int main(){

    crearBinario("plataforma.dat");
    crearBinario("videojuegos.dat");
    menuPrincipal();

    return 0;
}
