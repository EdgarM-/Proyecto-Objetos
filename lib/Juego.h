#ifndef Juego_h
#define Juego_h

#include <vector>

#include "Dado.h"
#include "Jugador.h"
#include "Pila_Cartas.h"
#include "Tablero.h"

using namespace std;

class Juego {

 public:

    void getJugadores();

    void agregarJugador();

    void agregarPila();

    void init()  = 0;

    void turno()  = 0;

    Boolean ganar()  = 0;

    Boolean empate()  = 0;

 public:
    int m_jugador_actual;

 public:

    /**
     * @element-type Jugador
     */
    vector< Jugador > m_jugadores;

    /**
     * @element-type Pila_Cartas
     */
    vector< Pila_Cartas > m_pilas;

    Tablero m_tablero;

    /**
     * @element-type Dado
     */
    vector< Dado > m_dados;
};

#endif // Juego_h
