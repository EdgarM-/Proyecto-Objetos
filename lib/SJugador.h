#ifndef SJugador_h
#define SJugador_h

#include <vector>
#include <string>

#include "SFicha.h"

//! Clase jugador 
	/*!
	   m_jugador y  m_casilla empiezan en nullpointer.
	 */

class SJugador {

protected:
	std::string m_nombre;
	std::vector< SFicha* > m_fichas;
	int m_equipo;
	
public:
	SJugador(std::string nombre, int equipo = 0)
	: m_nombre(nombre), m_equipo(equipo)
	{}

	void addFicha(SFicha* ficha)
	{
		ficha.setJugador(this);
		m_fichas.push_back(ficha);
	}

	void setEquipo(int equipo)
	{
		m_equipo = equipo;
	}

	int getEquipo() const
	{
		return m_equipo;
	}

	bool mismoEquipo(SJugador* jugador) const
	{
		return (m_equipo == jugador.getEquipo())
	}

	void retirar(){};

	~SJugador(){}
};

#endif // SJugador_h
