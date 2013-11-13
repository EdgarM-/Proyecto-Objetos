#ifndef SRegla_h
#define SRegla_h

#include "SFicha.h"

class SRegla
{
public:
	SRegla(){}

	virtual void fichaEntra(SFicha* ficha) = 0;

	virtual void fichaSale(SFicha* ficha) = 0;

	~SRegla(){}
};

#endif /* SRegla_h */
