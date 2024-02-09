#include "Juego.h"

Juego::Juego() {
	baraja = nullptr;
}
Juego::~Juego() {
	if (baraja != nullptr) {
		delete baraja;
	}
}
void Juego::jugar()
{
	int opcion;
	if (baraja == nullptr) {
		baraja = new Mazo();
	}
	//inicializar y barajar el mazo 
	baraja->inicializar();
	baraja->barajar();

	int cantJugadores = 0;

	// Solicitar el número de jugadores
	std::cout << "\tIngrese el numero de jugadores\t" << std::endl;
	std::cin >> cantJugadores;

	// Validar la cantidad de jugadores
	if (cantJugadores < 1 || cantJugadores > 7) {
		std::cerr << "Número de jugadores inválido." << std::endl;
		return;
	}
	// Crear mano del dealer
	Mano* dealerM = new Mano(); //esto esta vacio
	Dealer* dealerCPU = new Dealer(dealerM); //comentar si utilizo pedirCarta o agrego otra como jugador
	dealerCPU->pedirCarta();
	dealerCPU->pedirCarta();
	dealerCPU->volteaSegunda(); // Voltear la segunda carta del dealer

	// Crear jugadores y repartir cartas iniciales
	for (int i = 0; i < cantJugadores; i++) {
		std::string nombre;
		std::cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
		std::cin >> nombre;

		Jugador* jugador = new Jugador(nombre);
		jugador->agregarCarta(baraja->tomarCarta()); // Repartir carta inicial
		jugador->agregarCarta(baraja->tomarCarta()); // Repartir segunda carta
		listaJugadores.Insertar(jugador);
	}

	listaJugadores.toString();

	// Turno de los jugadores
	for (int i = 0; i < cantJugadores; i++) {
		Jugador* jugador = listaJugadores.getJugador(i);
		std::cout << "Turno de " << jugador->getName() << ": " << std::endl;

		// Mostrar la mano actual del jugador
		std::cout << "Mano actual: " << jugador->getMano()->toStringMano() << std::endl;
		//opciones


	}




}

void Juego::rondasJuego(Jugador* j )
{
	int op = 0;
	std::cout << "\tPosibles acciones " << std::endl;
	std::cout << "\t1.Deme una carta\t2.Pasar\t3.Guardar partida\t4.Salir" << std::endl;
	std::cin >> op;
	do {
		switch (op)
		{
		case 1: {
			// Pedir una carta al mazo
			j->agregarCarta(baraja->tomarCarta());
			std::cout << "Carta recibida: " << j->getMano()->ultimaCarta()->Mostrar() << std::endl;
			break;
		}
		case 2: {
			// El jugador pasa su turno
			std::cout << "El jugador pasa su turno." << std::endl;
			break;
		}
		case 3: {
			//aqui iria el metodo para guardar
			break;
		}
		case 4: {
			// Salir del juego
			std::cout << "Saliendo del juego." << std::endl;
			exit(0);
			break;
		}
		default:
			break;
		}
	} while (op < 4);
}