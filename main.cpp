#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

#include "generala.h"

int main(){
    setlocale(LC_ALL, "Spanish");
    int opcion, puntajes[3] = {0}, mejor_ronda[1] = {0};
    char jugador[51], jugador_2[51], mejor_jugador[104];
    while(true){
        system("cls");
        cout << "\t\t   ¡Bienvenido a la generala de Laboratorio 1!\n\n\n";
        cout << "Elija una opción (cualquier otro ingreso para cerrar el juego):\n\n";
        cout << "1. Modo 1 jugador\n\n";
        cout << "2. Modo 2 jugadores\n\n";
        cout << "3. Mostrar puntuación más alta\n\n\n";
        cout << "Opción: ";
        cin >> opcion;
        system("cls");
        switch(opcion){
            case 1:
                jugar_solo(jugador, mejor_jugador, puntajes, mejor_ronda);
                break;
            case 2:
                jugar_versus(jugador, jugador_2, mejor_jugador, puntajes, mejor_ronda);
                break;
            case 3:
                if(puntajes[2] == 0){
                    cout << "¡Aún no se ha jugado ninguna partida!\n\n";
                } else{
                    mostrar_puntuacion_maxima(mejor_jugador, puntajes[2], mejor_ronda[0]);
                }
                system("pause");
                break;
            default:
                return 0;
        }
    }
    return 0;
}
