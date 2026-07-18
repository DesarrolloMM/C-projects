#pragma region Dependencias

//Inclusion de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

#pragma endregion

#pragma region Macros
//Declaracion de macros
//Dimension maxima de la matriz
#define DIMENSION_MAXIMA 5
//Estado de las luces
#define ENCENDIDO 1
#define APAGADO 0
//Control
#define VERDADERO 1
#define FALSO 0

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
typedef struct {
    int fila;
    int columna;
    int dimension;
}Celda;

//Estructura para el seguimiento del juego en la interfaz
typedef struct{
    int tablero[DIMENSION_MAXIMA][DIMENSION_MAXIMA];
    int dimension;
    int movimientosRealizados;
    int movimientoMaximo;
    int ganador;
    GtkWidget *ventana;
    GtkWidget *grilla;
    GtkWidget *botones[DIMENSION_MAXIMA][DIMENSION_MAXIMA];
    GtkWidget *labelMovimientos;
    Estadisticas *estadisticas;
    int indiceEstadistica;
} EstadoJuego;

//Variables globales para la interfáz gráfica
EstadoJuego *estadoJuego = NULL;
Estadisticas estadisticas[3];

#pragma endregion

#pragma region Prototipos de funcion

void configuracion(int tablero[][DIMENSION_MAXIMA], int  dimension, char patron);
void presionarCelda(int tablero[][DIMENSION_MAXIMA], int fila, int columna, int dimension);
void alternarLuz(int tablero[][DIMENSION_MAXIMA], int fila, int columna, int dimension);
int victoria(int tablero [][DIMENSION_MAXIMA], int dimension);
void mostrarEstadisticas(Estadisticas estadisticas[]);
void iniciarEstadisticas(Estadisticas estadisticas[]);
void actualizarInterfaz(EstadoJuego *estado);
static void botonPresionado(GtkWidget *widget,  gpointer data);
void mostrarResultado(EstadoJuego *estado, int ganador);
void crearVentanaJuego(int dimension, char patron);
void popUpConfiguracion(int dimension);
void botonDimensionPresionado(GtkWidget *widget, gpointer data);
void mostrarMenuPrincipal(GtkWidget *ventana_menu);

#pragma endregion


