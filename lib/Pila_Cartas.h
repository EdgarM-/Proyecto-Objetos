#ifndef Pila_Cartas_h
#define Pila_Cartas_h

#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

#include "Carta.h"

using namespace std;

class Pila_Cartas {

protected:
	string m_nombre;
	vector< Carta* > m_cartas;

public:

	Pila_Cartas(string s): m_nombre(s){}

	void push(Carta* c){
		m_cartas.push_back(c);
	}

	Carta* pop(){
		Carta* c = m_cartas.back();
		m_cartas.pop_back();
		return c;
	}

	void shuffle(){
		vector<Boolean> v(m_cartas.size(), false);
		int n;

		for (int i = 0; i < m_cartas.size(); ++i)
		{
			if (v[i] == true)
				continue;

			n = rand() % m_cartas.size()
			if (n != i && v[n] == false)
			{
				swap(m_cartas[i], m_cartas[n]);

				v[i] = true;
				v[n] = true;
			}
			else --i;
		}
	}

	~Pila_Cartas()
	{
		for (auto& carta : m_cartas)
			delete carta;
		m_cartas.clear();
	}

};

#endif // Pila_Cartas_h
