#ifndef SFicha_h
#define SFicha_h

#include "SPareja.h"
#include "SJugador.h"
#include "SCasilla.h"

//! La clase Ficha es la base para las fichas
/*!
  La clase define las funciones las funciones para modelar lo basico de una ficha como asignar a un jugador o conseguir o asignar la casilla donde esta la ficha
*/

class SFicha {

protected:
	SJugador* m_jugador;
	SCasilla* m_casilla;
	int m_fila;
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
	int getFila();

	//!Devuelve la columna en la que esta la ficha
	/*!
	  \sa getPareja(), getFila()
	 */

	int getColumna();

	//!Devuelve la Pareja en la que esta la ficha
	/*!
	  \sa getFila() , getColumna(), SPareja
	*/

	SPareja getPareja();

	//!Asigna 

	void setFila(int fila);

	void setColumna(int columna);

	void setJugador(SJugador* jugador)
	{
		m_jugador = jugador;
	}

	SJugador* getJugador()
	{
		return m_jugador;
	}

	void setCasilla(SCasilla* casilla)
	{
		m_casilla = casilla;
	}

	SCasilla* getCasilla()
	{
		return m_casilla;
	}

	void setPareja();
};

#endif // SFicha_h
