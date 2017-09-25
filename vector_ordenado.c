/*
  Faustino Aguilar, 2015
  Elabore un programa que coloque elementos en un vector
  de manera que los elementos siempre estén ordenados.
  A medida que entra un valor debe ser colocado en la
  posición correspondiente para mantener el orden de los elementos.
*/

#include <stdio.h>
#include "string.h"

int main() {
  // Función para leer valores
  void readVector();
  // Función que ordenará el vector
  void sortVector(int vector[], int valor, int * c, int l);
  // Funcion para saber si el vector está lleno
  int isFull(int c, int l);
  // Función que va a imprimir el vector
  void printVector(int vector[], int c);

  readVector();

  return 0;
}

int isFull(int c, int l) {
  if (c >= l) {
    return 1;
  } else {
    return 0;
  }
}


void sortVector(int vector[], int valor, int * c, int l) {
  int j, k;
  if (*c == 0) {
    vector[0] = valor;
    *c = *c + 1;
  } else {
    /*
      Si valor es el mayor, solo se agrega al final.
      6 → 1 2 4 5 → 1 2 4 5 6
      Si valor es menor, se corren los números hacia delante
      y se cambia el valor por el número que es mayor a él.
      4 → 2 4 5 6 → 2 4 4 5 6
    */
    for (j = 0; j < *c; j++) {
      if (valor <= vector[j]) {
        // Solo entra si el valor es menor o igual
        for (k = *c; k > j; k--) {
          vector[k] = vector[k-1];
        }
        vector[j] = valor;
        j = *c;  // Detiene el ciclo
      } else if (j == *c-1) {
        // Se agrega el valor al final
        vector[j+1] = valor;
      }
    }
    /*
      Incrementa el contador de la
      cantidad de elementos del vector
    */
    *c = *c + 1;
  }
}


void printVector(int vector[], int c) {
  int j;
  // Imprime el vector en pantalla
  printf("Vector = [ ");
  for (j = 0; j < c; j++){
    printf("%d ", vector[j]);
  }
  printf("]\n");
}


void readVector() {
  /*
    Variables
    l: longuitud del vector
    n: cantidad de elementos a leer
    c: elementos en el vector
    i, j, k: contadores
    valor: introducido por el usuario
  */
  int i, valor, l=5, n=6, c=0;
  // Vector que almacenará enteros
  int vector[l];
  // Vector de caracteres leidos con fgets
  char line[256];

  for (i = 0; i < n; i++) {
    printf("\nEscribe el valor %d° del vector: ", i+1);

    // Forma segura de leer un valor
    // Referencia:
    // stackoverflow.com/questions/9278226/which-is-the-best-way-to-get-input-from-user-in-c
    if(fgets(line, sizeof(line), stdin)) {
      if(sscanf(line, "%d", &valor) == 1) {

        if (isFull(c, l)) {
          printf("El vector está lleno\n");
        } else {
          // Ordena el valor en el vector
          // El Vector NO está lleno
          sortVector(vector, valor, &c, l);
        }

        // Imprime el vector
        printVector(vector, c);

      } else {
        printf("Inserte un numero porfavor!\n");
        i--;
      }
    }
  }
}
