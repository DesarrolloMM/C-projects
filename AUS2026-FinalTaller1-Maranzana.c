//Inclusion de bibliotecas
#include <stdio.h>
#include <stdlib.h>


//Declaracion de macros
//Dimension maxima de la matriz
#define MAX 5
//Estado de las luces
#define ENCENDIDO 1
#define APAGADO 0
//Control
#define TRUE 1
#define FALSE 0

// Límites de movimientos sugeridos por dimensión
#define MAX_MOV_3 15
#define MAX_MOV_4 30
#define MAX_MOV_5 45

//Estructuras para la estadisticas

typedef struct {
    int ganadas;
    int perdidas;
    int abandonadas;
    int interaccionesTotales;
} Estadisticas;


//Prototipos de funcion
void configuracion(int tablero[][MAX], int  dimensiones);
void mostrarTablero(int tablero[][MAX], int dimensiones);
void presionarCelda(int tablero[][MAX], int r, int c, int dimensiones);
void cambiarLuz(int tablero[][MAX], int r, int c, int dimensiones);
void victoria();


//Funcion principal
int main (){
    return 0;
}

//Funciones
