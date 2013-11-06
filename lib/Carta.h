#ifndef Carta_h
#define Carta_h

#include <string>


class Carta {

protected:
	string m_nombre;

public:
	Carta()
		: m_nombre("")
	{}

	Carta(string s)
		: m_nombre(s)
	{}

};

#endif // Carta_h
