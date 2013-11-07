#ifndef Ficha_h
#define Ficha_h

#include "Pareja.h"
#include "Jugador.h"
#include "Casilla.h"

class Ficha {

protected:
	Jugador* m_jugador;
	Casilla* m_casilla;
	int m_fila;
	int m_columna;

public:
	Ficha()
		: m_jugador(nullptr), m_casilla(nullptr)
	{}

	int getFila();

	int getColumna();

	Pareja getPareja();

	void setFila();

	void setColumna();

	void setJugador(Jugador* jugador)
	{
		m_jugador = jugador;
	}

	Jugador* getJugador()
	{
		return m_jugador;
	}

	void setCasilla(Casilla* casilla)
	{
		m_casilla = casilla;
	}

	Casilla* getCasilla()
	{
		return m_casilla;
	}

	void setPareja();
};

#endif // Ficha_h
