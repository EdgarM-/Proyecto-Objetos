#ifndef Tablero_h
#define Tablero_h

#include <vector>

#include "Carta.h"
#include "Casilla.h"
#include "Ficha.h"

using namespace std;

class Tablero {

 public:

    Ficha getFicha();

    Ficha getFichas();

    Carta &getCarta();

    Carta &getCartas();

    void limpiar();

    void agregarFicha();

    void agregarCarta();

    void removerFicha();

    void removerCarta();

 public:
    Integer m_filas;
    Integer m_columnas;

 public:


    /**
     * @element-type Casilla
     */
    vector< Casilla > m_casillas;
};

#endif // Tablero_h
