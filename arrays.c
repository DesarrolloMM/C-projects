#include <stdio.h>

int main(){
    int decano[10];

    printf("Ingrese 10 numeros, comprendidos de -10 a 10, pulse enter mientras va agregando\n");
    for (int i=0; i < 10; i++){
        scanf("%d",&decano[i]);
        
    }
    //mostrar para corroborar
    for (int i=0; i < 10; i++){
        printf("Resultado:%d\n",decano[i]);
    }
    return 0;
}
