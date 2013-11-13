#ifndef SRegla_h
#define SRegla_h

#include "SFicha.h"

class SRegla
{
public:
	SRegla(){}

	virtual void fichaEntra(SFicha* ficha);

	virtual void fichaSale(SFicha* ficha);

	~SRegla(){}
};

#endif /* SRegla_h */
