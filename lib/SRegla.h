#ifndef SRegla_h
#define SRegla_h

#include "SFicha.h"
//! La clase SRegla manejas las reglas 
/*!Es una clase abstracta la cual hay que implementar para poder poner las reglas del juego, que generalmente son reglas de que pasa con las fichas 
 */
class SRegla
{
  //!Constructor
  /*!
    Al estar implementa crea una regla
   */
public:
	SRegla(){}
	//!Define Entra de una ficha
	/*!
	  Este metodo determina que pasa cuando una ficha entra, hay que implementarlo al heredar
	  \param ficha Ficha que entra y se revisa que pasara
	 */
	virtual void fichaEntra(SFicha* ficha) = 0;
	//!Define Sale una ficha
	/*!
	  Este metodo determina que pasa cuando una ficha sale, hay que implementarlo al heredar
	  \param ficha Ficha que sale y se revisa que pasara
	 */
	virtual void fichaSale(SFicha* ficha) = 0;
	//! Destructor
	virtual ~SRegla(){}
};

#endif /* SRegla_h */
