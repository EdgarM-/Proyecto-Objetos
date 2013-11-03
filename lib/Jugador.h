#ifndef Jugador_h
#define Jugador_h

#include <vector>
#include <string>

#include "Ficha.h"

using namespace std;


class Jugador {

 public:

    void retirar()  = 0;

 public:
    string m_nombre;
    int m_equipo;

 public:


    /**
     * @element-type Ficha
     */
    vector< Ficha > m_fichas;
};

#endif // Jugador_h
