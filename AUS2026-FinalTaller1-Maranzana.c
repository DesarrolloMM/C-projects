//Inclusion de bibliotecas
#include <stdio.h>
#include <stdlib.h>


//Declaracion de macros
//Dimension maxima de la matriz
#define DIMENSION_MAXIMA 5
//Estado de las luces
#define ENCENDIDO 1
#define APAGADO 0
//Control
#define TRUE 1
#define FALSE 0

// Límites de movimientos sugeridos por dimensión
#define MOVIMIENTOS_MAXIMOS_3 15
#define MOVIMIENTOS_MAXIMOS_4 30
#define MOVIMIENTOS_MAXIMOS_5 45

//Estructuras para la estadisticas

typedef struct {
    int jugadas;
    int ganadas;
    int perdidas;
    int abandonadas;
    int interaccionesTotales;
} Estadisticas;


//Prototipos de funcion
void configuracion(int tablero[][DIMENSION_MAXIMA], int  dimension);
void mostrarTablero(int tablero[][DIMENSION_MAXIMA], int dimension);
void presionarCelda(int tablero[][DIMENSION_MAXIMA], int fila, int columna, int dimension);
void cambiarLuz(int tablero[][DIMENSION_MAXIMA], int fila, int columna, int dimension);
int victoria(int tablero [][DIMENSION_MAXIMA], int dimension);
void mostrarEstadisticas(Estadisticas estadisticas[]);
void iniciarEstadisticas(Estadisticas estadisticas[]);


//Funcion principal
int main (){
    int tablero[DIMENSION_MAXIMA][DIMENSION_MAXIMA];
    int opcion, dimension, movimientoMaximo; 
    //Establecemos los valores de la estructura estadisticas como:
    //Indice 0 = 3x3
    //Indice 1 = 4x4
    //Indice 2 = 5x5
    Estadisticas estadisticas[4];

    iniciarEstadisticas(estadisticas);

    do{
        //menú
        printf("\n1. Jugar 3x3 \n2 Jugar 4x4\n3 Jugar 5x5 \n0. Salir");
        printf("\n Elija una opción: ");
        scanf("%d", &opcion);

        if(opcion >= 1 && opcion <= 3){
            //Convertimos la opcion en dimension para el tablero
            dimension = opcion+2;
            movimientoMaximo = (dimension == 3) ? MOVIMIENTOS_MAXIMOS_3 : (dimension == 4) ? MOVIMIENTOS_MAXIMOS_4 : MOVIMIENTOS_MAXIMOS_5;            
            
        
            int movimientosRealizados = 0;
            int ganador = FALSE;
            int partidaAbandonada = FALSE;

            configuracion (tablero, dimension);
            //Restamos 1 porque el índice inicia en 0
            estadisticas[opcion - 1].jugadas++;

            while (movimientosRealizados < movimientoMaximo && !ganador && !partidaAbandonada){
                int respuesta, c;
                mostrarTablero(tablero, dimension);
                printf("\n Movimientos: %d%d", movimientosRealizados,movimientoMaximo);
                printf("\n Ingrese fila y columna (0 a %d) o + -1 para salir", dimension-1);
                scanf("%d",&respuesta);
                    if (respuesta == -1){
                        partidaAbandonada = TRUE;
                        break;
                    }
                scanf("%d", &c);

                if(respuesta >= 0 && respuesta < dimension && c >= 0 && c < dimension){
                    movimientosRealizados++;
                    estadisticas[opcion - 1].interaccionesTotales++;
                    ganador = victoria(tablero, dimension);
                }
                else{
                    printf("\n Coordenadas invalidas.");
                }
            }

            mostrarTablero(tablero, dimension);
                if(ganador){
                    printf("\n GANADOR!!!");
                    estadisticas[opcion - 1];
                }
                else{
                    printf("\n Limite de movimientos alcanzado.\n");
                    estadisticas[opcion - 1].perdidas++;
                }
            }
        } while (opcion != 0);
    mostrarEstadisticas(estadisticas);
    return 0;
}


//Funciones

//Seteamos la configuración de la partida
void configuracion(int tablero[][DIMENSION_MAXIMA], int dimension){
    char opcion;
    int i,j;

    //Definimos las 3 configuraciones posibles para la partida:
    //Posibles configuraciones 3X3
    int configuracion3A[2][2] = {{1,0,1}, {0,1,0}, {1,0,1}};
    int configuracion3B[2][2] = {{0,1,0}, {1,1,1}, {0,1,0}};
    int configuracion3C[2][2] = {{1,1,0}, {0,1,0}, {0,1,1}};

    //Posibles configuraciones 4x4
    int configuracion4A[3][3] = {{1,0,1,0}, {0,1,0,1}, {1,0,1,0}, {0,1,0,1}};
    int configuracion4B[3][3]= {{0,1,1,0}, {1,0,0,1}, {1,0,0,1}, {0,1,1,0}};

    //Posibles configuraciones 5x5
    int configuracion5A[5][5] = {{1,1,0,0,0}, {1,1,1,0,0}, {0,1,1,1,0}, {0,0,1,1,1}, {0,0,0,1,1}};

    printf("\n Elija el patron inicial para %dx%d (A, B o C)", dimension, dimension);
    scanf(" %c", &opcion);

    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            if(dimension == 3){
                if(opcion == 'A' || opcion == 'a'){
                    tablero[i][j] = configuracion3A[i][j];
                }else if(opcion == 'B' || opcion == 'b'){
                    tablero[i][j] = configuracion3B[i][j];
                }else{
                    tablero[i][j] = configuracion3C[i][j];
                }
            }else if(dimension ==4){
                if(opcion == 'A' || opcion == 'a'){
                    tablero[i][j] = configuracion4A[i][j];
                }else{
                    tablero[i][j] = configuracion4B[i][j];
                }

            }else {
                if(opcion == 'A' || opcion == "a"){
                    tablero[i][j] = configuracion5A[i][j];
                }else{
                    tablero[i][j] = configuracion5A[i][j];
                }
            }
        
        }
        
    }
    
}


void mostrarTablero (int tablero[][DIMENSION_MAXIMA], int dimension){
    int i, j;  
    printf("\n   ");
    for (i = 0; j< dimension; j++){
        printf("%d ", j);
    }
    printf("\n");
    for (i = 0; i < dimension; i++){
        printf("%d |", i);
        for (int j = 0; j < dimension; j++){
            // ● para endcendido (1) ○ para apagado (0)
            printf("%s ", (tablero[i][j] == ENCENDIDO?  "●" : "○"); 
        }
        printf("\n");
    }
}

void presionarCelda(int tablero [][DIMENSION_MAXIMA], int fila, int columna, int dimension){
    cambiarLuz(tablero, fila, columna, dimension);
    cambiarLuz(tablero, fila-1, columna, dimension);
    cambiarLuz(tablero, fila+1, columna, dimension);
    cambiarLuz(tablero, fila, columna-1, dimension);
    cambiarLuz(tablero, fila, columna+1, dimension);
}