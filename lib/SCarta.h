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

#ifndef SCarta_h
#define SCarta_h

#include <string>

//! La clase SCarta es la base para modelar cartas
/*!
   Se definen las funciones para modelar lo basico de una carta, como colocar un nombre a una carta u obtener el nombre de la carta
*/

class SCarta {

protected:

	//! Nombre que identifica la carta
	std::string m_nombre;
	//! Numero de la carta
	int m_numero;

public:
	//! Constructor
	/*!
	  @ref m_nombre toma el valor del  string que halla entrado al constructor, o sera vacio en caso de que no entre nada al constructor
	  \param nombre String que se asigna al nombre de la carta
	  \param numero Int que se asigna al numero de la carta
	 */
	SCarta(std::string nombre = "", int numero = 0)
		: m_nombre(nombre), m_numero(numero)
	{}

	//! Devuelve el nombre de la carta
	/*!
	  \sa setNombre();
	*/
	std::string getNombre() const
	{
		return m_nombre;
	}

	//! Cambiar el nombre de la carta
	/*!
	  \param nombre es el nombre que va a tomar la carta
	   \sa getNombre();
	 */
	void setNombre(std::string nombre)
	{
		m_nombre = nombre;
	}

	//! Devuelve el numero de la carta
	/*!
	  \sa setNumero();
	*/
	int getNumero() const
	{
		return m_numero;
	}

	//! Cambiar el numero de la carta
	/*!
	  \param numero es el numero que va a tomar la carta
	   \sa getNumero();
	 */
	void setNumero(int numero)
	{
		m_numero = numero;
	}

	//! Destructor
	/*!
	   Destruye la carta
	 */
	virtual ~SCarta(){}

};

#endif // SCarta_h
