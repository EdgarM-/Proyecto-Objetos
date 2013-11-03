#ifndef Ficha_h
#define Ficha_h

#include "Pareja.h"


class Ficha {

 public:

     int getFila();

     int getColumna();

     Pareja getPareja();

     void setFila();

     void setColumna();

     void setPareja();

 public:
    int m_fila;
    int m_columna;

};

#endif // Ficha_h
