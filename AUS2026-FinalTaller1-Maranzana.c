#pragma region Dependencias

//Inclusion de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#pragma endregion

#pragma region Macros
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

#pragma endregion


//Estructuras para la estadisticas
typedef struct {
    int jugadas;
    int ganadas;
    int perdidas;
    int abandonadas;
    int interaccionesTotales;
} Estadisticas;

#pragma region Interfaz gráfica
//Estructura para la interfáz gráfica
typedef struct 
{
    int fila;
    int columna;
    int dimension;
}Celda;

//Variables globales para la interfáz gráfica
GtkWidget *botones[DIMENSION_MAXIMA][DIMENSION_MAXIMA];
int tableroLogico[DIMENSION_MAXIMA][DIMENSION_MAXIMA]

#pragma endregion

#pragma Prototipos de funcion

void configuracion(int tablero[][DIMENSION_MAXIMA], int  dimension);
void mostrarTablero(int tablero[][DIMENSION_MAXIMA], int dimension);
void presionarCelda(int tablero[][DIMENSION_MAXIMA], int fila, int columna, int dimension);
void alternarLuz(int tablero[][DIMENSION_MAXIMA], int fila, int columna, int dimension);
int victoria(int tablero [][DIMENSION_MAXIMA], int dimension);
void mostrarEstadisticas(Estadisticas estadisticas[]);
void iniciarEstadisticas(Estadisticas estadisticas[]);

