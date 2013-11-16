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

#ifndef SDado_h
#define SDado_h

#include <random>
#include <functional>
#include <ctime>
//! La clase SDado es la base de un dado
/*!
   Con esta clase se puede conseguir la funcionalidad de un dado,
   genera numeros aleatorios entre un numero entero minimo y uno maximo inclusivo.
*/
class SDado
{
	std::uniform_int_distribution<int> m_distribucion;
	std::mt19937 m_generador;
	
public:
	//!Constructor
	/*!
	 Crea el dado con los valores desde @ref min hasta @ref max
	 \param min numero minimo para el dado
	 \param max numero maximo para el dado
	 */
	SDado(const int& min, const int& max)
		: m_distribucion(min, max), m_generador(time(NULL))
	{}
	
	//!Tirar dado
	/*!
	  Se tira el dado y devuelve el numero que salga
	 */
	int tirar()
	{
		return m_distribucion(m_generador);
	}
	//!Destructor
	virtual ~SDado(){}
};

#endif // SDado_h
