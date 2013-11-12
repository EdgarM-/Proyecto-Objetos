#ifndef SPareja_h
#define SPareja_h

//! La clase Pareja es un par de enteros 
/*!
   Los enteros se usaran para almacenar lo que generalmente seran posiciones.
 */

class SPareja {
  //!Constructor
  /*! 
    Por defecto inicia: @param i, j en 0. \n Si ponen de entrada los 2 enteros, entonces:  @param i, j empiezan en esos enteros
   */
 public:
  SPareja(int i =  0, int j = 0): x(i), y(j){} 
  //! Entero 1
  /*! Representaria la posicion x */
  int x;
  //! Entero 2
  /*! Representaria la posicion y */
  int y;
};

#endif // SPareja_h
