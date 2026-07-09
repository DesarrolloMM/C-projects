// Scope de una variable, parte o contexto del código donde una variable es accesible y puede ser utilizada
//Pasaje por valor: Se crea una COPIA del valor de la variable, los cambios noi afectan a la variable original
//Pasaje por referencia: Se envia la dirección donde esta alojada la variable, los cambios en el scope de la llamada modifican  a la variable original

#include <stdio.h>

#define MAX 15
#define LINF 0
#define LSUP 50
#define TRUE 1
#define FALSE 0

void cargar (int array[], int tamaño);
void mostrar(int array[], int tamaño);
int compararSuma(int array[], int tamaño);


 int main(){
    int array[MAX];
    int tamaño = MAX;
    cargar(array, tamaño);
    mostrar(array, tamaño);
    if(compararSuma(array, tamaño)){
        printf("\nLa primera mitad es dominante");
    }
    else{
        printf("\nLa primera mitad NO es dominante");
    }
 }

//siempre se hace igual
 void cargar (int array[], int tamaño){
    for (int i = 0; i < tamaño; i++)
    {
        do
        {
            printf("\nIngrese el %d nro: ", i+1);
            scanf("%*[^0-9]%d", &array[i]);
        } while (array[i] < LINF || array[i]>LSUP);
    }
 }

 void mostrar(int array[], int tamaño){
    printf("\nElementos del array: ");
    for (int i = 0; i < tamaño; i++)
    {
        printf("%d, ", array[i]);
    }
 }


 int compararSuma(int array[], int tamaño){
    int sumaPrimeraMitad = 0;
    int sumaSegundaMitad =0;
    int j = tamaño;
    for (int i = 0; i < j ; i++)
    {
        j = tamaño-1-i;
        sumaPrimeraMitad += array[i];
        sumaSegundaMitad +=array[j];
    }
    
    printf("\n%d", sumaPrimeraMitad);
    printf("\n%d", sumaSegundaMitad);
    
    if(sumaPrimeraMitad > sumaSegundaMitad){
        return TRUE;
    } 
    else{
        return FALSE;
    }
 }

