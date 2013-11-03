#ifndef Pila_Cartas_h
#define Pila_Cartas_h

#include <vector>
#include <string>

#include "Carta.h"

using namespace std;

class Pila_Cartas {

 public:

    Boolean push();

    Carta &pop();

    void shuffle();

 public:
    string m_nombre;

 public:


    /**
     * @element-type Carta
     */
    vector< Carta* > m_cartas;
};

#endif // Pila_Cartas_h
