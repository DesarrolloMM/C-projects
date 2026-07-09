#include<stdio.h>
#define MAX 10 //limite del array

//se recomienda usar macros 
#define LINF 5
#define LSUP 10
#define TRUE 1
#define FALSE 0

void cargar (int a [], int n);
void mostrar(int a [], int n);
int mIguales(int a[], int n);

int main(){
    int num[MAX];
    int cantidad = MAX;

    cargar (num, cantidad);
    mostrar(num, cantidad);

    //0 es falso, cualquier cosa distinta de 0 es verdadera
    if (mIguales(num, cantidad)) printf("\nLas sumas son iguales\n"); 
    else printf("\nLas sumas son distintas\n");

return 0;
}


void cargar(int x[], int n){
    for (int i = 0; i < n; i++)
    {
        do{
        printf("\nIngrese el %2d numero entero:", i + 1);
        //el nombre del array es un puntero al primer elemento del array
        // por tanto esta expresion vale: scanf("%d", x+i);
        //en la siguiente, se necesista el ampersand
        //si hubiese alguna validación habría que agregar un do while de esta forma,
        //se repite mientras el nro ingresado sea incorrecto(le erraste, proba de nuevo)
        scanf("%d", &x[i]);
        } while (x[i]<LINF || x[i]>LSUP);    
    }
}
    
void mostrar(int x[], int n){
    printf("\n"); 
    for (int i = 0; i < n; i++)
    {
        printf("%4d, ",x[i]);
        printf("\n");
    }
}

int mIguales(int a[], int n){
    int psuma, ssuma;
    int i, j; //j = n-1-i

    int retorno = FALSE;

    psuma = 0;
    ssuma = 0;
    j = n-1;
    //de esta forma con una sola pasada de for hago ambas sumas
    //primera suma y segunda suma
    for (i = 0; i < j; i++){
        j = n-1-i;
        psuma = psuma + a[i];
        ssuma = ssuma +a[j];
    }

    
    printf("\n%d %d\n", psuma, ssuma );
    if (psuma == ssuma) retorno = TRUE;
    
return retorno;
}