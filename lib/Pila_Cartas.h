#ifndef Pila_Cartas_h
#define Pila_Cartas_h

#include <vector>
#include <string>
#include <cstdlib>

#include "Carta.h"

using namespace std;

class Pila_Cartas {

 public:

 		Pila_Cartas(string s): m_nombre(s){}

    Boolean push(Carta& c){
    	m_cartas.push_back(c);
    };

    Carta &pop(){
    	Carta c;
    	c=m_cartas.back();
    	m_cartas.erase(m_cartas.end());
    	return c;
    };

    void shuffle(){
    	vector<Boolean> v(false);
    	v.resize(m_cartas.size())
    	Carta c;
    	int n;
    	for (int i = 0; i < m_cartas.size(); ++i)
    	{
    		if (v[i]==true)
    		{
    			continue;
    		}
    		n=rand() % m_cartas.size()-1 +0
    		if (n!=i && v[n]== false)
    		{
    			c=m_cartas[i];
    			m_cartas[i]=m_cartas[n];
    			m_cartas[n]=c;
    			v[i]=true; v[n]=true;
    		}
    		else{
    			--i;
    		}
    	}
    };

 public:
    string m_nombre;

 public:


    /**
     * @element-type Carta
     */
    vector< Carta* > m_cartas;
};

#endif // Pila_Cartas_h
