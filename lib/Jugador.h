#ifndef Jugador_h
#define Jugador_h

#include <vector>
#include <string>

#include "Ficha.h"


class Jugador {

 protected:
    std::string m_nombre;
    vector< Ficha* > m_fichas;
    int m_equipo;
 
 public:
 	Jugador(std::string nombre, int equipo = 0)
 		: m_nombre(nombre), m_equipo(equipo)
 	{}

 	void addFicha(Ficha* ficha)
 	{
 		ficha.setJugador(this);
 		m_fichas.push_back(ficha);
 	}

    void retirar() = 0;
};

#endif // Jugador_h
