#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
#include "generala.h"

void mostrar_vector(int v[], int tam){
    int i;
    for(i = 0; i < tam; i++){
        cout << v[i] << "\t";
    }
}

void cargar_cero(int v[], int tam){
    int i;
    for(i = 0; i < tam; i++){
        v[i] = 0;
    }
}

int contar_apariciones(int v[], int tam, int numero){
    int i, cant = 0;
    for(i = 0; i < tam; i++){
        if(v[i] == numero) cant++;
        }
    return cant;
}

int buscar_maximo(int v[], int tam){
    int i, maximo = v[0];
    for(i = 1; i < tam; i++){
        if(v[i] > maximo){
            maximo = v[i];
        }
    }
    return maximo;
}

void ordenar_vector(int v[], int tam){
    int i, j, posmin, aux;
    for(i = 0; i < tam - 1; i++){
        posmin = i;
        for(j = i + 1; j < tam; j++){
            if(v[j] < v[posmin]) posmin = j;
        }
        aux = v[i];
        v[i] = v[posmin];
        v[posmin] = aux;
    }
}

void copiar_vector(int v[], int v2[], int tam){
    int i;
    for(i = 0; i < tam; i++){
        v2[i] = v[i];
    }
}

void cargar_dados(int v[], int tam){
    int i;
    for(i = 0; i < tam; i++){
        if(v[i] == 0){
            cout << "Ingrese valor: ";
            cin >> v[i];
            cout << endl << endl;
        }
    }
}

void tirar_dados(int v[], int tam, int limite){
    int i;
    srand(time(NULL));
    for(i = 0; i < tam; i++){
        if(v[i] == 0){
            v[i] = (rand() % limite) + 1;
        }
    }
}

bool comprobar_apariciones(int v[], int tam, int apariciones_buscadas){
    int apariciones;
    for(int i = 1; i <= 6; i++){
        apariciones = contar_apariciones(v, tam, i);
        if(apariciones == apariciones_buscadas){
            return true;
        }
    }
    return false;
}

bool comprobar_full(int v[], int tam){
    int apariciones, apariciones2, i, j;
    for(i = 1; i <= 6; i++){
        apariciones = contar_apariciones(v, tam, i);
        if(apariciones == 3){
            break;
        }
    }
    if(apariciones != 3){
        return false;
    }
    for(j = 1; j <= 6; j++){
        if(j == i){
            continue;
        } else{
            apariciones2 = contar_apariciones(v, tam, j);
            if(apariciones2 == 2){
                return true;
            }
        }
    } return false;
}

bool comprobar_escalera(int v[], int v2[], int tam){
    copiar_vector(v, v2, tam);
    ordenar_vector(v2, tam);
    for(int i = 1; i < tam; i++){
        if(v2[i] <= v2[i - 1] || (v2[i] - v2[i - 1]) != 1){
            return false;
        }
    } return true;
}

int calcular_mejor_juego(int v[], int v3[], int tam, int tam3){
    int apariciones;
    for(int i = 1; i <= 6; i++){
        apariciones = contar_apariciones(v, tam, i);
        v3[i - 1] = i * apariciones;
    }
    return buscar_maximo(v3, tam3);
}

int puntuar_jugada(int v[], int v2[], int v3[], int tam, int tam3){
    if(comprobar_apariciones(v, tam, 5)){
        return 50;
    }
    if(comprobar_apariciones(v, tam, 4)){
        return 40;
    }
    if(comprobar_full(v, tam)){
        return 30;
    }
    if(comprobar_escalera(v, v2, tam)){
        return 25;
    }
    return calcular_mejor_juego(v, v3, tam, tam3);
}

void establecer_ranking(char jugador[], int ronda, int puntaje, char mejor_jugador[], int mejor_ronda[], int puntajes[]){
    if(puntaje > puntajes[2]){
        puntajes[2] = puntaje;
        mejor_ronda[0] = ronda;
        strcpy(mejor_jugador, jugador);
    }
}

void imprimir_encabezado(char jugador[], int ronda, int puntaje, int lanzamiento){
    cout << "Turno de: " << jugador << "\n\nRonda: " << ronda << "\n\nPuntaje Total: " << puntaje << "\n\n";
    cout << "--------------------------------------------------------------------------------\n";
    cout << "Lanzamiento N° " << lanzamiento << ":\n\n\n\n\n";
}

void imprimir_entre_turnos(char jugador[], int ronda, int puntaje){
    cout << "\n\n\n\n\n\n\n\n\t\t\t\tRonda: " << ronda;
    cout << "\n\n\t\t\t\t" << jugador;
    cout << "\n\n\t\t\t\tPuntaje: " << puntaje << "\n\n\n\n\n\n";
}

