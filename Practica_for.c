#include <stdio.h>


//N1-4) Pida dos números y sume todos los números comprendidos entre el primero y el segundo
//(inclusive). Debe controlarse que el segundo número sea mayor que el primero.

/*int main(){ 
    int n1, n2;
    do{
        printf("Ingrese el primer número\n");
        scanf("%d", &n1);
        printf("Ingrese el segúndo número\n");
        scanf("%d", &n2);
        int i;
        int acum;
        for (i=n1; i<=n2; i++){
            acum = acum + i;
        }
        printf("La suma entre todos los números entre: %d y %d es = %d\n", n1, n2, acum);
        acum = 0;
    } while (n1 < n2);

    return 0;
}*/


//N1-5) Solicite dos números y multiplique todos los números comprendidos entre el primero y el
//segundo (inclusive). Debe controlarse que el segundo número sea mayor que el primero.
/*int main(){ 
    int n1, n2;
    do{
        printf("Ingrese el primer número\n");
        scanf("%d", &n1);
        printf("Ingrese el segúndo número\n");
        scanf("%d", &n2);
        int i;
        int result = 1;
        for (i=n1; i<=n2; i++){
            result = result * i ;
            printf("i = %d\n", i);
            printf("result = %d\n", result);
        }
        printf("La multiplicación entre todos los números entre: %d y %d es = %d\n", n1, n2, result);
        result = 0;
    } while (n1 < n2);

    return 0;
}*/


//N1-6) Calcule el promedio de 10 números ingresados por el usuario

/*int main(){ 
    double acum;
    int number;
    printf("A continuación vaya ingresando números hasta completar 10\n");

    for (int i = 1; i <= 10; i++)
    {
        printf("Ingrese número\n");
        scanf("%d", &number);
        acum = acum + number;    
    }
    
    printf("Promedio: %.2f\n", (acum/10));

    return 0;
}*/

// N1-7) Requiera un número entero entre 1 y 15 (controlar esto) y muestre el mismo número de
// asteriscos por pantalla.


int main()
{
    int number;
    do
    {
        do
        {
            printf("Ingrese un número entre 1 y 15\n");
            scanf("%d",&number);
            if(number <1 || number>15){
                printf("No esta entre 1 y 15\n");
                return 0;
            }
        }
        while (1>=number>=15);
        
        for (int i = 1; i <= number; i++)
        {
            printf("*\n");
        }
    } while (number != 0);
   return 0;
}