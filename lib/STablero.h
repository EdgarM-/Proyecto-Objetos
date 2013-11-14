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


	SFicha* getFicha(int posicion)
	{
		return m_casillas[posicion]->getFicha();
	}

	std::vector< SFicha* > getFichas(int posicion)
	{
		return m_casillas[posicion]->getFichas();
	}

	SCarta* getCarta(int posicion)
	{
		return m_casillas[posicion]->getCarta();
	}

	std::vector< SCarta* > getCartas()
	{
		return m_casillas[posicion]->getCartas();
	}

	void agregarFicha(SFicha* ficha, int posicion)
	{
		ficha->setPosicion(posicion);
		m_casillas[posicion]->addFicha(ficha);
	}

	void agregarCarta(SCarta* carta, int posicion)
	{
		m_casillas[posicion]->addCarta(carta);
	}

	void removerFicha(SFicha* ficha)
	{
		ficha->getCasilla()->rmFicha(ficha);
	}

	void removerCartas(int posicion)
	{
		m_casillas[posicion]->rmCartas();
	}

};

#endif // STablero_h
