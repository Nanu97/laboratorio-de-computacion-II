/*Se denomina palíndromo a una palabra o frase que se lee igual de
izquierda a derecha que de derecha a izquierda.
Por ejemplo: DABALE ARROZ ALA ZORRA ELABAD

Escribe un programa que lea una cadena de caracteres y
determine si es o no un palíndromo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int capacidad = 10; // Empezamos con un espacio pequeño
    int contador = 0;
    char *texto = malloc(capacidad * sizeof(char));
    int c;

    if (texto == NULL) return 1;

    printf("Escribe un texto largo: ");

    // Leer caracteres hasta el salto de línea o el fin del archivo (EOF)
    while ((c = getchar()) != '\n' && c != EOF) {

        // ¿Nos quedamos sin espacio? (Reservamos 1 extra para el \0)
        if (contador + 1 >= capacidad) {
            capacidad *= 2; // Duplicamos la capacidad (estrategia eficiente)
            char *temporal = realloc(texto, capacidad * sizeof(char));

            if (temporal == NULL) {
                free(texto);
                return 1;
            }
            texto = temporal;
        }

        texto[contador++] = (char)c;
    }

    // Importante: Agregar el terminador nulo al final
    texto[contador] = '\0';

    int esPalindromo = 1;
    int j = strlen(texto) - 1;

    for (int i=0; i<strlen(texto); i++){
        if (texto[i] != texto[j]){
            esPalindromo = 0;
            break;
        } else {
            j--;
        }
    }

    if (esPalindromo == 1){
        printf("El texto ES PALINDROMO\n");
    } else {
        printf("El texto NO es un palindromo\n");
    }

    printf("\nLeIdo correctamente (%d caracteres): %s\n", contador, texto);

    free(texto);
    return 0;
}
