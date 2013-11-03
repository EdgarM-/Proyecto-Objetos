#ifndef Carta_h
#define Carta_h

#include <string>


class Carta {

 public:
 		carta(): m_nombre(""){}
 		carta(string s): m_nombre(s){}
    string m_nombre;

};

#endif // Carta_h
