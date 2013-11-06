#ifndef Dado_h
#define Dado_h

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

#endif // Dado_h
