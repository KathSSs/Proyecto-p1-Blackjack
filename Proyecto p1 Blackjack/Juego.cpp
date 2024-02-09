#include "Juego.h"

Juego::Juego(){
	baraja = nullptr;
}

Juego::~Juego() {
	if (baraja != nullptr) {
		delete baraja;
	}
}

void Juego::jugar()
{
	int opcion = 0;
	if (baraja == nullptr) {
		baraja = new Mazo();
	}
		//inicializar y barajar el mazo 
		baraja->inicializar();
		baraja->barajar();
	

	int canti = 0; //le cambie el nombre por sospechas con recursividad 

	// Solicitar el número de jugadores
	std::cout << "\tIngrese el numero de jugadores\t" << std::endl;
	std::cin >> canti;

	// Validar la cantidad de jugadores
	if (canti < 1 || canti> 7) {
		std::cerr << "Numero de jugadores invalido." << std::endl;
		return;
	}
	
	// Crear mano del dealer
	Mano* dealerM = new Mano(); //esto esta vacio
	Dealer* dealerCPU = new Dealer(dealerM); //comentar si utilizo pedirCarta o agrego otra como jugador
	dealerCPU->pedirCarta();
	dealerCPU->pedirCarta();
	dealerCPU->volteaSegunda(); // Voltear la segunda carta del dealer

	// Crear jugadores y repartir cartas iniciales
	for (int i = 0; i < canti; i++) {
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
	for (int i = 0; i < canti; i++) {
		Jugador* jugador = listaJugadores.getJugador(i);
		std::cout << "Turno de " << jugador->getName() << ": " << std::endl;

		// Mostrar la mano actual del jugador
		std::cout << "Mano actual: " << jugador->getMano()->toStringMano() << std::endl;
		//opciones
		char opcion;
		do {
			std::cout << "¿Desea pedir una carta mas? (S/N): ";
			std::cin >> opcion;

			if (opcion == 'S' || opcion == 's') {
				Carta* nuevaCarta = baraja->tomarCarta();
				jugador->agregarCarta(nuevaCarta); // Agregar nueva carta al jugador
				std::cout << "Nueva carta recibida: " << nuevaCarta->Mostrar() << std::endl;
				std::cout << "Mano actual: " << jugador->getMano()->toStringMano() << std::endl;
			}
		} while ((opcion == 'S' || opcion == 's') && !jugador->sePaso()); // Mientras el jugador desee pedir cartas y no se haya pasado de 21

		if (jugador->sePaso()) {
			std::cout << "¡Se ha pasado de 21! " << jugador->getName() << " pierde." << std::endl;
		}
		else {
			std::cout << jugador->getName() << " pasa." << std::endl;
		}
	}

	// Turno del dealer
	std::cout << "Turno del dealer:" << std::endl;
	std::cout << "Mano actual: " << dealerCPU->getMano()->toStringMano() << std::endl;

	// El dealer pide cartas hasta alcanzar 17 o más
	while (dealerCPU->getPuntos() < 17) {
		Carta* nuevaCarta = baraja->tomarCarta();
		dealerCPU->pedirCarta(); // Agregar nueva carta al dealer
		std::cout << "Nueva carta recibida: " << nuevaCarta->Mostrar() << std::endl;
		std::cout << "Mano actual: " << dealerCPU->getMano()->toStringMano() << std::endl;
	}

	if (dealerCPU->sePaso()) {
		std::cout << "¡El dealer se ha pasado de 21! Todos los jugadores ganan." << std::endl;
	}
	else {
		// Comparar las manos de los jugadores con la del dealer
		for (int i = 0; i < canti; i++) {
			Jugador* jugador = listaJugadores.getJugador(i);
			if (!jugador->sePaso()) {
				if (jugador->getPuntos() > dealerCPU->getPuntos()) {
					std::cout << jugador->getName() << " gana." << std::endl;
				}
				else if (jugador->getPuntos() == dealerCPU->getPuntos()) {
					std::cout << "Empate entre " << jugador->getName() << " y el dealer." << std::endl;
				}
				else {
					std::cout << jugador->getName() << " pierde." << std::endl;
				}
			}
		}
	}
}


