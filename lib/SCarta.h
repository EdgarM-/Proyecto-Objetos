#ifndef SCarta_h
#define SCarta_h

#include <string>

//! La clase SCarta es la base para modelar cartas
/*!
   Se definen las funciones para modelar lo basico de una carta, como colocar un nombre a una carta u obtener el nombre de la carta
*/

class SCarta {

protected:

	//! Nombre que identifica la carta
	std::string m_nombre;
	//! Numero de la carta
	int m_numero;

public:
	//! Constructor
	/*!
	  @ref m_nombre toma el valor del  string que halla entrado al constructor, o sera vacio en caso de que no entre nada al constructor
	  \param nombre String que se asigna al nombre de la carta
	 */
	SCarta(std::string nombre = "")
		: m_nombre(nombre)
	{}

	//! Devuelve el nombre de la carta
	/*!
	  \sa setNombre();
	*/
	std::string getNombre() const
	{
		return m_nombre;
	}

	//! Cambiar el nombre de la carta
	/*!
	  \param nombre es el nombre que va a tomar la carta
	   \sa getNombre();
	 */
	void setNombre(std::string nombre)
	{
		m_nombre = nombre;
	}

	//! Devuelve el numero de la carta
	/*!
	  \sa setNumero();
	*/
	int getNumero() const
	{
		return m_numero;
	}

	//! Cambiar el numero de la carta
	/*!
	  \param numero es el numero que va a tomar la carta
	   \sa getNumero();
	 */
	void setNombre(int numero)
	{
		m_numero = numero;
	}

	//! Destructor
	/*!
	   Destruye la carta
	 */
	virtual ~SCarta(){}

};

#endif // SCarta_h
