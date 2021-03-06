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

#ifndef SJuego_h
#define SJuego_h

#include <vector>

#include "SDado.h"
#include "SJugador.h"
#include "SPila_Cartas.h"
#include "STablero.h"

enum SEstado {EN_CURSO, GANADO, EMPATE};

//! La clase SJuego tiene unas funciones para modelar lo que seria un juego
/*!
  Esta Clase es un clase semi abstracta porque toca implementar varias funciones, para que este pueda usarla y se pueda jugar
*/
class SJuego {
  //! Indica que jugador esta en su turno
protected:
	int m_jugador_actual;
	//! Es el tablero de juego
	STablero* m_tablero;
	//!Vector de SJugador que contiene todos los jugadores
	std::vector< SJugador* > m_jugadores;
	//!Vector de SDado que contiene todos los dados que posee el juego
	std::vector< SDado > m_dados;
	//!Vector de SPila_Cartas que contiene las pilas de cartas del juego
	std::vector< SPila_Cartas* > m_pilas;
	//!SEstado indica el estado actual del juego
	SEstado m_estado;

public:
	//!Constructor
	/*!
	  Inicia sin tablero, con el @ref m_jugador_actual en 0 y con @ref m_estado en EN_CURSO
	 */
	SJuego()
	: m_jugador_actual(0), m_tablero(nullptr), m_estado(EN_CURSO)
	{}
	//!Agrega un jugador al juego
	/*!
	  \param jugador Jugador que entra al juego
	 */
	void agregarJugador(SJugador* jugador)
	{
		m_jugadores.push_back(jugador);
	}
	//!Agrega una pila de cartas al juego
	/*!
	  \param pila Pila de cartas que entra al juego
	 */
	void agregarPila(SPila_Cartas* pila)
	{
		m_pilas.push_back(pila);
	}
	//!Cambia al siguiente jugador
	/*!
	  Cambia al siguiente jugador en m_jugadores aumentando m_jugador_actual, si llega al ultimo comienza desde 0;
	*/
	void cambiarJugador()
	{
		++m_jugador_actual;
		if (m_jugador_actual == m_jugadores.size()) m_jugador_actual = 0;
	}
	//!Cambia es estado del juego
	/*!
	  \param estado SEstado en el que se encuentra el juego
	 */
	void cambiarEstado(SEstado estado)
	{
		m_estado = estado;
	}
	//!Retorna el estado actual del juego
	/*!
	  \return m_estado SEstado en el que se encuentra el juego
	 */
	SEstado getEstado() const
	{
		return m_estado;
	}
	//!Inicializadora del juego
	/*!
	  Este metodo es el encargado de inicializar todo el juego, se debe implementar cuando se herede
	 */
	virtual void init()  = 0;
	//! Definir Turno
	/*!
	  Este metodo es el encargado de manejar lo que es un turno y lo que pasa en el, se debe implementar cuando se herede
	 */
	virtual void turno()  = 0;
	//! Definir Ganar
	/*!
	  Este metodo es el encargado de saber cuando se gana el juego, se debe implementar cuando se herede
	 */
	virtual bool ganar()  = 0;
	//! Definir Turno
	/*!
	  Este metodo es el encargado de saber cuando se empata el juego, se debe implementar cuando se herede
	 */
	virtual bool empate()  = 0;

	//! Destructor
	/*!
		Libera toda la memoria alocada posible para el desarrollo del juego.
	*/
	virtual ~SJuego()
	{
		for(int i = 0; i < m_jugadores.size(); ++i)
		{
			delete m_jugadores[i];
		}
		for(int i = 0; i < m_pilas.size(); ++i)
		{
			delete m_pilas[i];
		}
		delete m_tablero;
		m_jugadores.clear();
		m_pilas.clear();
	}

};

#endif // SJuego_h
