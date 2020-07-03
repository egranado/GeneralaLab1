#ifndef GENERALA_H_INCLUDED
#define GENERALA_H_INCLUDED


/* Muestra lo que contiene cada una de las posiciones de un vector */
void mostrar_vector(int v[], int tam);

/* Asigna el valor 0 a todas las posiciones de un vector */
void cargar_cero(int v[], int tam);

/* Devuelve la cantidad de apariciones de un número en un vector */
int contar_apariciones(int v[], int tam , int numero);

/* Devuelve el máximo de un vector */
int buscar_maximo(int v[], int tam);

/* Ordena de menor a mayor un vector */
void ordenar_vector(int v[], int tam );

/* Copia los elementos de un vector en otro */
void copiar_vector(int v[], int v2[],int tam );

/* Asigna valores por ingreso a cada una de las posiciones de un vector cuyo valor sea 0 */
void cargar_dados(int v[], int tam);

/* Asigna valores aleatorios a cada una de las posiciones de un vector cuyo valor sea 0 */
void tirar_dados(int v[], int tam, int limite);

/* Devuelve true si encuentra la cantidad de apariciones enviadas por parámetro de valores de 1 a 6 en un vector */
bool comprobar_apariciones(int v[], int tam, int apariciones_buscadas);

/* Devuelve true si corrobora que hay full house en un vector*/
bool comprobar_full(int v[], int tam);

/* Devuelve true si corrobora que hay escalera en un vector */
bool comprobar_escalera(int v[], int v2[], int tam);

/* Devuelve el máximo valor entre los juegos posibles */
int calcular_mejor_juego(int v[], int v3[], int tam, int tam3);

/* Devuelve el puntaje de la jugada */
int puntuar_jugada(int v[], int v2[], int v3[], int tam, int tam3);

/* Sobreescribe los datos en el ranking de puntuación máxima si esta es superada */
void establecer_ranking(char jugador[], int ronda, int puntaje, char mejor_jugador[], int mejor_ronda[], int puntajes[]);

/* Imprime el encabezado con el estado del juego */
void imprimir_encabezado(char jugador[], int ronda, int puntaje, int lanzamiento);

/* Imprime el estado del juego antes de iniciar una nueva ronda */
void imprimir_entre_turnos(char jugador[], int ronda, int puntaje);

/* Imprime el estado del juego en el cambio de turno entre un jugador y otro */
void imprimir_entre_turnos_versus(char jugador[], char jugador_2[], int ronda, int bandera_jugador, int puntaje, int puntaje_2);

/* Imprime los datos del jugador al ganar la partida */
void imprimir_ganador(char jugador[], int ronda, int puntaje);

/* Imprime los datos de la partida en caso de empate */
void imprimir_empate(char jugador[], char jugador_2[], int ronda, int puntaje);

/* Muestra en pantalla los datos del jugador con la puntuación más alta */
void mostrar_puntuacion_maxima(char mejor_jugador[], int puntaje, int mejor_ronda);

/* Inicia una partida de generala de un jugador */
int jugar_solo(char jugador[], char mejor_jugador[], int puntajes[], int mejor_ronda[]);

/* Inicia una partida de generala de dos jugadores */
int jugar_versus(char jugador[], char jugador_2[], char mejor_jugador[], int puntajes[], int mejor_ronda[]);

#endif // GENERALA_H_INCLUDED
