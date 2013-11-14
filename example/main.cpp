#include <iostream>

/* Incluimos la libreria SaemGames,
 * SJuego.h contiene todos los componentes incluidos por defecto.
 */
#include "../lib/SJuego.h"

/* Vamos a crear la serie de reglas que seran importantes para el desarrollo del juego.
 * Como las reglas se definen en la clase abstracta SRegla que define la llegada y salida 
 * de una ficha a una casilla del tablero de juego, podemos heredar de ella para crear
 * nuestro propio juego de reglas.
 * Necesitaremos dos tipos de reglas: una para interpretar las cartas especiales en ciertas
 * casillas del tablero, y la otra para cuando una ficha llegue a una serpiente o escalera.
 */
class ReglaCartas
	: public SRegla // Heredamos de la clase abstracta para reglas SRegla
{
	/* Como la regla va ha utilizar su propio dado de numeros aleatorios, agregamos el atributo */
	SDado m_dado;
public:
	/* Creamos el constructor */
	ReglaCartas()
	:  m_dado(1,6)
	{}
	/* Como SRegla es una clase abstracta, es necesario implementar los dos metodos que posee
	 * + fichaEntra() 
	 * + fichaSale()
	 */
	/* Como las reglas aplican basada en la carta de la casilla
	 * consultamos la casilla donde ha llegado la ficha y revisamos la
	 * carta que tiene. */
	void fichaEntra(SFicha* ficha)
	{
		/* Optenemos el numero de la carta */
		SCarta* carta = ficha->getCasilla()->getCarta();
		int n_carta;
		/* Revisamos que la casilla determinada tenga una carta */
		if(carta != nullptr)
		{
			n_carta = carta->getNumero();
			/* Optenemos el tablero de juego */
			STablero* tablero = ficha->getCasilla()->getTablero();
			/* Revisamos si es una carta negativa o positiva */
			if (n_carta < 0) // Negativa
			{
				n_carta = n_carta * m_dado.tirar() * (-1);
				std::cout << "Dark: n_carta = " << n_carta << std::endl;
				/* Tomamos la casilla donde se encuentra y retrocedemos la ficha 
				 * el numero inticado de casillas o hasta la posicion 0 */
				if (ficha->getPosicion() <= n_carta)
				{
					tablero->removerFicha(ficha);
					tablero->agregarFicha(ficha, 0);
				}
				else
				{
					int tmp = ficha->getPosicion();
					tablero->removerFicha(ficha);
					tablero->agregarFicha(ficha, tmp - n_carta);
				}
			}
			else // Positiva
			{
				std::cout << "Light: n_carta = " << n_carta << std::endl;
				tablero->moverFicha(ficha, n_carta);
			}
		}
	}

	bool fichaSale(SFicha* ficha)
	{
		/* Como no estamos alterando el nada y no queremos alteral
		 * el desplazamiento de una ficha al salir de la casilla
		 * retornamos false, es decir, no alterar el movimiento
		 * predeterminado. */
		return false;
	}
};
/* La segunda regla para serpientes y escaleras */
class ReglaSE
	: public SRegla
{
	/* Como las serpientes y escaleras conectan dos puntos del tablero
	 * vamos a crear dos variables con ese posiciones m_a salida, m_b llegada
	 */
	int m_a;
	int m_b;
public:
	/* Creamos el constructor */
	ReglaSE(int a, int b)
	: m_a(a), m_b(b)
	{}

	void fichaEntra(SFicha* ficha)
	{
		/* Optenemos el numero de la casilla */
		int casilla = ficha->getPosicion();
		/* Optenemos el tablero de juego */
		STablero* tablero = ficha->getCasilla()->getTablero();
		if (m_a == casilla)
		{
			std::cout << ((m_a - m_b > 0) ? "Escalera: ":"Serpiente: ") << m_a - m_b << std::endl;
			tablero->removerFicha(ficha);
			tablero->agregarFicha(ficha, m_b);
		} 
	}

	bool fichaSale(SFicha* ficha)
	{
		/* Como no estamos alterando el nada y no queremos alteral
		 * el desplazamiento de una ficha al salir de la casilla
		 * retornamos false, es decir, no alterar el movimiento
		 * predeterminado. */
		return false;
	}
};

/* Creamos la clase principal de nuestro Juego de Escalera,
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
	 /* Vamos a crear un nuevo atributo solo para hacer mas facil la identificacion del ganador */
	 SJugador* m_jugador_ganador;
