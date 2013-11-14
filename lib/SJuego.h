#ifndef SJuego_h
#define SJuego_h

#include <vector>

#include "SDado.h"
#include "SJugador.h"
#include "SPila_Cartas.h"
#include "STablero.h"

class SJuego {

protected:
	int m_jugador_actual;
	STablero* m_tablero;
	std::vector< SJugador* > m_jugadores;
	std::vector< SDado > m_dados;
	std::vector< SPila_Cartas* > m_pilas;

public:

	SJuego()
	: m_jugador_actual(0), m_tablero(nullptr) 
	{
		init();
	}

	void agregarJugador(SJugador* jugador)
	{
		m_jugadores.push_back(jugador);
	}

	void agregarPila(SPila_Cartas* pila)
	{
		m_pilas.push_back(pila);
	}

	virtual void init()  = 0;

	virtual void turno()  = 0;

	virtual bool ganar()  = 0;

	virtual bool empate()  = 0;

};

#endif // SJuego_h
