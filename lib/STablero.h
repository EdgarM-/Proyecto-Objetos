#ifndef STablero_h
#define STablero_h

#include <vector>

#include "SCasilla.h"

enum tipoSTablero { CIRCULAR, LINEAL_REBOTE, LINEAL_NOREBOTE };

class STablero {

protected:

    std::vector< SCasilla* > m_casillas;
    tipoSTablero m_tipo;

public:

	explicit STablero(int tamano, tipoSTablero tipo = LINEAL_REBOTE)
	{
		m_casillas.resize(tamano, new SCasilla());
		m_tipo = tipo;
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

	void moverFicha(SFicha* ficha, int n_casillas)
	{
		int pos = ficha->getPosicion();
		if (ficha->enTablero())
			removerFicha(ficha);
		pos += n_casillas;
		if (pos >= m_casillas.size())
		{
			if (m_tipo == CIRCULAR)
				agregarFicha(ficha, pos - m_casillas.size());
			else if (m_tipo == LINEAL_REBOTE)
				agregarFicha(ficha, 2 * m_casillas.size() - 2 - pos ))
		}
		else
			agregarFicha(ficha, pos + n_casillas);
	}

	void removerCartas(int posicion)
	{
		m_casillas[posicion]->rmCartas();
	}

};

#endif // STablero_h
