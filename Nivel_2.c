#include <stdio.h>

/*
N2-1) Muestre los divisores de un número.

int main() {

 int number;
  do{
      printf("Ingrese un numero para conocer sus divisores\n");
      scanf("%d",&number);
      for (int i = 1; i <= number; i++)
         {
            if (number % i == 0){
               printf("Divisores de %d:\n %d\n", number, i);
            }
         }  
   } while (number != 0);
 
   return 0;
}  */

//N2-2) Pida un número por teclado y decir si es un número primo o no. Controlar que el usuario ingrese
//un número mayor a 0.
/*
int main(){
   int number;
  do{
      printf("Ingrese un numero para identificar si es primo o no:\n");
      scanf("%d",&number);
      int acum = 0;
      for (int i = 1; i <= number; i++)
         {
            if (number % i == 0){
               acum++;
            }
         }  
         if(acum > 2){
            printf("El numero %d no es primo\n", number);
         } else if (acum == 2){
            printf("El numero %d es primo\n", number);
         }
           
   } while (number != 0);
    
   return 0;
}*/


//N2-3) Calcule la suma de los cuadrados de los 100 primeros números enteros.
/*
int main (){
   int acum = 0;
   for (int i = 1; i <= 100; i++)
      {
         acum += i*i;
      }  
      printf("La suma de los cuadrados de los 100 primeros numeros enteros es: %d\n", acum);
    
   return 0;
}*/


//N2-4) Calcule el promedio de N números, se dejarán de solicitar números hasta que se introduzca el 0. 
// int main (){
//    int contador, acum, number, result;
//    char salida = 'n';
//    do {
//       contador = 0;
//       acum = 0;
//       do
//       {
//          printf("Ingrese numeros para conocer su promedio, para finalizar ingrese 0\n");
//          if (scanf("%d", &number) != 1) {
//             int c;
//             while ((c = getchar()) != '\n' && c != EOF);
//             continue;
//          }

//          if (number != 0)
//          {
//             acum = acum + number;
//             contador ++;
//          }
//       } while (number != 0);

//       if (contador > 0)
//          result = acum / contador;
//       else
//          result = 0;

//       printf("Promedio de los %d numeros es igual a %d\n", contador, result);
//       printf("Ingrese 's' para salir o cualquier otra tecla para continuar: ");
//       scanf(" %c", &salida);

//    } while (salida != 's');
//    return 0;   
// }

// N2-5) Reciba tres enteros positivos n, p y m, asegurándose que n<m
// - genere la salida n, n+p, n+2.p, n+3.p, .... k (k<=m y es de la forma n+NRO.p)
// Ejemplo n=2, p=3, m=10, debe generarse: 2, 5, 8
// Ejemplo n=1, p=4, m=21, debe generarse 1,5,9,13,17,21

// int main (){
//    int n,p,m;
//    do{ 
//       printf("Ingrese 3 enteros positivos separaos por espacios, luego pulse enter: \n");
//       scanf("%d %d %d", &n, &p, &m);
//       if (n<m)
//       {
//          for (int i = 0; i <= m; i++)
//          {
//           printf("%d\n", n+(i*p));
//          }
//       }
//    } while (n != 0 && m != 0 && p !=0);
   
//    return 0;
// }