#pragma endregion

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
        printf("\n1. Jugar 3x3 \n2. Jugar 4x4\n3. Jugar 5x5 \n0. Salir");
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
            
            //Creamos la ventana grafica
            GtkWidget *ventqana, *grilla;
            gtk_init (&argc, &argv);
            ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
            gtk_window_set_title(GTK_WINDOW(ventana), "Luces Fuera!");
            grilla = gtk_grid_new();
            gtk_container_add(GTK_CONTAINER(ventana), grilla);
            for (int i = 0; i < dimension; i++)
            {
                for (int j = 0; j < dimension; i++)
                {
                    Celda *info = malloc(sizeof(Celda));
                    info->fila = i; info->columna = j; info->dimension = dimension;
                    matriz_botones[i][j] = gtk_button_new();

                    //Capturamos el clic
                    g_signal_connect(matriz_botones[i][j], "clicked", G_CALLBACK(botonPresionado), info);
                    //Colocamos en la grilla visual
                    gtk_grid_attach(GTK_GRID(grilla), matriz_botones[i][j], j,i,1,1);
                }                
            }

            //Actualizamos la ventana
            actualizarInterfaz(dimension);
            gtk_widget_show_all(ventana);
            //Cedemos el control a la interfaz gráfica
            gtk_main()

            //Restamos 1 porque el índice inicia en 0
            estadisticas[opcion - 1].jugadas++;

            while (movimientosRealizados < movimientoMaximo && !ganador && !partidaAbandonada){
                int fila, columna;
                mostrarTablero(tablero, dimension);
                printf("\n Movimientos: %d/%d", movimientosRealizados,movimientoMaximo);
                printf("\n Ingrese la fila y luego la columna (0 a %d) o + -1 para salir\n", dimension-1);
                scanf("%d",&fila);
                    if (fila == -1){
                        partidaAbandonada = TRUE;
                        break;
                    }
                scanf("%d", &columna);

                if(fila >= 0 && fila < dimension && columna >= 0 && columna < dimension){            
                    presionarCelda(tablero,fila,columna,dimension);
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


#pragma region Funciones

//Inicializamos las estadisticas en 0
void iniciarEstadisticas(Estadisticas estadisticas[]){
    for(int i=0; i < 3; i++){
        estadisticas[i].ganadas = 0;
        estadisticas[i].perdidas = 0;
        estadisticas[i].jugadas = 0;
        estadisticas[i].abandonadas = 0;
        estadisticas[i].interaccionesTotales = 0;
    }
}


//Seteamos la configuración de la partida
void configuracion(int tablero[][DIMENSION_MAXIMA], int dimension){
    char opcion;
    int i,j;

    //Definimos las 3 configuraciones posibles para la partida:
    //Posibles configuraciones 3X3
    int configuracion3A[3][3] = {{1,0,1}, {0,1,0}, {1,0,1}};
    int configuracion3B[3][3] = {{0,1,0}, {1,1,1}, {0,1,0}};
    int configuracion3C[3][3] = {{1,1,0}, {0,1,0}, {0,1,1}};

    //Posibles configuraciones 4x4
    int configuracion4A[4][4] = {{1,0,1,0}, {0,1,0,1}, {1,0,1,0}, {0,1,0,1}};
    int configuracion4B[4][4]= {{0,1,1,0}, {1,0,0,1}, {1,0,0,1}, {0,1,1,0}};

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
            }else if(dimension == 4){
                if(opcion == 'A' || opcion == 'a'){
                    tablero[i][j] = configuracion4A[i][j];
                }else{
                    tablero[i][j] = configuracion4B[i][j];
                }

            }else {
                if(opcion == 'A' || opcion == 'a'){
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
    for (j = 0; j< dimension; j++){
        printf("%d ", j);
    }
    printf("\n");
    for (i = 0; i < dimension; i++){
        printf("%d |", i);
        for (int j = 0; j < dimension; j++){
            // ● para endcendido (1) ○ para apagado (0)
            printf("%s ", (tablero[i][j] == ENCENDIDO?  "●" : "○")); 
        }
        printf("\n");
    }
}

void presionarCelda(int tablero [][DIMENSION_MAXIMA], int fila, int columna, int dimension){
    alternarLuz(tablero, fila, columna, dimension);
    alternarLuz(tablero, fila-1, columna, dimension);
    alternarLuz(tablero, fila+1, columna, dimension);
    alternarLuz(tablero, fila, columna-1, dimension);
    alternarLuz(tablero, fila, columna+1, dimension);
}


void alternarLuz (int tablero[][DIMENSION_MAXIMA], int fila, int columna, int dimension){
    if(fila >= 0 && fila < dimension && columna >= 0 && columna < dimension){
        tablero[fila][columna] = !tablero [fila][columna];
    }
}



int victoria (int tablero [][DIMENSION_MAXIMA], int dimension){
    //Verificamos que todas las celdas esten encendidas
    for(int i = 0; i<dimension; i++){
        for (int j = 0; j < dimension; j++){
            if(tablero[i][j] == ENCENDIDO) return FALSE;
        }
    }
    return TRUE;
}

void mostrarEstadisticas( Estadisticas estadisticas[]){
    printf("\nFIN DEL JUEGO");
    
    for(int i=0; i<3; i++){
        int dimension = i+3;
        printf("\nPartidas en %dx%d - %d Gandas vs %d Perdidas - %d Jugadas - %d Interacciones Totales",
        dimension, dimension, estadisticas[i].ganadas, estadisticas[i].perdidas, estadisticas[i].jugadas, estadisticas[i].interaccionesTotales);
        
        if(estadisticas[i].abandonadas > 0){
            printf("\nAbandonadas: %d", estadisticas[i].abandonadas);
        }
    }
    printf("\n");
}

//Funciones para controlar la interfaz gráfica
void actualizarInterfaz(int dimension){
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            //Sincronizamos el texto delboton con el estado lógico
            const char *estado = (tableroLogico[i][j] == ENCENDIDO)? ON:OFF;
            gtk_button_set_label(GTKBUTTON(botones[i][j]), estado);
        }   
    }
}


static void botonPresionado(GtkWidget *widget,  gpointer data){
    
    Celda *info = (Celda *)data;
    presionarCelda(tableroLogico, info->fila, info->columna, info->dimension);
    // Actualizamos los botones visuales
    actualizarInterfaz(info->dimension);
    //Verificamos victoria
    if (victoria(tableroLogico, info->dimension)) {
        printf("¡Has ganado!\n");
    }   
}    

#pragma endregion

