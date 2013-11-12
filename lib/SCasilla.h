#ifndef SCasilla_h
#define SCasilla_h

#include <vector>
#include "SPila_Cartas.h"
#include "SFicha.h"

//! La clase casilla son las divisiones que tiene el tablero y lugares donde podran estar las fichas o cartas
	/*!
	   la clase define funciones para saber que hay en la casilla y sus constructoras, debido a que el contenido de esta puede variar
	 */

class SCasilla {

protected:
	//! pila de cartas
	SPila_Cartas* m_pila_cartas;
	//! fichas que puedan estar en la casilla
	std::vector< SFicha* > m_fichas;
	//! cartas que puedan estar en la casilla
	std::vector< SCarta* > m_cartas;
	//! reglas de una casilla
	/*!
	   \sa SRegla.h
	 */
	SRegla* m_regla;

public:
	//! Constructor
	/*!
	   este constructor por defecto no coloca pila de cartas
	 */
	SCasilla()
		: m_pila_cartas(nullptr)
	{}

	//! Constructor
	/*!
	   este constructor, coloca una ficha en la casilla, sin pila de cartas
	 */

	SCasilla(SFicha* ficha)
		: m_pila_cartas(nullptr)
	{
		m_fichas.push_back(ficha);
	}

	//! Constructor
	/*!
	   le asigna a las fichas de la casilla fichas por referencia sin pila de cartass
	 */
	SCasilla(const std::vector< SFicha* >& fichas)
		: m_pila_cartas(nullptr), m_fichas(fichas)
	{}

	//! Constructor
	/*!
	   coloca una carta en la casilla y sin pila de cartas
	 */
	SCasilla(SCarta* carta)
		: m_pila_cartas(nullptr)
	{
		m_cartas.push_back(carta);
	}

	//! Constructor
	/*!
	   le asigna a la casilla cartas por referencia y sin pila de cartas
	 */

	SCasilla(const std::vector< SCarta* >& cartas)
		: m_pila_cartas(nullptr), m_cartas(cartas)
	{}

	//! Constructor
	/*!
	   crea una pila de cartas en la casilla
	 */

	SCasilla(SPila_Cartas* pila_cartas)
		: m_pila_cartas(pila_cartas)
	{}

	//! Devuelve una pila de cartas que tenga la casilla

	SPila_Cartas* getPila()
	{
		return m_pila_cartas;
	}

	//! Devuelve la ficha que tenga en la casilla, la primera que llego
	/*!
	   \sa  getFicha(), getFichas(), getCarta(), getCartas()
	 */

	SFicha* getFicha()
	{
		if (m_fichas.empty())
			return nullptr;
		return m_fichas[0];
	}

	//! Devuelve todas las fichas que hay en la casilla
	/*!
	   \sa getFichas(), getCarta(), getCartas(), getPila()
	 */

	std::vector< SFicha* > getFichas()
	{
		return m_fichas;
	}

	//! Devuelve la primera carta que este en la casilla
	/*!
	   \sa getFicha(), getFichas(), getCartas(), getPila()
	 */	

	SCarta* getCarta()
	{
		if (m_cartas.empty())
			return nullptr;
		return m_cartas[0];
	}

	//! Devuelve todas las cartas que hay en la casilla
	/*!
	   \sa getFicha(), getFichas(), getCarta(), getPila()
	 */

	std::vector< SCarta* > getCartas()
	{
		return m_cartas;
	}

	~SCasilla(){}

};

#endif // SCasilla_h
