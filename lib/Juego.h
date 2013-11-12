#ifndef Juego_h
#define Juego_h

#include <vector>

#include "Dado.h"
#include "Jugador.h"
#include "Pila_Cartas.h"
#include "Tablero.h"

using namespace std;

class Juego {

protected:
    int m_jugador_actual;
    Tablero* m_tablero;
    vector< Jugador* > m_jugadores;
    vector< Dado > m_dados;
    vector< Pila_Cartas > m_pilas;

 public:

    Juego()
        : m_jugador_actual(0), m_tablero(nullptr) 
    {}

    void agregarJugador(Jugador* jugador)
    {
        m_jugadores.push_back(jugador);
    }

    void agregarPila(Pila_Cartas* pila)
    {
        m_pilas.push_back(pila);
    }

    void init()  = 0;

    void turno()  = 0;

    bool ganar()  = 0;

    bool empate()  = 0;

};

#endif // Juego_h
