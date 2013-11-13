#ifndef STablero_h
#define STablero_h

#include <vector>

#include "SCarta.h"
#include "SCasilla.h"
#include "SFicha.h"

class STablero {

protected:
    std::vector< SCasilla* > m_casillas;

public:

	explicit STablero(int tamano)
	{
		m_casillas.resize(tamano, new SCasilla())
	}


	SFicha* getFicha(int position)
	{
		return m_casillas[position].getFicha();
	}

	std::vector< SFicha* > v getFichas(int position)
	{
		return m_casillas[position].getFichas();
	}

	SCarta* getCarta(int position)
	{
		return m_casillas[position].getCarta();
	}

	std::vector< SCarta* > getCartas()
	{
		return m_casillas[position].getCartas();
	}

	void agregarFicha(SFicha* ficha, int position)
	{
		m_casillas[position].addFicha(ficha);
	}

	void agregarCarta(SCarta* carta, int position)
	{
		m_casillas[position].addCarta(carta);
	}

	void removerFicha();

	void removerCarta();

};

#endif // STablero_h
