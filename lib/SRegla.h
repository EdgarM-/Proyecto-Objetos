#ifndef Regla_h
#define Regla_h

#include "Ficha.h"

class Regla
{
public:
	Regla(){}

	virtual void fichaEntra(Ficha* ficha) = 0;

	virtual void fichaSale(Ficha* ficha) = 0;

	~Regla(){}
};

#endif /* Regla_h */
