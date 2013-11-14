#ifndef SCasilla_h
#define SCasilla_h

#include <vector>

#include "SPila_Cartas.h"
#include "STablero.h"
#include "SFicha.h"
#include "SRegla.h"

//! La clase SCasilla es la que modela lo basico de una casilla y posee las cartas y las fichas
/*!
   la clase define funciones para asignar o obtener los atributos de casilla como las cartas o fichas, cuenta con varios constructores para hacer mas facil su construccion
 */

class SCasilla {

protected:
	//! Tablero de juego
	/*!
	 \sa STablero
	 */
	 STablero* m_tablero;
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
	   \param regla Regla que aplica en la casilla
	 */
	SCasilla(STablero* tablero = nullptr, SRegla* regla = nullptr)
		: m_pila_cartas(nullptr), m_tablero(tablero), m_regla(regla)
	{}

	//! Constructor
	/*!
	  Crea una casilla y coloca una ficha en la casilla, sin pila de cartas
	  \param ficha Ficha que se va a asignar a la casilla
	  \param regla Regla que aplica en la casilla
	 */

	SCasilla(SFicha* ficha, STablero* tablero = nullptr, SRegla* regla = nullptr)
		: m_pila_cartas(nullptr), m_tablero(tablero), m_regla(regla)
	{
		m_fichas.push_back(ficha);
	}

	//! Constructor
	/*!
	   Crea una casilla y asigna a las fichas de la casilla fichas por referencia sin pila de cartas
	   \param fichas Vector de SFicha* pasado por referencia, contiene las fichas que se van a poner a la casilla
	   \param regla Regla que aplica en la casilla
	 */
	SCasilla(const std::vector< SFicha* >& fichas, STablero* tablero = nullptr, SRegla* regla = nullptr)
		: m_pila_cartas(nullptr), m_fichas(fichas), m_tablero(tablero), m_regla(regla)
	{}

	//! Constructor
	/*!
	   Crea una casilla y coloca una carta en la casilla y sin pila de cartas
	   \param carta Carta que se va a agregar a la casilla
	   \param regla Regla que aplica en la casilla
	 */
	SCasilla(SCarta* carta, STablero* tablero = nullptr, SRegla* regla = nullptr)
		: m_pila_cartas(nullptr), m_tablero(tablero), m_regla(regla)
	{
		m_cartas.push_back(carta);
	}

	//! Constructor
	/*!
	   Crea una casilla y asigna a la casilla cartas por referencia y sin pila de cartas
	   \param fichas Vector de SCarta*  pasado por referencia, contiene las cartas que se van a poner a la casilla
	   \param regla Regla que aplica en la casilla
	 */

	SCasilla(const std::vector< SCarta* >& cartas, STablero* tablero = nullptr, SRegla* regla = nullptr)
		: m_pila_cartas(nullptr), m_cartas(cartas), m_tablero(tablero), m_regla(regla)
	{}

	//! Constructor
	/*!
	   Crea una Casilla y le asigna una pila de cartas
	   \param pila_cartas Es la pila de cartas que se le asignara a la casilla
	   \param regla Regla que aplica en la casilla
	 */

	SCasilla(SPila_Cartas* pila_cartas, STablero* tablero = nullptr, SRegla* regla = nullptr)
		: m_pila_cartas(pila_cartas), m_tablero(tablero), m_regla(regla)
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
	  \param ficha Ficha que se va a addicionar
	   \sa   SFicha, getFichas(), rmFicha() */
	void addFicha(SFicha* ficha)
	{
		ficha->setCasilla(this);
		m_fichas.push_back(ficha);
		if (m_regla != nullptr)
			m_regla->fichaEntra(ficha);
	}
	//! Quita una ficha de la casilla
	/*!
	  \param ficha Ficha que se va quitar de la casilla 
	  \return bool false si la SRegla asociada a la casilla altera el movimiento normal de la ficha en el tablero,
	  true si se ejecuta normalmente.
	  \sa   SFicha, getFichas(), addFicha() 	   
	*/
	bool rmFicha(SFicha* ficha)
	{
		bool result = true;
		for (int i = 0; i < m_fichas.size(); ++i)
		{
			if (m_fichas[i] == ficha)
			{
				if  (m_regla != nullptr)
					result = !(m_regla->fichaSale(ficha));
				if (result)
				{
					m_fichas[i]->setPosicion(-1);
					m_fichas[i]->setCasilla(nullptr);
					m_fichas.erase(i);
				}
				break;
			}
		}
		return result;
	}

	void rmCartas()
	{
		for (int i = 0; i < m_cartas.size(); ++i)
			delete m_cartas[i];
		m_cartas.clear();
	}

	//! Indica las reglas a ejecutar en la casilla
	/*!
	  SRegla implementa las acciones a toma cuando una ficha es agregada a
	  la casilla o deja la casilla, solo puede haber maximo una regla por casilla.
	  \param regla SRegla que se va a addicionar
	   \sa   SRegla */
	void setRegla(SRegla* regla)
	{
		m_regla = regla;
	}

	//! Destructor
	/*!
	  Vacia @ref m_fichas y @ref m_cartas, libera la memoria alocada por cada carta en @ref m_cartas
	  y la memoria alocada para @ref m_regla
	 */
	virtual ~SCasilla()
	{
	  for (int i = 0; i < m_cartas.size(); ++i)
	    delete m_cartas[i];
	  delete m_regla;
	  m_fichas.clear();
	  m_cartas.clear();
	}

};

#endif // SCasilla_h
