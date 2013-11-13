#ifndef SCasilla_h
#define SCasilla_h

#include <vector>
#include "SPila_Cartas.h"
#include "SFicha.h"
#include "SRegla.h"

//! La clase SCasilla es la que modela lo basico de una casilla y posee las cartas y las fichas
/*!
   la clase define funciones para asignar o obtener los atributos de casilla como las cartas o fichas, cuenta con varios constructores para hacer mas facil su construccion
 */

class SCasilla {

protected:
	//! Pila de cartas
        /*!
	 \sa SPila_Cartas
	 */
	SPila_Cartas* m_pila_cartas;
	//! Fichas que se encuentran en la casilla
	/*!
	 \sa SFicha
	 */
	std::vector< SFicha* > m_fichas;
	//! Cartas asignadas a la casilla
	/*!
	 \sa SCarta
	 */
	std::vector< SCarta* > m_cartas;
	//! Reglas asociadas a la entrada y salida  de Fichas en la casilla.
	/*!
	   \sa SRegla
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
	  Crea una casilla y coloca una ficha en la casilla, sin pila de cartas
	 */

	SCasilla(SFicha* ficha, SRegla* regla = nullptr)
		: m_pila_cartas(nullptr), m_regla(regla)
	{
		m_fichas.push_back(ficha);
	}

	//! Constructor
	/*!
	   Crea una casilla y asigna a las fichas de la casilla fichas por referencia sin pila de cartass
	 */
	SCasilla(const std::vector< SFicha* >& fichas, SRegla* regla = nullptr)
		: m_pila_cartas(nullptr), m_fichas(fichas), m_regla(regla)
	{}

	//! Constructor
	/*!
	   Crea una casilla y coloca una carta en la casilla y sin pila de cartas
	 */
	SCasilla(SCarta* carta, SRegla* regla = nullptr)
		: m_pila_cartas(nullptr), m_regla(regla)
	{
		m_cartas.push_back(carta);
	}

	//! Constructor
	/*!
	   Crea una casilla y asigna a la casilla cartas por referencia y sin pila de cartas
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

	//! Devuelve la pila de cartas que tenga la casilla
	/*! \sa SPila_Cartas, getCarta(), getCartas()*/

	SPila_Cartas* getPila()
	{
		return m_pila_cartas;
	}

	//! Devuelve la ficha que tenga en la casilla, la primera que entro
	/*!
	   \sa   SFicha, getFichas(), addFicha(), rmFicha() */

	SFicha* getFicha()
	{
		if (m_fichas.empty())
			return nullptr;
		return m_fichas[0];
	}

	//! Devuelve todas las fichas que hay en la casilla
	/*!
	   \sa getFicha(), SFicha
	 */

	std::vector< SFicha* > getFichas()
	{
		return m_fichas;
	}

	//! Devuelve la primera carta que este en la casilla
	/*!
	   \sa getCartas(), getPila(), SCarta
	 */	

	SCarta* getCarta()
	{
		if (m_cartas.empty())
			return nullptr;
		return m_cartas[0];
	}

	//! Devuelve todas las cartas que hay en la casilla
	/*!
	   \sa getCarta(), getPila(), SCarta
	 */

	std::vector< SCarta* > getCartas()
	{
		return m_cartas;
	}

        //! Agrega una ficha a la casilla
	/*!
	   \sa   SFicha, getFichas(), rmFicha() */
	void addFicha(SFicha* ficha)
	{
		m_fichas.push_back(ficha);
	}
	//! Quita una ficha a la casilla
	/*!
	   \sa   SFicha, getFichas(), addFicha() */
	void rmFicha()
	{
	}
	//! Destructor
	/*!
	  Vacia @ref m_fichas y @ref m_cartas
	 */
	virtual ~SCasilla()
	{
		m_fichas.clear();
		m_cartas.clear();
	}

};

#endif // SCasilla_h
