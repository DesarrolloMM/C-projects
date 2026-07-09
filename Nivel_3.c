#include <stdio.h>
// N3-1) Muestre el abecedario por pantalla en ambos sentidos.
// int main() {
//     // Sentido ascendente: de 'a' a 'z'
//     printf("Abecedario Ascendente:\n");
//     for (char c = 'a'; c <= 'z'; c++) {
//         printf("%c ", c);
//     }
    
//     printf("\n\nAbecedario Descendente:\n");
//     // Sentido descendente: de 'z' a 'a'
//     for (char c = 'z'; c >= 'a'; c--) {
//         printf("%c ", c);
//     }
    
//     printf("\n");
//     return 0;
// }


// N3-2) Calcule el factorial de un número entero positvo. ¿Que sucede cuando el resultado es un número
// muy grande? ¿Cómo se puede atenuar el problema?

int main() {  
    int number, result = 1;
    do
    {
        scanf("%d", &number);
        printf("factorial:\n");
        for (int i = number; i >= 1; --i) {
            result = result*i;
        }
    printf("%d\n",result);    
    } while (number != 0);
    
    
return 0;
}