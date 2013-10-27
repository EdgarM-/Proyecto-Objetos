#ifndef _DADO_H
#define _DADO_H

#include <random>
#include <functional>
#include <ctime>

class Dado
{
	std::uniform_int_distribution<int> m_distribucion;
	std::mt19937 m_generador;

public:
	Dado(const int& min, const int& max)
		: m_distribucion(min, max), m_generador(time(NULL))
	{}

	int tirar()
	{
		return m_distribucion(m_generador);
	}

	~Dado(){}
};

#endif // _DADO_H
