#include <stdio.h>

int main ()
{
    //int cant = 0;
    // printf("\nimprimir los primero 10 numeros pares\n");
    
    //este while es equivalente al for de abajo
    
    // i=0;
    // while (i<10)
    // {
    //     printf("%d\n", 2*i);
    //     i++;    
    // }

    // for (int i=0; i<10; cant=++i){
    //     printf(" %d\n", 2*i);
    // }

    //printf("\nSe mostraron %d numeros\n", cant);
    
    int n = 0;
    for(;;){
    printf("\nIngerese un Numero: (0 para salir)");
    
    scanf ("%d", &n);
    
    if(n !=0){
        if(n%2 == 0) printf ("Es impar");
        else printf("Es par");
    }
    else break;
    

    
}
    return 0;
}