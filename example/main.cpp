#include <iostream>

#include "../lib/SJuego.h"

/* Creamos la clase principal de nuestro Juego de Tetris,
 * hereda de la clase principal de la libreria, SJuego,
 * para tener acceso a la logica de la libreria.
 * Para crear un juego se deben implementar los metodos abstractos:
 * + init()
 * + turno()
 * + ganar()
 * + empate()
 */
class Juego
	: public SJuego
{
	/* Definimos la implementacion del metodo abstracto init que se encarga de la inicializacion del juego.
	 * Dentro de esta funcion debemos alocar la memoria que va a utilizar nuestro juego
	 * ademas de crear los elementos basicos como el tablero. */
	void init()
	{
		/* Creamos el dado a utilizar en este juego, estandar de 6 caras. */
		SDado dado(1,6);
		/* Creamos el tablero donde se desarrolla el juego, en escalera es de 100 casillas */
		m_tablero = new STablero(100);
		/* Agregamos el dado al Juego insertandolo en el vector de dados para poder usarlo
		 * mas adelante. */
		m_dados.push_back(dado);
		
	}
};

/* La funcion principal del programa, donde creamos una instancia de nuestro Juego. */
int main()
{
	std::cout << "Hello World!";
	return 0;
}