//Funcion principal
int main (int argc, char *argv[]){
    gtk_init(&argc, &argv);
    
    iniciarEstadisticas(estadisticas);
    
    GtkWidget *ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(ventana), "Luces Fuera - Menú Principal");
    gtk_window_set_default_size(GTK_WINDOW(ventana), 350, 300);
    gtk_window_set_position(GTK_WINDOW(ventana), GTK_WIN_POS_CENTER);
    
    g_signal_connect(ventana, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    mostrarMenuPrincipal(ventana);
    
    gtk_main();
    
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
void configuracion(int tablero[][DIMENSION_MAXIMA], int dimension, char patron){
    int i,j;

    //Definimos las 3 configuraciones posibles para la partida:
    //Posibles configuraciones 3X3
    int configuracion3A[3][3] = {{1,0,1}, {0,1,0}, {1,0,1}};
    int configuracion3B[3][3] = {{0,1,0}, {1,1,1}, {0,1,0}};
    int configuracion3C[3][3] = {{1,1,0}, {0,1,0}, {0,1,1}};

    //Posibles configuraciones 4x4
    int configuracion4A[4][4] = {{1,0,1,0}, {0,1,0,1}, {1,0,1,0}, {0,1,0,1}};
    int configuracion4B[4][4]= {{0,1,1,0}, {1,0,0,1}, {1,0,0,1}, {0,1,1,0}};
    int configuracion4C[4][4]= {{1,1,1,0}, {0,1,0,1}, {1,0,1,0}, {0,0,1,1}};

    //Posibles configuraciones 5x5
    int configuracion5A[5][5] = {{1,0,1,0,1}, {0,1,0,1,0}, {1,0,1,0,1}, {0,1,0,1,0}, {1,0,1,0,1}};
    int configuracion5B[5][5] = {{0,0,1,0,0}, {0,1,1,1,0}, {1,1,1,1,1}, {0,1,1,1,0}, {0,0,1,0,0}};
    int configuracion5C[5][5] = {{1,1,0,0,1}, {0,1,1,0,0}, {1,0,1,0,1}, {0,0,1,1,0}, {1,0,0,1,1}};

    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            if(dimension == 3){
                if(patron == 'A' || patron == 'a'){
                    tablero[i][j] = configuracion3A[i][j];
                }else if(patron == 'B' || patron == 'b'){
                    tablero[i][j] = configuracion3B[i][j];
                }else{
                    tablero[i][j] = configuracion3C[i][j];
                }
            }else if(dimension == 4){
                if(patron == 'A' || patron == 'a'){
                    tablero[i][j] = configuracion4A[i][j];
                }else if(patron == 'B' || patron == 'b'){
                    tablero[i][j] = configuracion4B[i][j];
                }else{
                    tablero[i][j] = configuracion4C[i][j];
                }

            }else {
                if(patron == 'A' || patron == 'a'){
                    tablero[i][j] = configuracion5A[i][j];
                }else if(patron == 'B' || patron == 'b'){
                    tablero[i][j] = configuracion5B[i][j];
                }else{
                    tablero[i][j] = configuracion5C[i][j];
                }
            }
        
        }
        
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
    //Verificamos que todas las celdas esten APAGADAS (objetivo del juego)
    for(int i = 0; i<dimension; i++){
        for (int j = 0; j < dimension; j++){
            if(tablero[i][j] == ENCENDIDO) return FALSO;  //Si hay una encendida, no gana
        }
    }
    return VERDADERO;  //Todas están apagadas, ¡GANA!
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
void actualizarInterfaz(EstadoJuego *estado){
    for (int i = 0; i < estado->dimension; i++)
    {
        for (int j = 0; j < estado->dimension; j++)
        {
            //Sincronizamos el texto del boton con el estado lógico
            const char *estado_luz = (estado->tablero[i][j] == ENCENDIDO)?  "●" : "○";
            gtk_button_set_label(GTK_BUTTON(estado->botones[i][j]), estado_luz);
        }   
    }
    
    //Actualizar etiqueta de movimientos
    char buffer[50];
    sprintf(buffer, "Movimientos: %d/%d", estado->movimientosRealizados, estado->movimientoMaximo);
    gtk_label_set_text(GTK_LABEL(estado->labelMovimientos), buffer);
}


static void botonPresionado(GtkWidget *widget,  gpointer data){
    Celda *info = (Celda *)data;
    
    presionarCelda(estadoJuego->tablero, info->fila, info->columna, estadoJuego->dimension);
    estadoJuego->movimientosRealizados++;
    estadoJuego->estadisticas[estadoJuego->indiceEstadistica].interaccionesTotales++;
    
    // Actualizamos los botones visuales
    actualizarInterfaz(estadoJuego);
    
    //Verificamos victoria
    if (victoria(estadoJuego->tablero, estadoJuego->dimension)) {
        estadoJuego->ganador = VERDADERO;
        mostrarResultado(estadoJuego, VERDADERO);
    }
    //Verificar derrota
    else if(estadoJuego->movimientosRealizados >= estadoJuego->movimientoMaximo) {
        mostrarResultado(estadoJuego, FALSO);
    }
}

//Mostrar cartel de resultado (ganador/perdedor)
void mostrarResultado(EstadoJuego *estado, int ganador) {
    GtkWidget *dialog;
    const char *mensaje;
    
    if(ganador) {
        mensaje = "¡GANASTE! 🎉\n\nFelicidades, apagaste todas las luces.";
        estado->estadisticas[estado->indiceEstadistica].ganadas++;
    } else {
        mensaje = "PERDISTE 😢\n\nSe acabaron los movimientos disponibles.";
        estado->estadisticas[estado->indiceEstadistica].perdidas++;
    }
    
    dialog = gtk_message_dialog_new(
        GTK_WINDOW(estado->ventana),
        GTK_DIALOG_DESTROY_WITH_PARENT,
        ganador ? GTK_MESSAGE_INFO : GTK_MESSAGE_WARNING,
        GTK_BUTTONS_OK,
        "%s",
        mensaje
    );
    
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    
    //Cerrar la ventana del juego
    gtk_widget_destroy(estado->ventana);
    free(estado);
    estadoJuego = NULL;
}

//Manejo del botón de dimensión
void botonDimensionPresionado(GtkWidget *widget, gpointer data) {
    int dimension = GPOINTER_TO_INT(data);
    popUpConfiguracion(dimension);
}

//Diálogo para seleccionar configuración
void popUpConfiguracion(int dimension) {
    GtkWidget *dialog;
    GtkWidget *vbox;
    GtkWidget *label;
    GtkResponseType response;
    char patron_seleccionado = 0;
    
    dialog = gtk_dialog_new_with_buttons(
        "Selecciona Configuración",
        NULL,
        GTK_DIALOG_MODAL,
        "A", 1,
        "B", 2,
        "C", 3,
        NULL
    );
    
    vbox = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    
    char titulo[100];
    sprintf(titulo, "Elige el patrón para %dx%d", dimension, dimension);
    label = gtk_label_new(titulo);
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 10);
    
    gtk_widget_show_all(dialog);
    response = gtk_dialog_run(GTK_DIALOG(dialog));
    
    if(response == 1) patron_seleccionado = 'A';
    else if(response == 2) patron_seleccionado = 'B';
    else if(response == 3) patron_seleccionado = 'C';
    else patron_seleccionado = 'A';
    
    gtk_widget_destroy(dialog);
    
    if(patron_seleccionado) {
        crearVentanaJuego(dimension, patron_seleccionado);
    }
}

