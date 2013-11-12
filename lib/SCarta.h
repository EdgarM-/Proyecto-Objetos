#ifndef SCarta_h
#define SCarta_h

#include <string>

//! La clase Carta es la base para modelar cartas
/*!
   Se definen las funciones las funciones para modelar lo basico de una carta, como colocar un nombre a una carta o obtener el nombre de la carta
*/

class SCarta {

protected:

	//! Nombre de la carta
	std::string m_nombre;

public:
	//! Constructor
	/*!
	   m_nombre toma el valor del  string que halla entrado al constructor, o sera vacio en caso de que no entre nada al constructor
	 */
	SCarta(string nombre="")
		: m_nombre(nombre)
	{}

	//! Devuelve el nombre de la carta
	/*!
	  \sa setNombre();
	*/
	std::string getNombre()
	{
		return m_nombre;
	}

	//! Cambiar el nombre de la carta
	/*!
	   m_nombre toma el valor que le entre al metodo.
	   \sa getNombre();
	 */
	void setNombre(std::string nombre)
	{
		m_nombre = nombre;
	}

	//! Destructor
	/*!
	   Destruye la carta
	 */
	~SCarta(){}

};

#endif // SCarta_h