void imprimir_entre_turnos_versus(char jugador[], char jugador_2[], int ronda, int bandera_jugador, int puntaje, int puntaje_2){
    cout << "\n\n\n\n\n\n\n\n\t\t\t\tRonda: " << ronda;
    if(bandera_jugador == 1){
        cout << "\n\n\t\t\t\tPróximo turno: " << jugador;
    } else{
        cout << "\n\n\t\t\t\tPróximo turno: " << jugador_2;
    }
    cout << "\n\n\t\t\t\tPuntaje de " << jugador << ": " << puntaje;
    cout << "\n\n\t\t\t\tPuntaje de " << jugador_2 << ": " << puntaje_2 << "\n\n\n\n\n\n";
}

void imprimir_ganador(char jugador[], int ronda, int puntaje){
    cout << "\n\n\n\n\n\n\n\n\t\t\t\tGanador: " << jugador;
    cout << "\n\n\t\t\t\tRondas requeridas: " << ronda;
    cout << "\n\n\t\t\t\tPuntaje: " << puntaje << "\n\n\n\n\n\n";
}

void imprimir_empate(char jugador[], char jugador_2[], int ronda, int puntaje){
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t¡" << jugador << " y " << jugador_2 << " empataron!";
    cout << "\n\n\t\t\t\tRondas requeridas: " << ronda;
    cout << "\n\n\t\t\t\tPuntaje: " << puntaje << "\n\n\n\n\n\n";
}

void mostrar_puntuacion_maxima(char mejor_jugador[], int puntaje, int mejor_ronda){
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t" << mejor_jugador;
    cout << "\n\n\t\t\t\tRondas requeridas: " << mejor_ronda;
    cout << "\n\n\t\t\t\tPuntaje: " << puntaje << "\n\n\n\n\n\n";
}

int jugar_solo(char jugador[], char mejor_jugador[], int puntajes[], int mejor_ronda[]){
    int rondas_totales, lanzamiento, puntos, ronda_actual = 0, dados[5], dados_copia[5], tam = 5, aparicion_cara[6],
    tam3 = 6, dados_nuevo_tiro, pos_dado;
    char modo[20], ingreso[20], t[] = {'t', '\0'};
    puntajes[0] = 0;
    system("cls");
    cout << "Ingrese su nombre: ";
    cin.ignore();
    cin.getline(jugador, 51);
    cout << "\n\nIngrese la cantidad de rondas a jugar: ";
    cin >> rondas_totales;
    cout << "\n\nIngrese T para activar el modo tester (carga manual de dados), otro ingreso para jugar normalmente: ";
    cin >> modo;
    while(ronda_actual < rondas_totales){
        ronda_actual++;
        lanzamiento = 0;
        cargar_cero(dados, tam);
        system("cls");
        imprimir_entre_turnos(jugador, ronda_actual, puntajes[0]);
        system("pause");
        while(true){
            system("cls");
            lanzamiento++;
            imprimir_encabezado(jugador, ronda_actual, puntajes[0], lanzamiento);
            if(strcasecmp(modo, t) == 0){
                cargar_dados(dados, tam);
            } else{
                tirar_dados(dados, tam, 6);
            }
            mostrar_vector(dados, 5);
            cout << endl << endl << endl;
            if(lanzamiento == 1 && comprobar_apariciones(dados, tam, 5)){
                puntajes[0] += 50;
                cout << "¡Generala servida, felicidades ganó el juego!\n\n";
                establecer_ranking(jugador, ronda_actual, puntajes[0], mejor_jugador, mejor_ronda, puntajes);
                system("pause");
                system("cls");
                imprimir_ganador(jugador, ronda_actual, puntajes[0]);
                system("pause");
                return 0;
            }
            puntos = puntuar_jugada(dados, dados_copia, aparicion_cara, tam, tam3);
            cout << "La jugada actual vale " << puntos << " puntos\n\n";
            system("pause");
            if(lanzamiento == 3){
                puntajes[0] += puntos;
                break;
            }
            cout << "\nIngrese T para volver a tirar algunos o todos los dados, otro ingreso para terminar la ronda: ";
            cin >> ingreso;
            if(strcasecmp(ingreso, t) == 0){
                cout << "\nIngrese cuántos dados vuelve a tirar: ";
                cin >> dados_nuevo_tiro;
                for(int i = 0; i < dados_nuevo_tiro; i++){
                    cout << "\nIngrese la posición (1 a 5) del dado: ";
                    cin >> pos_dado;
                    if(dados[pos_dado - 1] == 0){
                        cout << "\n¡No puede repetir el dado!\n";
                        i--;
                    } else{
                        dados[pos_dado - 1] = 0;
                    }
                }
            } else{
                puntajes[0] += puntos;
                break;
            }
        }
    }
    system("cls");
    establecer_ranking(jugador, ronda_actual, puntajes[0], mejor_jugador, mejor_ronda, puntajes);
    imprimir_ganador(jugador, ronda_actual, puntajes[0]);
    system("pause");
    return 0;
}