#pragma endregion

#pragma region Manejo De interfaz gráfica
//Creamos la ventana principal del juego
void crearVentanaJuego(int dimension, char patron) {
    EstadoJuego *estado = malloc(sizeof(EstadoJuego));
    estado->dimension = dimension;
    estado->movimientosRealizados = 0;
    estado->ganador = FALSO;
    estado->indiceEstadistica = dimension - 3; //0 para 3x3, 1 para 4x4, 2 para 5x5
    
    estado->estadisticas = estadisticas;
    estado->estadisticas[estado->indiceEstadistica].jugadas++;
    
    estado->movimientoMaximo = (dimension == 3) ? MOVIMIENTOS_MAXIMOS_3 : 
                                (dimension == 4) ? MOVIMIENTOS_MAXIMOS_4 : 
                                MOVIMIENTOS_MAXIMOS_5;
    
    //Configuramos el tablero
    configuracion(estado->tablero, dimension, patron);
    
    estadoJuego = estado;
    
    //Creamos la ventana principal
    estado->ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(estado->ventana), "Luces Fuera!");
    gtk_window_set_default_size(GTK_WINDOW(estado->ventana), 400, 500);
    
    GtkWidget *vbox_principal = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_set_border_width(GTK_CONTAINER(vbox_principal), 10);
    gtk_container_add(GTK_CONTAINER(estado->ventana), vbox_principal);
    
    //Movimientos
    estado->labelMovimientos = gtk_label_new("");
    PangoAttrList *attrs = pango_attr_list_new();
    PangoAttribute *attr = pango_attr_size_new(18000);
    pango_attr_list_insert(attrs, attr);
    gtk_label_set_attributes(GTK_LABEL(estado->labelMovimientos), attrs);
    pango_attr_list_unref(attrs);
    gtk_box_pack_start(GTK_BOX(vbox_principal), estado->labelMovimientos, FALSE, FALSE, 0);
    
    //Grilla de botones
    estado->grilla = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(estado->grilla), 5);
    gtk_grid_set_column_spacing(GTK_GRID(estado->grilla), 5);
    gtk_box_pack_start(GTK_BOX(vbox_principal), estado->grilla, TRUE, TRUE, 0);
    
    //Creamos los botones
    for(int i = 0; i < dimension; i++) {
        for(int j = 0; j < dimension; j++) {
            Celda *info = malloc(sizeof(Celda));
            info->fila = i;
            info->columna = j;
            info->dimension = dimension;
            
            estado->botones[i][j] = gtk_button_new_with_label("●");
            
            //Hacer botones más grandes
            gtk_widget_set_size_request(estado->botones[i][j], 60, 60);
            PangoAttrList *btn_attrs = pango_attr_list_new();
            PangoAttribute *btn_attr = pango_attr_size_new(24000);
            pango_attr_list_insert(btn_attrs, btn_attr);
            gtk_label_set_attributes(
                GTK_LABEL(gtk_bin_get_child(GTK_BIN(estado->botones[i][j]))), 
                btn_attrs
            );
            pango_attr_list_unref(btn_attrs);
            
            g_signal_connect(estado->botones[i][j], "clicked", 
                           G_CALLBACK(botonPresionado), info);
            
            gtk_grid_attach(GTK_GRID(estado->grilla), estado->botones[i][j], j, i, 1, 1);
        }
    }
    
    actualizarInterfaz(estado);
    gtk_widget_show_all(estado->ventana);
}

