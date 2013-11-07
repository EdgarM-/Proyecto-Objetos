#ifndef Tablero_h
#define Tablero_h

#include <vector>

#include "Carta.h"
#include "Casilla.h"
#include "Ficha.h"

class Tablero {

protected:
    std::vector< Casilla* > m_casillas;

public:

	explicit Tablero(int tamano)
	{
		m_casillas.resize(tamano, new Casilla())
	}


	Ficha* getFicha(int position)
	{
		return m_casillas[position].getFicha();
	}

	std::vector< Ficha* > v; getFichas(int position)
	{
		return m_casillas[position].getFichas();
	}

	Carta* getCarta(int position)
	{
		return m_casillas[position].getCarta();
	}

	std::vector< Carta* > getCartas()
	{
		return m_casillas[position].getCartas();
	}

	void limpiar(); // TODO: Terminar, funcion importante, definir funcionamiento.

	void agregarFicha(Ficha* ficha, int position)
	{
		m_casillas[position].addFicha(ficha);
	}

	void agregarCarta(Carta* carta, int position)
	{
		m_casillas[position].addCarta(carta);
	}

	void removerFicha();

	void removerCarta();

};

#endif // Tablero_h
