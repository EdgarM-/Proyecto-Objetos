#ifndef SDado_h
#define SDado_h

#include <random>
#include <functional>
#include <ctime>
//! La Clase SDado es la base de un dado
/*! Con esta clase se puede conseguir la funcionalidad de un dado*/
class SDado
{
	std::uniform_int_distribution<int> m_distribucion;
	std::mt19937 m_generador;
	
public:
	SDado(const int& min, const int& max)
		: m_distribucion(min, max), m_generador(time(NULL))
	{}

	int tirar()
	{
		return m_distribucion(m_generador);
	}

	~SDado(){}
};

#endif // SDado_h
