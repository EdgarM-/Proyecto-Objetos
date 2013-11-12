#ifndef SPila_Cartas_h
#define SPila_Cartas_h

#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

#include "SCarta.h"


class SPila_Cartas {

protected:
	std::string m_nombre;
	std::vector< SCarta* > m_cartas;

public:

	SPila_Cartas(std::string nombre): m_nombre(nombre){}

	void push(SCarta* carta){
		m_cartas.push_back(carta);
	}

	SCarta* pop(){
		SCarta* carta = m_cartas.back();
		m_cartas.pop_back();
		return carta;
	}

	void shuffle(){
		std::vector< bool > v(m_cartas.size(), false);
		int n;

		for (int i = 0; i < m_cartas.size(); ++i)
		{
			if (v[i] == true)
				continue;

			n = rand() % m_cartas.size()
			if (n != i && v[n] == false)
			{
				std::swap(m_cartas[i], m_cartas[n]);

				v[i] = true;
				v[n] = true;
			}
			else --i;
		}
	}

	~SPila_Cartas()
	{
		for (auto& carta : m_cartas)
			delete carta;
		m_cartas.clear();
	}

	~SPila_Cartas(){}

};

#endif // SPila_Cartas_h
