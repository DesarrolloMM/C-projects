#include <stdio.h>

// Prototipo de la funcion
void mostrar(int);

int main() {
   printf("Ingrese un entero: ");
   int valor;
   scanf("%d", &valor);

   printf("Antes de la funcion %d\n", valor);
   mostrar(valor); // llamada a la funcion 
   printf("Despues de la funcion %d\n", valor);

   return 0;
}

void mostrar(int valor) {
    valor = 1;
    printf("El valor es %d\n", valor);
}

#include <stdio.h>

// Prototipo de la funcion
void mostrar(int*);

int main() {
   printf("Ingrese un entero: ");
   int valor; // 0x1000
   scanf("%d", &valor);

   printf("Antes de la funcion %d\n", valor);
   printf("La direccion de memoria de valor es %p\n", &valor);
   mostrar(&valor); // llamada a la funcion 
   printf("Despues de la funcion %d\n", valor);

   return 0;
}

void mostrar(int *valor) { // copia de 0x1000
    *valor = 1;
    printf("El valor es %d\n", *valor);
}

#include <stdio.h>

#define N 5

/* a) completar un arreglo de 5 elemenetos por teclado */
/* b) triplicar cada valor */
/* c) mostrar por pantalla */
/* d) calcular el promedio y mostrarlo por pantalla en la funcion main */

void ingresar(int[], int);
void triplicar(int[], int);
void mostrar(int[], int);
float promedio(int[], int);
int sumar(int[], int);

int main() {
    int arr[N];

    ingresar(arr, N);

    triplicar(arr, N);

    mostrar(arr, N);

    printf("Promedio %.2f\n", promedio(arr, N));

    return 0;
}

void ingresar(int arr[], int cant) {
    for(int i = 0; i < cant; i++) {
	scanf("%d", &arr[i]);
    }
}

void triplicar(int arr[], int cant) {
    for(int i = 0; i < cant; i++) {
        arr[i] = 3 * arr[i];	
    }
}

void mostrar(int arr[], int cant) {
    for(int i = 0; i < cant; i++) {
	printf("%d ", arr[i]);
    }
}

float promedio(int arr[], int cant) {
    int funcionSuma = sumar(arr, cant);    
    return funcionSuma / (float)cant;
}

int sumar(int arr[], int cant) {
    int suma = 0;
    for(int i = 0; i < cant; i++) {
        suma += arr[i];	// suma = suma + arr[i]
    }
    return suma;
}