//Mostramos el menú principal
void mostrarMenuPrincipal(GtkWidget *ventana_menu) {
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 20);
    gtk_container_add(GTK_CONTAINER(ventana_menu), vbox);
    
    //Título
    GtkWidget *titulo = gtk_label_new("LUCES FUERA");
    PangoAttrList *attrs = pango_attr_list_new();
    PangoAttribute *attr = pango_attr_size_new(48000);
    pango_attr_list_insert(attrs, attr);
    gtk_label_set_attributes(GTK_LABEL(titulo), attrs);
    pango_attr_list_unref(attrs);
    gtk_box_pack_start(GTK_BOX(vbox), titulo, FALSE, FALSE, 0);
    
    //Botones de dimensión
    GtkWidget *boton3x3 = gtk_button_new_with_label("Jugar 3x3");
    gtk_widget_set_size_request(boton3x3, 150, 50);
    g_signal_connect(boton3x3, "clicked", G_CALLBACK(botonDimensionPresionado), GINT_TO_POINTER(3));
    gtk_box_pack_start(GTK_BOX(vbox), boton3x3, FALSE, FALSE, 0);
    
    GtkWidget *boton4x4 = gtk_button_new_with_label("Jugar 4x4");
    gtk_widget_set_size_request(boton4x4, 150, 50);
    g_signal_connect(boton4x4, "clicked", G_CALLBACK(botonDimensionPresionado), GINT_TO_POINTER(4));
    gtk_box_pack_start(GTK_BOX(vbox), boton4x4, FALSE, FALSE, 0);
    
    GtkWidget *boton5x5 = gtk_button_new_with_label("Jugar 5x5");
    gtk_widget_set_size_request(boton5x5, 150, 50);
    g_signal_connect(boton5x5, "clicked", G_CALLBACK(botonDimensionPresionado), GINT_TO_POINTER(5));
    gtk_box_pack_start(GTK_BOX(vbox), boton5x5, FALSE, FALSE, 0);
    
    GtkWidget *botonSalir = gtk_button_new_with_label("Salir");
    gtk_widget_set_size_request(botonSalir, 150, 50);
    g_signal_connect(botonSalir, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), botonSalir, FALSE, FALSE, 0);
    
    gtk_widget_show_all(ventana_menu);
}    

#pragma endregion

