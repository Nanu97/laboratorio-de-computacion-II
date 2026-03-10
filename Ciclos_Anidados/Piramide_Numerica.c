#include <stdio.h>
#include <stdlib.h>

int main()
{
int fila, espacio, cuenta;
const int lineas = 5;

for (fila = 1; fila <= lineas; fila++){
printf("\t");
  for (espacio=lineas - fila; espacio >0; espacio--)
  printf(" ");
  for (cuenta = 1; cuenta <= fila; cuenta++)
  printf("%d",cuenta);
  for (cuenta = fila-1; cuenta>=1; cuenta--)
  printf("%d",cuenta);
  printf(" ");
  printf(" \n");
  }
  return  0;
}
