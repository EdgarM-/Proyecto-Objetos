#ifndef SJugador_h
#define SJugador_h

#include <vector>
#include <string>

#include "SFicha.h"

//! La Clase SJugador es la base para modelar los jugadores
	/*!
	   La clase define las funciones basicas para modelar un jugador, este tiene fichas, un nombre y pertenece a un equipo.
	   Se puede asignar un equipo, fichas, saber a que equipo pertenece y retirar el jugador de ser necesario.
	 */

class SJugador {

protected:
	//! Nombre del jugador
	std::string m_nombre;
	//! Fichas del jugador
	std::vector< SFicha* > m_fichas;
	//! Entero que representa a que equipo pertenece el jugador
	int m_equipo;
	
public:
	//! Constructor
	/*!
	   @ref m_nombre empezara con el nombre que entre al metodo y @ref m_equipo empieza con el entero que ingrese al metodo, de lo contrario el equipo sera 0
	 */
	SJugador(std::string nombre, int equipo = 0)
	: m_nombre(nombre), m_equipo(equipo)
	{}

	//! Agregar una ficha
	/*!
	  \param ficha es un puntero a la ficha que se agregara
	   \sa SFicha.h
	 */
	void addFicha(SFicha* ficha)
	{
		ficha.setJugador(this);
		m_fichas.push_back(ficha);
	}

	//! Asignacion de equipo.
	/*!
	  Cambia el entero que reprensenta el equipo del jugador por el nuevo que entre
	  \param equipo Entero que indica el nuevo equipo del jugador
	   \sa getEquipo(), mismoEquipo()
	 */
	void setEquipo(int equipo)
	{
		m_equipo = equipo;
	}

	//! Obtener el equipo al que pertenece el jugador
	/*!
	   \sa setEquipo(), mismoEquipo()
	 */
	int getEquipo() const
	{
		return m_equipo;
	}

	//! Comprueba si dos jugadores son del mismo equipo
	/*!
	  Devuelve verdadero si jugador que entra a la funcion es de el mismo equipo que el jugador, falso de lo contrario
	  \param jugador Jugador con el que se va a comparar
	   \sa setEquipo(), getEquipo(), SJugador()
	 */
	bool mismoEquipo(SJugador* jugador) const
	{
		return (m_equipo == jugador.getEquipo())
	}

	//! Retira un jugador del juego
	/*!
	   En caso de que el jugador no se necesite mas en el juego
	 */
	void retirar()
	{};
	//! Destructor
	~SJugador(){}
};

#endif // SJugador_h
