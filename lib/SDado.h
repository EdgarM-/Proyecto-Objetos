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
