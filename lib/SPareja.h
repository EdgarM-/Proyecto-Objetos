#ifndef SPareja_h
#define SPareja_h

//! La clase Pareja es un par de enteros que se usara para almacenar 2 enteros, que generalmente seran posiciones.
	/*!
	   La clase define la funcion creadora.
	 */

class SPareja {

 public:

 		//! Constructor
		/*!
	   Preja empieza con los valores que le entren al metodo, de lo contrario tomara valores de 0 por defecto.
	 */
 		SPareja(int i=0, int j=0): x(i), y(j){}

 		//! par de enteros
    int x;
    int y;
};

#endif // SPareja_h
