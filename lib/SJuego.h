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
	  Inicia sin tablero y con el @ref m_jugador_actual en 0
	 */
	SJuego()
	: m_jugador_actual(0), m_tablero(nullptr) 
	{
		init();
	}
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
	//!Cambia es estado del juego
	/*!
	  \param estado SEstado en el que se encuentra el juego
	 */
	void cambiarEstado(SEstado estado)
	{
		m_estado(estado);
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

};

#endif // SJuego_h
