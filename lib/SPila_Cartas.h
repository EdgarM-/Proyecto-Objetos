#ifndef SPila_Cartas_h
#define SPila_Cartas_h

#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

#include "SCarta.h"
//!la clase SPila_Cartas es la base para modelar una pila de cartas
/*!
  Aqui se implementan las funciones basicas de una pila de cartas, como push(), pop(), size() y shuffle()
*/
class SPila_Cartas {
  //!Nombre de la pila de cartas
protected:
	std::string m_nombre;
	//!Vector de SCarta que funciona como pila
	std::vector< SCarta* > m_cartas;

public:
	//!Constructor
	/*!
	 Construye la pila de cartas vacia y con el nombre que entre en @ref nombre
	 \param nombre Es el nombre que se asignara a la pila
	 */ 
	SPila_Cartas(std::string nombre): m_nombre(nombre){}
	
	//!Agrega una carta a la pila
	/*! 
	  \param carta Es la carta que se va a agregar a la pila
	  \sa pop()
	 */
	void push(SCarta* carta)
	{
		m_cartas.push_back(carta);
	}
	//!Saca una carta de la pila
	/*!
	  \sa push()
	*/
	SCarta* pop()
	{
		SCarta* carta = m_cartas.back();
		m_cartas.pop_back();
		return carta;
	}
	//!Retorna el tamaño de la pila
	int size()
	{
		return m_cartas.size();
	}
	//!Mezcla las cartas que estan en la pila
	/*!
	 \sa push(), pop()
	 */
	void shuffle()
	{
		std::vector< bool > v(m_cartas.size(), false);
		int n;

		for (int i = 0; i < m_cartas.size(); ++i)
		{
			if (v[i] == true)
				continue;

			n = rand() % m_cartas.size();
			if (n != i && v[n] == false)
			{
				std::swap(m_cartas[i], m_cartas[n]);

				v[i] = true;
				v[n] = true;
			}
			else --i;
		}
	}
	//!Destructor
	/*!
	  Elimina todas las cartas y vacia @ref m_cartas
	 */
	virtual ~SPila_Cartas()
	{
		for (auto& carta : m_cartas)
			delete carta;
		m_cartas.clear();
	}

};

#endif // SPila_Cartas_h
