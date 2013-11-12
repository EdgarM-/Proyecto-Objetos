#ifndef SFicha_h
#define SFicha_h

#include "SPareja.h"
#include "SJugador.h"
#include "SCasilla.h"

//! La clase Ficha es la base para las fichas
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
	 //! Entero que indica la fila
	int m_fila;
	 //! Entero que indica la columna
	int m_columna;

public:
	//! Constructor
	/*!
	   m_jugador y  m_casilla empiezan en nullpointer.
	 */
	SFicha()
		: m_jugador(nullptr), m_casilla(nullptr)
	{}

	//!Devuelve la fila en la que esta la ficha
	/*!
	  \sa getPareja(), getColumna()
	 */
	int getFila()
	{
	  return m_fila;
	}
	//!Devuelve la columna en la que esta la ficha
	/*!
	  \sa getPareja(), getFila()
	 */

	int getColumna()
	{
	  return m_columna;
	}

	//!Devuelve la Pareja en la que esta la ficha
	/*!
	  \sa getFila() , getColumna(), SPareja
	*/

	SPareja getPareja()
	{
	  SPareja actual(m_columna,m_fila);
	  return actual;
	}

	//!Asigna a la ficha una fila
	/*!
	  \param fila es un entero que indica en que fila esta
	  \sa setColumna(), setCasilla(), setPareja()
	 */

	void setFila(int fila)
	{
	  m_fila = fila;
	}
	
	//!Asigna a la ficha una columna
	/*!
	  \param columna es un entero que indica en que fila esta la ficha
	  \sa setFila(), setCasilla(), setPareja()
	 */

	void setColumna(int columna)
	{
	  m_columna = columna;
	}
	
	//!Asigna a la ficha un Jugador
	/*!
	  \param jugador es un puntero al Jugador que posee la ficha
	  \sa  getJugador()
	 */

	void setJugador(SJugador* jugador)
	{
		m_jugador = jugador;
	}
	
	//!Devuelve el Jugador al que le pertenece la ficha
	/*!
	  \sa setJugador()
	 */

	SJugador* getJugador()
	{
		return m_jugador;
	}
	//!Asigna a la ficha una casilla
	/*!
	  \param casilla es una SCasilla la cual indica en que casilla esta la ficha
	  \sa getCasilla()
	 */
	void setCasilla(SCasilla* casilla)
	{
		m_casilla = casilla;
	}
	//!Devuelve la casilla en la cual esta la ficha
	/*!
	  \sa  setCasilla()
	 */
	SCasilla* getCasilla()
	{
		return m_casilla;
	}
	
	//!Asigna una pareja en la cual esta la ficha
	/*!
	  \param pareja es una SPareja que indica en que columna y fila esta la ficha
	  \sa  getPareja(), getColumna(), getFila()
	 */
	
	void setPareja(SPareja pareja )
	{
	  m_columna = pareja.x;
	  m_fila = pareja.y;
	}
};

#endif // SFicha_h