public:
	/* Es muy importante crear el constructor de la Clase derivada de SJuego y llamar a init() */
	Juego()
	: SJuego()
	{
		init();
	}
	void init()
	{
		/* Creamos el dado a utilizar en este juego, estandar de 6 caras. */
		SDado dado(1,6);
		/* Creamos el tablero donde se desarrolla el juego, en escalera es de 100 casillas
		 * por defecto el constructor crea un tablero de tipo LINEAL_REBOTE de n casillas tipo SCasilla 
		 * es decir que cuando una fiche se mueva con STablero::moverFigura(...), si el valor es mayor
		 * al total de casillas la ficha 'rebota' y retrocede el numero de pasos restantes. */
		m_tablero = new STablero(100);
		/* Agregamos el dado al Juego insertandolo en el vector de dados para poder usarlo
		 * mas adelante. */
		m_dados.push_back(dado);
		/* En este caso haremos el juego entre dos jugadores y con solo una ficha por jugador
		 * Como el juego no necesita de equipos no es necesario, por lo que el valor por defecto es suficiente */
		agregarJugador(new SJugador(1, "Rojo"));
		agregarJugador(new SJugador(1, "Azul"));
		/* Agregamos las reglas a las casillas */
		std::vector<int> pinicial = {0, 3, 8, 16, 20, 27, 50, 53, 61, 63, 70, 79, 92, 94, 97};
		std::vector<int> pfinal = {37, 13, 30, 6, 41, 83, 66, 33, 18, 59, 90, 99, 72, 74, 78};
		for (int i = 0; i < pinicial.size(); ++i)
		{
			m_tablero->agregarRegla(new ReglaSE(pinicial[i], pfinal[i]), pinicial[i]);
		}
		/* Para hacer el juego mas intersante hay casillas dentro del tablero que tienen cartas negativas y positivas
		 * en este caso una carta negativa (x < 0) retrocedera al jugador un numero correspondientede dados multiplicado
		 * por el valor absoluto de la carta (1-6),y una carta positiva lo adelantara un numero correspondiente al dado */
		m_tablero->agregarCarta(new SCarta("power", 5), 48);
		m_tablero->agregarRegla(new ReglaCartas(), 48);
		m_tablero->agregarCarta(new SCarta("bad", -3), 24);
		m_tablero->agregarRegla(new ReglaCartas(), 24);
		m_tablero->agregarCarta(new SCarta("bad", -6), 75);
		m_tablero->agregarRegla(new ReglaCartas(), 75);
	}
	/* Implementamos la funcion para saber si hay un ganador */
	bool ganar()
	{
		for (int i = 0; i < m_jugadores.size(); ++i)
		{
			if(m_jugadores[i]->getFichas()[0]->getPosicion() == 99)
			{
				m_estado = GANADO;
				m_jugador_ganador = m_jugadores[i];
				return true;
			}
		}
		return false;
	}
	/* Como no hay forma de empatar implementar empate es facil */
	bool empate() { return false; }

	/* Creamos una forma de sacar y cambiar el dato del jugador ganador por fuera de la clase */
	SJugador* getJGanador()
	{
		return m_jugador_ganador;
	}
	void setJGanador(SJugador* jugador)
	{
		m_jugador_ganador = jugador;
	}

	/* Finalmente de si no hay interfaz grafica solo queda definir lo que ocurre en un turno
	 * revisar el si hay un ganador o un empate con las funciones previamente implementadas
	 * y si no llamar a SJuego::cambiarJugador(), m_jugadores_actual es numero en rotacion
	 * que se relaciona con un jugador de m_jugadores */
	void turno()
	{
		/* Definimos la logica de un turno */
		/* Conseguimos la ficha del jugador actual */
		SFicha* ficha = m_jugadores[m_jugador_actual]->getFichas()[0];
		/* Obtenomos el valor del dado y anunciamos el valor */
		int dado = m_dados[0].tirar();
		std::cout << dado << std::endl;
		/* Desplazamos la figura del jugador actual las casillas indicadas por el dado
		 * las reglas especificadas previamente se haran cargo de las escaleras, serpientes o cartas
		 * especiales en las casillas y el tipo de tablero LINEAL_REBOTE se hara cargo del desbordamiento */
		m_tablero->moverFicha(ficha, dado);
		/* Imprimimos la casilla en la que se encuentra la ficha despues de moverla */
		// std::cout << " Casilla: " << ficha->getPosicion() + 1 << std::endl;
		 /* Revisamos si hay ganador */
		if(ganar() || m_estado == GANADO)
		{
			/* Anunciamos el ganador por salida estandar */
			std::cout << "El ganador es " << m_jugador_ganador->getNombre() << std::endl;
		}
		else
		{
			/* Si no hay ganador cambiamos al siguiente jugador para el proximo turno */
			cambiarJugador();
		}
	}

};

/* La funcion principal del programa, donde creamos una instancia de nuestro Juego. */
int main()
{
	/* Creamos una instancia de nuestro nuevo juego */
	Juego SaemEscalera;
	/* Para probar el juego paso a paso
	 * hasta que halla un ganador */
	std::string dummyString; // Para la captura de entrada
	std::cout << "SaemEscalera cli edition!\n";
	/* Creamos nuestro ciclo */
	while(SaemEscalera.getEstado() == EN_CURSO)
	{
		std::cout << "Ingresa tirar: ";
		std::cin >> dummyString;
		if (dummyString == "tirar")
		{
			SaemEscalera.turno();
		}
	}
	/* y listo! */

	return 0;
}
