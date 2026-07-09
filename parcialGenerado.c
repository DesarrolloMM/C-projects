#include <stdio.h>

#define LINF 10
#define LSUP 50
#define MAX 12
#define TRUE 1
#define FALSE 0

void cargar(int a[], int n);
void mostrar(int a[], int n);
int compararMitades(int a[], int n);

int main()
{   
    int numeros[MAX];
    int cantidad = MAX;
    
    cargar(numeros, cantidad); 
    mostrar(numeros, cantidad);

    if(compararMitades(numeros,cantidad)){
        printf("\nLas cantidades de pares son iguales");
    }
    else{
        printf("\nLas cantidades de pares son distintas");
    }
    return 0;
}

void cargar(int a[], int n)
{
    
    for (int i = 0; i<n; i++)
    {
        do
        {
            printf("\nIngrese el %d numero: ", i+1);
            scanf("%d", &a[i]);
        } while (a[i]<LINF || a[i]>LSUP);
    }    
}

void mostrar(int a[], int n){
    printf("\nElementos del array: ");
    for (int i = 0; i < n; i++)
    {     
        printf("%d,", a[i]);
    }
}

int compararMitades(int a [], int n){
    int cantidadDeParesIzquierda, cantidadDeParesDerecha=0;
    int j = n;
    for (int i = 0; i < j; i++)
    {
        j = n-1-i;
        if(a[i]%2){}
        else{
            cantidadDeParesIzquierda++;
        }

        if(a[j]%2){}
        else{
            cantidadDeParesDerecha++;
        }
    }
    
    if(cantidadDeParesDerecha == cantidadDeParesIzquierda){
        return TRUE;
    }
    else{
        return FALSE;
    }    
}


