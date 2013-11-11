#ifndef Ficha_h
#define Ficha_h

#include "Pareja.h"
#include "Jugador.h"
#include "Casilla.h"

//! La clase Ficha es la base para las fichas
/*!
  La clase define las funciones las funciones para modelar lo basico de una ficha como asignar a un jugador o conseguir o asignar la casilla donde esta la ficha
*/

class Ficha {

protected:
	Jugador* m_jugador;
	Casilla* m_casilla;
	int m_fila;
	int m_columna;

public:
	//! Constructor
	/*!
	   m_jugador y  m_casilla empiezan en nullpointer.
	 */
	Ficha()
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
	  \sa getFila() , getColumna(), Pareja
	*/

	Pareja getPareja();

	//!Asigna 

	void setFila(int fila);

	void setColumna(int columna);

	void setJugador(Jugador* jugador)
	{
		m_jugador = jugador;
	}

	Jugador* getJugador()
	{
		return m_jugador;
	}

	void setCasilla(Casilla* casilla)
	{
		m_casilla = casilla;
	}

	Casilla* getCasilla()
	{
		return m_casilla;
	}

	void setPareja();
};

#endif // Ficha_h
