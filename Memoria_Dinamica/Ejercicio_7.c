/*Construye un programa que lea una secuencia de números enteros por teclado
y los almacene en un array dinámico. A partir de él, se deben crear tres array
 de modo que en el primero se almacenen los números que dan resto 1 al dividirlos
por tres, en la segunda los de resto 2, y en la tercera los divisibles por 3.
El programa deberá emitir la lista inicial y las tres nuevas listas.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int num = 0;
    int *dinamico = NULL;
    int n = 0;

    int *v1 = NULL, *v2 = NULL, *v3 = NULL;
    int cont1 = 0, cont2 = 0, cont3 = 0;

    printf("Ingresa numeros (-1 para finalizar):\n");

    // =========================
    // 1. CARGA DINAMICA
    // =========================
    while (num != -1) {
        scanf("%d", &num);

        if (num == -1) break;

        n++;
        dinamico = realloc(dinamico, n * sizeof(int));
        dinamico[n - 1] = num;
    }

    // =========================
    // 2. CONTAR ELEMENTOS
    // =========================
    for (int i = 0; i < n; i++) {

        if (dinamico[i] % 3 == 1){
            cont1++;
        }

        else if (dinamico[i] % 3 == 2){
                cont2++;
        }

        else {
        cont3++;
        }
    }

    // =========================
    // 3. RESERVAR MEMORIA (malloc)
    // =========================
    v1 = (int*)malloc(cont1 * sizeof(int));
    v2 = (int*)malloc(cont2 * sizeof(int));
    v3 = (int*)malloc(cont3 * sizeof(int));

    if (v1 == NULL || v2 == NULL || v3 == NULL) {
        printf("Error de memoria\n");
        free(dinamico);
        return 1;
    }

    // =========================
    // 4. LLENAR VECTORES
    // =========================
    int j = 0, k = 0, b = 0;

    for (int i = 0; i < n; i++) {
        if (dinamico[i] % 3 == 1) {
            v1[j] = dinamico[i];
            j++;
        }
        else if (dinamico[i] % 3 == 2) {
            v2[k] = dinamico[i];
            k++;
        }
        else {
            v3[b] = dinamico[i];
            b++;
        }
    }

    // =========================
    // 5. MOSTRAR RESULTADOS
    // =========================
    printf("\nOriginal:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", dinamico[i]);
        }

    printf("\nResto 1:\n");
    for (int i = 0; i < cont1; i++){
        printf("%d ", v1[i]);
        }

    printf("\nResto 2:\n");
    for (int i = 0; i < cont2; i++){
        printf("%d ", v2[i]);
        }

    printf("\nResto 0:\n");
    for (int i = 0; i < cont3; i++){
        printf("%d ", v3[i]);
        }

    printf("\n");

    // =========================
    // 6. LIBERAR MEMORIA
    // =========================
    free(dinamico);
    free(v1);
    free(v2);
    free(v3);

    return 0;
}
