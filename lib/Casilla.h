#ifndef Casilla_h
#define Casilla_h

#include <vector>

using namespace std;

class Ficha;
class Carta;

class Casilla {

 public:


    /**
     * @element-type Ficha
     */
    vector< Ficha* > m_fichas;

    /**
     * @element-type Carta
     */
    vector< Carta* > m_cartas;
};

#endif // Casilla_h
