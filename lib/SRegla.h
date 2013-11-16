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

#ifndef SRegla_h
#define SRegla_h
#include "SFicha.h"

//! La clase SRegla manejas las reglas 
/*!Es una clase abstracta la cual hay que implementar para poder poner las reglas del juego, que generalmente son reglas de que pasa con las fichas 
 */
class SRegla
{
  //!Constructor
  /*!
    Al estar implementa crea una regla
   */
public:
	SRegla(){}
	//!Define Entra de una ficha
	/*!
	  Este metodo determina que pasa cuando una ficha entra, hay que implementarlo al heredar
	  \param ficha Ficha que entra y se revisa que pasara
	 */
	virtual void fichaEntra(SFicha* ficha) = 0;
	//!Define Sale una ficha
	/*!
	  Este metodo determina que pasa cuando una ficha sale, hay que implementarlo al heredar.
	  Si el metodo sobreescribe las propiedades m_posicion y m_casilla de ficha entonce retorna true
	  para prevenir la accion por defecto, i.e. Sacar la ficha del tablero para reposicionarla.
	  
	  \param ficha Ficha que sale y se revisa que pasara
	  \return bool true para prevenir la accion por defecto (i.e. sobreescribe las propiedades m_posicion y m_casilla de ficha) false de lo contrario
	 */
	virtual bool fichaSale(SFicha* ficha) = 0;
	//! Destructor
	virtual ~SRegla(){}
};

#endif /* SRegla_h */
