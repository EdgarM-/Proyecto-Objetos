#ifndef SJugador_h
#define SJugador_h

#include <vector>
#include <string>

#include "SFicha.h"

//! La Clase jugador es la base para modelar los jugadores
	/*!
	   La clase define las funciones basicas para modelar un jugador, este tiene fichas, un nombre y pertenece a un equipo.
	   puede asignar un equipo, fichas, saber de que equipo es y retirar el jugador de ser nesesario.
	 */

class SJugador {

protected:
	//! nombre del jugador
	std::string m_nombre;
	//! fichas del jugador
	std::vector< SFicha* > m_fichas;
	//! entero que representa a que equipo pertenece el jugador
	int m_equipo;
	
public:
	//! Constructor
	/*!
	   m_nombre empezara con el nombre que entre al metodo y m_equipo empieza con el entero que ingrese al metodo, de lo contrario el equipo sera por default 0
	 */
	SJugador(std::string nombre, int equipo = 0)
	: m_nombre(nombre), m_equipo(equipo)
	{}

	//! Agregar una ficha, le entre un puntero a una ficha y la guarda en el jugador
	/*!
	   \sa SFicha.h
	 */
	void addFicha(SFicha* ficha)
	{
		ficha.setJugador(this);
		m_fichas.push_back(ficha);
	}

	//! Asigancion de quipo, canbia el entero que reprensenta el equipo del jugador por el nuevo que entre
	/*!
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

	//! Devuelve verdadero si jugador que entra a la funcion es de el mismo equipo que el jugador, falso de lo contrario
	/*!
	   \sa setEquipo(), getEquipo()
	 */
	bool mismoEquipo(SJugador* jugador) const
	{
		return (m_equipo == jugador.getEquipo())
	}

	//! Retira un jugador del juego
	/*!
	   es caso de que el jugador no se nesesite mas en el juego
	 */
	void retirar(){};

	~SJugador(){}
};

#endif // SJugador_h
