/* Copyright (c) 2013 Santiago Quintero Pabón, Edgar Manuel Amézquita, Juan Camilo Arévalo
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef SFicha_h
#define SFicha_h

class SJugador;
class SCasilla;

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
	//!Asigna a la ficha una casilla
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
