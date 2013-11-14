#ifndef SFicha_h
#define SFicha_h

#include "SJugador.h"
#include "SCasilla.h"

//! La clase SFicha es la base para las fichas
/*!
  La clase define las funciones las funciones para modelar lo basico de una ficha como asignar a un jugador, conseguir o asignar la casilla donde esta la ficha
*/

class SFicha {
//! Jugador que posee la ficha
/*! \sa SJugador*/
protected:
	SJugador* m_jugador;
	//! Casilla en la que esta la ficha
	/*! \sa SCasilla*/
	SCasilla* m_casilla;
	 //! Entero que indica la casilla en la que se encuentra la ficha respecto al tablero empezando en 0, -1 indica que no esta en el tablero.
	int m_posicion; 

public:
	//! Constructor
	/*!
	   @ref m_jugador y @ref m_casilla empiezan en nullpointer.
	   \param posicion Entero que indica en que posicion empieza la ficha por defecto es -1
	 */
	SFicha(int posicion = -1)
		: m_jugador(nullptr), m_casilla(nullptr), m_posicion(posicion)
	{}

	//!Devuelve la posicion en la que se encuentra la ficha respecto al tablero
	/*!
	  \sa setPosicion(), getCasilla()
	 */
	int getPosicion()
	{
	  return m_posicion;
	}

	//!Asigna a la ficha una posicion
	/*!
	  \param posicion es un entero que indica en que posicion esta
	  \sa getPosicion(), setCasilla()
	 */

	void setPosicion(int posicion)
	{
	  m_posicion = posicion;
	}
	
	//!Devuelve si la ficha se encuentra en alguna casilla
	/*!
	  \sa  getCasilla(), getPosicion()
	 */
	bool enTablero()
	{
	  return (m_posicion >= 0);
	}

	//!Asigna a la ficha un Jugador
	/*!
	  \param jugador es un puntero al jugador que posee la ficha
	  \sa  getJugador(), SJugador
	 */
	void setJugador(SJugador* jugador)
	{
		m_jugador = jugador;
	}
	
	//!Devuelve el jugador al que le pertenece la ficha
	/*!
	  \sa setJugador(), SJugador
	 */

	SJugador* getJugador()
	{
		return m_jugador;
	}
2	//!Asigna a la ficha una casilla
	/*!
	  \param casilla es una SCasilla la cual indica en que casilla esta la ficha
	  \sa getCasilla(),SCasilla
	 */
	void setCasilla(SCasilla* casilla)
	{
		m_casilla = casilla;
	}
	//!Devuelve la casilla en la cual esta la ficha
	/*!
	  \sa  setCasilla(), SCasilla
	 */
	SCasilla* getCasilla()
	{
		return m_casilla;
	}
};

#endif // SFicha_h
