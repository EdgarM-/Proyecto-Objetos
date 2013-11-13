#ifndef SCarta_h
#define SCarta_h

#include <string>


class SCarta {

protected:
	std::string m_nombre;

public:
	SCarta()
		: m_nombre("")
	{}

	SCarta(string nombre)
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

#endif // SCarta_h
