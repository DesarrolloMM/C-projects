/*Conceptos de programación:
    Compilador:
        Genera un programa stand-alone (se puede ejecutar por sí solo)
        Es mas fácil distribuir un programa compilado (respetando la plataforma)
        Analiza y traduce el programa fuente a un equivalente en codigo máquina
        Suele generar programas mas rápidos y eficientes
    
    Interprete:
        Analiza el programa fuente y lo ejecuta directamente, sin generar código equivalente
        Facilita la detección de errores, ya que la ejecución de un programa puede interrumpirse en cualquier momento
        Se precisa del interprete en la plataforma para ejecutar el programa

    Preprocesador:
        El preprocesador de C es una herramienta que opera antes de la compilación real, 
        modificando el código fuente a nivel léxico mediante instrucciones llamadas directivas, 
        las cuales siempre comienzan con el símbolo #.  Su función principal es realizar sustituciones de texto, 
        inclusión de archivos y control condicional del código sin considerar la sintaxis ni semántica del lenguaje    
*/

/*respuesta a parcial 2019:
    Que es el pre-procesador? que hace?
        El pre-procesador de C es una herramienta que opera antes de la compilación real,
        modificando el código fuente a nivel léxico mediantes directiva, las cuales comienzan con el símbolo #.
            Su función principal es realizar sustituciones de código (sustitucion de macros), inclusión de archivos y control condicional del código sin considerar la sintaxis ni lña semántica.
    Para que sirven las funciones?
        Sirven para modularizar y reutilizar código, agregar encapsulamiento (ocultan detalles de su implementacion)
    Que es un array? por que son útiles?
        Es una estructura de datos que almacena una o muchas variables, generalemente, del mismo tipo
        Utilidad: Son funcdamentales para organizar datos relacionados y tratarlos como una unidad en vez de tratarlos como entidades separadas
        Eficiencia: Permiten realizar operaciones de manera compacta y eficiente mediante el uso de índices para acceder a sus elementos
        Manejo de datos: Facilitan tareas como el procesamiento de listas, cadenas de caracteres o tablas complejas.

*/

//Ejercicio del parcial 2019:
#include<stdio.h>

//macro para verificar multiplo de 5
#define esMult5(n) ((n) % 5 == 0)
//identifica nros de 3 cifras
#define tresCifras(n) ((n) >= 100 && (n) <= 999)
//identifica nros impares
#define esImpar(n) ((n)%2 !=0)

//macros para manejar el array
#define MAX 10
#define LINF 0
#define LSUP 999
#define TRUE 1
#define FALSE 0

//prototipos de funciones:
void cargar(int a[], int n);
void mostrar(int a[], int n);
int estaOrdenado(int a[], int n);

int main()
{
    int numeros[MAX];
    int cantidad = MAX;
    int multiplosDeCinco, impares, numerosDeTresCifras = 0;
    cargar(numeros , cantidad);
    mostrar( numeros, cantidad);


    if(estaOrdenado(numeros, cantidad)){
        printf("\nEl array SI está ordenado\n");
    }
    else{printf("\nEl array NO esta ordenado\n");
    }

    for (int i = 0; i < MAX; i++)
    {
        if(esMult5(numeros[i])){
            multiplosDeCinco ++;
        }

        if (tresCifras(numeros[i]))
        {
            numerosDeTresCifras++;
        }

        if (esImpar(numeros[i]))
        {
            impares++;
        }    
    }

    printf("\nCantidad de números impares: %d", impares);
    printf("\nCantidad de números con 3 cífras: %d", numerosDeTresCifras);
    printf("\nCantidad de números que son múltiplos de 5: %d\n",multiplosDeCinco);    

    return 0;
}

//modificaciones, ingresar elementos enteros en un rango de 0 a 999
void cargar(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        do{
            printf("\nIngrese el %2d numero:\n", i+1);
            scanf("%d", &a[i]);
        }while(a[i]<0 || a[i]>999 );
    }
}

void mostrar(int a[], int n){
    for (int  i = 0; i < n; i++)
    {
        printf("\nAqui los nros del array: %d\n", a[i]);
    }
}


int estaOrdenado(int a[], int n){
    // el bucle debe ser hasta uno menos para poder acceder al ultimo
    for (int i = 0; i < n -1; i++)
    {
        if(a[i]>a[i+1]){
            return FALSE;
        } 
    }

    return TRUE;
}