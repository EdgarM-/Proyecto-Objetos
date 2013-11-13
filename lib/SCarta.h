#ifndef Carta_h
#define Carta_h

#include <string>


class Carta {

protected:
	std::string m_nombre;

public:
	Carta()
		: m_nombre("")
	{}

	Carta(string nombre)
		: m_nombre(nombre)
	{}

	std::string getNombre()
	{
		return m_nombre;
	}

	void setNombre(std::string nombre)
	{
		m_nombre = nombre;
	}

};

#endif // Carta_h
