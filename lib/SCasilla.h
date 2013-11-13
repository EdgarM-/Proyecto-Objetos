#ifndef SCasilla_h
#define SCasilla_h

#include <vector>
#include "SPila_Cartas.h"
#include "SFicha.h"

class SCasilla {

protected:
	SPila_Cartas* m_pila_cartas;
	std::vector< SFicha* > m_fichas;
	std::vector< SCarta* > m_cartas;
	SRegla* m_regla;

public:
	SCasilla()
		: m_pila_cartas(nullptr)
	{}

	SCasilla(SFicha* ficha)
		: m_pila_cartas(nullptr)
	{
		m_fichas.push_back(ficha);
	}

	SCasilla(const std::vector< SFicha* >& fichas)
		: m_pila_cartas(nullptr), m_fichas(fichas)
	{}

	SCasilla(SCarta* carta)
		: m_pila_cartas(nullptr)
	{
		m_cartas.push_back(carta);
	}

	SCasilla(const std::vector< SCarta* >& cartas)
		: m_pila_cartas(nullptr), m_cartas(cartas)
	{}

	SCasilla(SPila_Cartas* pila_cartas)
		: m_pila_cartas(pila_cartas)
	{}

	SPila_Cartas* getPila()
	{
		return m_pila_cartas;
	}

	SFicha* getFicha()
	{
		if (m_fichas.empty())
			return nullptr;
		return m_fichas[0];
	}

	std::vector< SFicha* > getFichas()
	{
		return m_fichas;
	}

	SCarta* getCarta()
	{
		if (m_cartas.empty())
			return nullptr;
		return m_cartas[0];
	}

	std::vector< SCarta* > getFichas()
	{
		return m_cartas;
	}

};

#endif // SCasilla_h
