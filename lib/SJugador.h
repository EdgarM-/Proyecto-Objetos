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
	//! entero que representa a que equipo pertenece el jugador, 0 es igual a que no pertenece a algun equipo
	int m_equipo;
	//! entero que representa la cantidad de puntaje que el jugador posee, por defecto empieza en 0
	int m_puntaje;
	
public:
	//! Constructor
	/*!
	   @ref m_nombre empezara con el nombre que entre al metodo y @ref m_equipo empieza con el entero que ingrese al metodo, de lo contrario el equipo sera 0
	   \param nombre Nombre del jugador
	   \param equipo Entero que indica en que grupo esta
	 */
	SJugador(std::string nombre, int equipo = 0)
	: m_nombre(nombre), m_equipo(equipo), m_puntaje(0);
	{}

	//! Constructor
	/*!
	   Construye un SJugador con un nombre especificado y con un numero @ref n_fichas de fichas tipo SFicha asignadas, de no ser especificado el equipo sera por default 0 
	   \param nombre Nombre del jugador
	   \param n_fichas cantidad de fichas que se le asignaran al jugador
	   \param equipo Entero que indica en que grupo esta
	   	   
	 */
	SJugador(std::string nombre, int n_fichas, int equipo = 0)
	: m_nombre(nombre), m_equipo(equipo), m_puntaje(0);
	{
		for (int i = 0; i < n_fichas; ++i)
			addFicha(new SFicha());
	}

	//! Agregar una ficha, le entra un puntero a una ficha y la guarda en el jugador
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
		return (m_equipo == jugador.getEquipo());
	}

	/**
	 * @brief Retorna el puntaje actual del jugador
	 * @return entero con el valor de m_puntaje, equivalente al puntaje del jugador
	 */
	int getPuntaje() const
	{
		return m_puntaje;
	}

	/**
	 * @brief Cambia el valor del puntaje del jugador por uno nuevo
	 * @details Reemplaza cualquier valor guardado en m_puntaje con el valor de puntaje
	 * 
	 * @param puntaje entero que representa el nuevo puntaje
	 */
	void setPuntaje(int puntaje)
	{
		m_puntaje = puntaje;
	}

	/**
	 * @brief Agrega puntos al valor del puntaje del jugador
	 * @details Agrega al valor de m_puntaje la cantidad en puntos
	 * 
	 * @param puntos entero con la cantidad de puntos a adicionar
	 */
	void addPuntaje(int puntos)
	{
		m_puntaje += puntos;
	}

	/**
	 * @brief Resta puntos al valor del puntaje del jugador
	 * @details Resta al valor de m_puntaje la cantidad en puntos
	 * 
	 * @param puntos entero con la cantidad de puntos a restar
	 */
	void rmPuntaje(int puntos)
	{
		m_puntaje -= puntos;
	}

	//! Retira un jugador del juego
	/*!
	   En caso de que el jugador no se necesite mas en el juego, a diferencia del destructor
	   en este caso todas las fichas del jugador son eliminadas del tablero, las cartas
	   regresan a la SPila_Cartas de donde fueron extraidas, pero no se libera la memoria
	   allocada a las SFichas*.
	 */

	virtual void retirar()
	{
		for (int i = 0; i < m_fichas.size(); ++i)
		{
			if (m_fichas[i]->enTablero())
				m_fichas[i]->getCasilla()->rmFicha(m_fichas[i]);
		}
	}
	//! Destructor
	/*!
	  Elimina todas la fichas que tenga el jugador
	 */
	virtual ~SJugador()
	{
		for (auto& ficha : m_fichas)
			delete ficha;
		m_fichas.clear();
	}
};

#endif // SJugador_h
