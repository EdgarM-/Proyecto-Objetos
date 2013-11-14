#ifndef SRegla_h
#define SRegla_h

#include "SFicha.h"

class SRegla
{
public:
	SRegla(){}

	virtual void fichaEntra(SFicha* ficha) = 0;
	/* Si el metodo sobreescribe las propiedades m_posicion y m_casilla de ficha entonce retorna true
	 * para prevenir la accion por defecto, i.e. Sacar la ficha del tablero para reposicionarla */
	virtual bool fichaSale(SFicha* ficha) = 0;

	virtual ~SRegla(){}
};

#endif /* SRegla_h */
