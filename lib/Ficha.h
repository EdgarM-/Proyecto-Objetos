#ifndef Ficha_h
#define Ficha_h

#include "Pareja.h"
#include "Jugador.h"

class Ficha {

protected:
	Jugador* m_jugador;
	int m_fila;
	int m_columna;

public:
	Ficha()
		: m_jugador(nullptr)
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

	void setPareja();
};

#endif // Ficha_h
