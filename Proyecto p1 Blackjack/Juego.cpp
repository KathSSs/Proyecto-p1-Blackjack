#include "Juego.h"

Juego::Juego() {
	baraja = new Mazo();
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
	/*baraja->inicializar();*/
	baraja->barajar();

	int cantJugadores = 0;

	// Solicitar el número de jugadores
	std::cout << "\tIngrese el numero de jugadores\t" << std::endl;
	std::cin >> cantJugadores;

	// Validar la cantidad de jugadores
	if (cantJugadores < 1 || cantJugadores > 7) {
		std::cerr << "Numero de jugadores invalido." << std::endl;
		return;
	}
	//// Crear mano del dealer
	Mano* dealerM = new Mano(baraja); 
	Dealer* dealerCPU = new Dealer(dealerM,"Dealer"); //comentar si utilizo pedirCarta o agrego otra como jugador
		dealerCPU->pedirCarta();
		dealerCPU->pedirCarta();
	dealerCPU->volteaSegunda(); // Voltear la segunda carta del dealer
	


	// Crear jugadores y repartir cartas iniciales
	for (int i = 0; i < cantJugadores; i++) {
		std::string nombre;
		std::cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
		std::cin >> nombre;

		Mano* manoJ = new Mano(baraja); 
		Jugador* jugador = new Jugador(manoJ,nombre);
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
		rondasJuego(jugador);

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
			std::cout << "Guardando la partida... "<<std::endl ; 
			std::ofstream file;
			listaJugadores.guardarLista(file); 
			break;
		}
		case 4: {
			// Salir del juego
			std::cout << "Saliendo del juego.\n Gracias por Jugar!!" << std::endl;
			exit(0);
			break;
		}
		default:
			break;
		}
	} while (op < 4);
}

void Juego::menu() {
	int opcion = 0;
	std::cout << "Bienvenido a Blackjack pecador adicto a las apuestas!\n";
	std::cout << "\t1.Jugar nueva partida\t2.Cargar partida anterior\n";
	std::cout << "Ingrese su opcion:  ";
	std::cin >> opcion;
	do {
		switch (opcion)
		{
		case 1: {
			jugar();
			break;
		}
		case 2: {
			std::ifstream  file;
			listaJugadores.leerLista(file);
			break;
		}
		default:
			break;
		}
	} while (opcion <= 2);
}

//void Juego::mostrarJugadores() {
//	listaJugadores.toString(); 
//}