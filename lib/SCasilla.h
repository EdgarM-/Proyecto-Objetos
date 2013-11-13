#ifndef SCasilla_h
#define SCasilla_h

#include <vector>
#include "SPila_Cartas.h"
#include "SFicha.h"

//! La clase SCasilla es la que modela lo basico de una casilla y posee las cartas y las fichas
/*!
   la clase define funciones para asignar o obtener los atributos de casilla como las cartas o fichas, cuenta con varios constructores para hacer mas facil su construccion
 */

class SCasilla {

protected:
	//! Pila de cartas que puede poseer la casilla
        /*!
	  \sa SPila_Cartas, SCarta
	*/
	SPila_Cartas* m_pila_cartas;
	//! Fichas que posee la casilla
	/*!
	  \sa SFicha  
	*/
	std::vector< SFicha* > m_fichas;
	//! Cartas que puede poseer la casilla
	/*! 
	  \sa SCarta 
	*/
	std::vector< SCarta* > m_cartas;
	//! Reglas que posee la casilla
	/*!
	   \sa SRegla
	 */
	SRegla* m_regla;

public:
	//! Constructor
	/*!
	   Este es el constructor por defecto, solo le asigna a  @ref m_pila_cartas un nullpointer
	 */
	SCasilla()
		: m_pila_cartas(nullptr)
	{}

	//! Constructor
	/*!
	   Este constructor, le agrega una ficha a @ref m_fichas y le asigna a @ref m_pila_cartas un nullpointer \param ficha Es la ficha que se agrega a la casilla
	 */

	SCasilla(SFicha* ficha)
		: m_pila_cartas(nullptr)
	{
		m_fichas.push_back(ficha);
	}

	//! Constructor
	/*!
	   Este constructor le asigna a @ref m_fichas las fichas por referencia y le asigna a @ref m_pila_cartas un nullpointer \param fichas Es la referencia al vector de fichas que se asignara a @ref m_fichas
	 */
	SCasilla(const std::vector< SFicha* >& fichas)
		: m_pila_cartas(nullptr), m_fichas(fichas)
	{}

	//! Constructor
	/*!
	  Este constructor le agrega una carta a @ref m_cartas y le asigna a @ref m_pila_cartas un nullpointer \param carta Es la carta que se agregara a la casilla
	 */
	SCasilla(SCarta* carta)
		: m_pila_cartas(nullptr)
	{
		m_cartas.push_back(carta);
	}

	//! Constructor
	/*!
	  Este constructor le asigna a @ref m_cartas las cartas por referencia y le asigna a @ref m_pila_cartas un nullpointer \param cartas Es la referencia al vector de cartas que se asignara a @ref m_cartas
	 */

	SCasilla(const std::vector< SCarta* >& cartas)
		: m_pila_cartas(nullptr), m_cartas(cartas)
	{}

	//! Constructor
	/*!
	   Este constructor le asigna a @ref m_pila_cartas la pila de cartas \param pila_cartas Es la pila de cartas se asignara a la casilla
	 */

	SCasilla(SPila_Cartas* pila_cartas)
		: m_pila_cartas(pila_cartas)
	{}

	//! Devuelve la pila de cartas que tenga la casilla
	/*! \sa SPila_Cartas, getCarta(), getCartas()*/

	SPila_Cartas* getPila()
	{
		return m_pila_cartas;
	}

	//! Devuelve la ficha que tenga en la casilla, la primera que entro
	/*!
	   \sa   SFicha, getFichas(), addFichas(), rmFichas() */

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
	   \sa   SFicha, getFichas(), rmFichas() */
	void addFicha(SFicha* ficha)
	{
		m_fichas.push_back(ficha);
	}
	//! Quita una ficha a la casilla
	/*!
	   \sa   SFicha, getFichas(), addFichas() */
	void addFicha(SFicha* ficha)
	{
		m_fichas.push_back(ficha);
	}
	//! Destructor
	~SCasilla(){}

};

#endif // SCasilla_h
