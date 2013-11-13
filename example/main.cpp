#include <iostream>

#include "../lib/SJuego.h"

class Juego
	: public SJuego
{
	void init()
	{
		m_tablero = new STablero(100);
		
	}
};

int main()
{
	std::cout << "Hello World!";
	return 0;
}
