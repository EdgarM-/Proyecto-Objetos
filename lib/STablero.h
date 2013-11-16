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

#ifndef STablero_h
#define STablero_h

#include <vector>

#include "SCasilla.h"

enum tipoSTablero { CIRCULAR, LINEAL_REBOTE, LINEAL_NOREBOTE };

//!La clase STablero modela lo que sera el tablero de juego
/*!
  Esta clase implementa funciones para conseguir o agregar cartas y fichas
  \sa SCarta, SFicha
 */
class STablero {

  //!Vector de casillas que respresnta al tablero
  /*!
    \sa SCasilla
   */
protected:

    std::vector< SCasilla* > m_casillas;
    tipoSTablero m_tipo;

    //!Constructor
    /*!
      Tiene que llamarse explicitamente para crear el tablero
      \param tamano Entero que indica el tamaño del tablero a crear
     */
public:

	explicit STablero(int tamano, tipoSTablero tipo = LINEAL_REBOTE)
	{
		m_casillas.resize(tamano);
		for (int i = 0; i < tamano; ++i)
			m_casillas[i] = new SCasilla(this);
		m_tipo = tipo;
	}
	
	//!Devuelve una de las fichas que hay en una posicion
	/*! 
	  \param posicion Entero que indica la posicion para saber que ficha se encuentra ahi
	 */
	SFicha* getFicha(int posicion)
	{
		return m_casillas[posicion]->getFicha();
	}
	//!Devuelve todas las fichas que hay en una posicion
	/*! 
	  \param posicion Entero que indica la posicion para saber que fichas se encuentran ahi
	 */
	std::vector< SFicha* > getFichas(int posicion)
	{
		return m_casillas[posicion]->getFichas();
	}
	//!Devuelve la carta que hay en una posicion
	/*! 
	  \param posicion Entero que indica la posicion para saber que carta se encuentra ahi
	 */
	SCarta* getCarta(int posicion)
	{
		return m_casillas[posicion]->getCarta();
	}
	//!Devuelve todas las cartas que hay en una posicion
	/*! 
	  \param posicion Entero que indica la posicion para saber que cartas se encuentran ahi
	 */
	std::vector< SCarta* > getCartas(int posicion)
	{
		return m_casillas[posicion]->getCartas();
	}
	
	//!Agrega una ficha en una posicion
	/*!
	  \param ficha Ficha que se va a agregar
	  \param posicion Entero que indica en donde se pondra la ficha
	 */
	void agregarFicha(SFicha* ficha, int posicion)
	{
		ficha->setPosicion(posicion);
		m_casillas[posicion]->addFicha(ficha);
	}
	//!Agrega una carta en una posicion
	/*!
	  \param carta Carta que se va a agregar
	  \param posicion Entero que indica en donde se pondra la carta
	 */
	void agregarCarta(SCarta* carta, int posicion)
	{
		m_casillas[posicion]->addCarta(carta);
	}
	//!Remueve una ficha
	/*!
	  \param ficha Ficha que se va a eliminar
	 */
	void removerFicha(SFicha* ficha)
	{
		ficha->getCasilla()->rmFicha(ficha);
	}

	void moverFicha(SFicha* ficha, int n_casillas)
	{
		int pos = ficha->getPosicion();
		if (ficha->enTablero())
			removerFicha(ficha);
		pos += n_casillas;
		if (pos >= m_casillas.size())
		{
			if (m_tipo == CIRCULAR)
				agregarFicha(ficha, pos - m_casillas.size());
			else if (m_tipo == LINEAL_REBOTE)
				agregarFicha(ficha, 2 * m_casillas.size() - 2 - pos );	
		}
		else
			agregarFicha(ficha, pos);
	}

	//!Agrega una regla en la casilla posicion
	/*!
	  \param regla Regla que se va a agregar
	  \param posicion Entero que indica en donde se pondra la regla
	 */
	void agregarRegla(SRegla* regla, int posicion)
	{
		m_casillas[posicion]->setRegla(regla);
	}

	//!Remueve las cartas en una posicion
	/*!
	  \param posicion Entero que se indica la posicion en la que se va a eliminar las cartas
	 */
	void removerCartas(int posicion)
	{
		m_casillas[posicion]->rmCartas();
	}

};

#endif // STablero_h
