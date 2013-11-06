#ifndef Casilla_h
#define Casilla_h

#include <vector>
#include "Pila_Cartas.h"
#include "Ficha.h"

class Casilla {

protected:
	Pila_Cartas* m_pila_cartas;
	std::vector< Ficha* > m_fichas;
	std::vector< Carta* > m_cartas;
public:
	Casilla()
		: m_pila_cartas(nullptr)
	{}

	Casilla(Ficha* ficha)
		: m_pila_cartas(nullptr)
	{
		m_fichas.push_back(ficha);
	}

	Casilla(const std::vector<Ficha*>& fichas)
		: m_pila_cartas(nullptr), m_fichas(fichas)
	{}

	Casilla(Carta* carta)
		: m_pila_cartas(nullptr)
	{
		m_cartas.push_back(carta);
	}

	Casilla(const std::vector<Carta*>& cartas)
		: m_pila_cartas(nullptr), m_cartas(cartas)
	{}

	Casilla(Pila_Cartas* pila_cartas)
		: m_pila_cartas(pila_cartas)
	{}

	Pila_Cartas* getPila()
	{
		return m_pila_cartas;
	}

	Ficha* getFicha()
	{
		if (m_fichas.empty())
			return nullptr;
		return m_fichas[0];
	}

	std::vector<Fichas*> getFichas()
	{
		return m_fichas;
	}

};

#endif // Casilla_h
