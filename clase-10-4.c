/*dio operadores lógicos, incremento
    return, goto (no se usa, mala idea)
    uso el ejemplo de la calculadora para explicar la estructura switch

*/

#include <stdio.h>

int main() {

   float num1;
   float num2;
   char op;

   printf("Ingrese un numero: ");
   scanf("%f", &num1);  //num:valor de la var,   &num:en que lugar de la M esta la variable

   printf("Ingrese otro numero: ");
   scanf("%f", &num2);

   printf("Ingrese el operador: ");
   scanf(" %c", &op); //truco dejo un espacio "_%c" en lugar de "%c"

   switch (op) {
      case '+':
         printf("La suma %.2f + %.2f es %.2f\n", num1, num2, num1+num2);
         break;
      case '-':
         printf("La resta %.2f - %.2f es %.2f\n", num1, num2, num1-num2);
         break;
      case '*':
         printf("El producto %.2f * %.2f es %.2f\n", num1, num2, num1*num2);
         break;
      case '/':
         if(num2!=0) {
            printf("La divsion %.2f / %.2f es %.2f\n", num1, num2, num1/num2);
         } else { //caso num2==0
            printf("Augh!!! Intento de division por cero!!!\n");
            return -1;
         }
         break;
      case '%':
         if(num2!=0) {
            printf("El módulo %.2f %% %.2f es %d\n", num1, num2, (int)num1%(int)num2);
         } else { //caso num2==0
            printf("Augh!!! Intento de division por cero al calcular el modulo!!!\n");
            return -1;
         }
         break;
   default:
         //operador desconocido
         //llego aca si op no aplica para ninguno de los casos anteriores
         printf("Al operador %c no lo conozco!!!\n", op);
         break;
   }

   return 0;
}