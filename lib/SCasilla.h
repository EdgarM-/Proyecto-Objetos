#ifndef SCasilla_h
#define SCasilla_h

#include <vector>
#include "SPila_Cartas.h"
#include "SFicha.h"
#include "SRegla.h"

//! La clase SCasilla son las divisiones que tiene el tablero y lugares donde podran estar las fichas o cartas
	/*!
	   la clase define funciones para saber que hay en la casilla y sus constructoras, debido a que el contenido de esta puede variar
	 */

class SCasilla {

protected:
	//! Pila de cartas
	SPila_Cartas* m_pila_cartas;
	//! Fichas que se encuentran en la casilla
	std::vector< SFicha* > m_fichas;
	//! Cartas asignadas a la casilla
	std::vector< SCarta* > m_cartas;
	//! Reglas asociadas a la entrada y salida  de Fichas en la casilla.
	/*!
	   \sa SRegla.h
	 */
	SRegla* m_regla;

public:
	//! Constructor
	/*!
	   Constructor por defecto, no coloca pila de cartas
	 */
	SCasilla(SRegla* regla = nullptr)
		: m_pila_cartas(nullptr), m_regla(regla)
	{}

	//! Constructor
	/*!
	   Constructor, coloca una ficha en la casilla, sin pila de cartas
	 */

	SCasilla(SFicha* ficha, SRegla* regla = nullptr)
		: m_pila_cartas(nullptr), m_regla(regla)
	{
		m_fichas.push_back(ficha);
	}

	//! Constructor
	/*!
	   Asigna a las fichas de la casilla fichas por referencia sin pila de cartass
	 */
	SCasilla(const std::vector< SFicha* >& fichas, SRegla* regla = nullptr)
		: m_pila_cartas(nullptr), m_fichas(fichas), m_regla(regla)
	{}

	//! Constructor
	/*!
	   Coloca una carta en la casilla y sin pila de cartas
	 */
	SCasilla(SCarta* carta, SRegla* regla = nullptr)
		: m_pila_cartas(nullptr), m_regla(regla)
	{
		m_cartas.push_back(carta);
	}

	//! Constructor
	/*!
	   Asigna a la casilla cartas por referencia y sin pila de cartas
	 */

	SCasilla(const std::vector< SCarta* >& cartas, SRegla* regla = nullptr)
		: m_pila_cartas(nullptr), m_cartas(cartas), m_regla(regla)
	{}

	//! Constructor
	/*!
	   Crea una Casilla y le asigna una pila de cartas
	 */

	SCasilla(SPila_Cartas* pila_cartas, SRegla* regla = nullptr)
		: m_pila_cartas(pila_cartas), m_regla(regla)
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

	virtual ~SCasilla()
	{
		m_fichas.clear();
		m_cartas.clear();
	}

};

#endif // SCasilla_h