int jugar_versus(char jugador[], char jugador_2[], char mejor_jugador[], int puntajes[], int mejor_ronda[]){
    int rondas_totales, lanzamiento, puntos, dados[5], dados_copia[5], tam = 5, aparicion_cara[6],
    tam3 = 6, dados_nuevo_tiro, pos_dado, bandera_jugador = 0, cont_ronda_1 = 0, cont_ronda_2 = 0;
    char modo[20], ingreso[20], t[] = {'t', '\0'}, jugador_activo[51], aux[104];
    puntajes[0] = 0;
    puntajes[1] = 0;
    system("cls");
    cout << "Ingrese el nombre de un jugador: ";
    cin.ignore();
    cin.getline(jugador, 51);
    cout << "\n\nIngrese el nombre del otro jugador: ";
    cin.getline(jugador_2, 51);
    cout << "\n\nIngrese la cantidad de rondas a jugar: ";
    cin >> rondas_totales;
    cout << "\n\nIngrese T para activar el modo tester (carga manual de dados), otro ingreso para jugar normalmente: ";
    cin >> modo;
    while(cont_ronda_2 < rondas_totales){
        bandera_jugador++;
        if(bandera_jugador == 3){
            bandera_jugador = 1;
        }
        if(bandera_jugador == 1){
            strcpy(jugador_activo, jugador);
            cont_ronda_1++;
        } else{ // bandera_jugador == 2 para el jugador_2
            strcpy(jugador_activo, jugador_2);
            cont_ronda_2++;
        }
        lanzamiento = 0;
        cargar_cero(dados, tam);
        system("cls");
        imprimir_entre_turnos_versus(jugador, jugador_2, cont_ronda_1, bandera_jugador, puntajes[0], puntajes[1]);
        system("pause");
        while(true){
            system("cls");
            lanzamiento++;
            imprimir_encabezado(jugador_activo, cont_ronda_1, puntajes[bandera_jugador - 1], lanzamiento);
            if(strcasecmp(modo, t) == 0){
                cargar_dados(dados, tam);
            } else{
                tirar_dados(dados, tam, 6);
            }
            mostrar_vector(dados, 5);
            cout << endl << endl << endl;
            if(lanzamiento == 1 && comprobar_apariciones(dados, tam, 5)){
                puntajes[bandera_jugador - 1] += 50;
                cout << "¡Generala servida, felicidades ganó el juego!\n\n";
                establecer_ranking(jugador_activo, cont_ronda_1, puntajes[bandera_jugador - 1], mejor_jugador, mejor_ronda, puntajes);
                system("pause");
                system("cls");
                imprimir_ganador(jugador_activo, cont_ronda_1, puntajes[bandera_jugador - 1]);
                system("pause");
                return 0;
            }
            puntos = puntuar_jugada(dados, dados_copia, aparicion_cara, tam, tam3);
            cout << "La jugada actual vale " << puntos << " puntos\n\n";
            system("pause");
            if(lanzamiento == 3){
                puntajes[bandera_jugador - 1] += puntos;
                break;
            }
            cout << "\nIngrese T para volver a tirar algunos o todos los dados, otro ingreso para terminar la ronda: ";
            cin >> ingreso;
            if(strcasecmp(ingreso, t) == 0){
                cout << "\nIngrese cuántos dados vuelve a tirar: ";
                cin >> dados_nuevo_tiro;
                for(int i = 0; i < dados_nuevo_tiro; i++){
                    cout << "\nIngrese la posición (1 a 5) del dado: ";
                    cin >> pos_dado;
                    if(dados[pos_dado - 1] == 0){
                        cout << "\n¡No puede repetir el dado!\n";
                        i--;
                    } else{
                        dados[pos_dado - 1] = 0;
                    }
                }
            } else{
                puntajes[bandera_jugador - 1] += puntos;
                break;
            }
        }
    }
    system("cls");
    if(puntajes[0] > puntajes[1]){
        establecer_ranking(jugador, cont_ronda_1, puntajes[0], mejor_jugador, mejor_ronda, puntajes);
        imprimir_ganador(jugador, cont_ronda_1, puntajes[0]);
    } else if(puntajes[1] > puntajes[0]){
        establecer_ranking(jugador_2, cont_ronda_2, puntajes[1], mejor_jugador, mejor_ronda, puntajes);
        imprimir_ganador(jugador_2, cont_ronda_2, puntajes[1]);
    } else {
        strcpy(aux, jugador);
        strcat(aux, " y ");
        strcat(aux, jugador_2);
        establecer_ranking(aux, cont_ronda_1, puntajes[0], mejor_jugador, mejor_ronda, puntajes);
        imprimir_empate(jugador, jugador_2, cont_ronda_1, puntajes[0]);
    }
    system("pause");
    return 0;
}
