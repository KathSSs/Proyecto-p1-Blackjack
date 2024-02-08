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
	if (baraja == nullptr) {
		baraja = new Mazo();
	}
	baraja->inicializar();//inicializando el mazo
	baraja->barajar();// barajar alistar cartas
	
	 
	int cantJugadores = 0;
	std::cout << "\tIngrese el numero de jugadores\t" << std::endl;
	std::cin >> cantJugadores;
	
	
	while (cantJugadores <= 7) {
;		for (int i = 0; i < cantJugadores; i++) {
			std::string name = " ";
			Mano* mano = new Mano(); //creación de mano para cada jugador

			std::cout << "\tIngrese el nombre del jugador\t";
			std::cin >> name;
				Jugador * nuevo = new Jugador(name);
			listaJugadores.Insertar(nuevo);
			nuevo->setMano(mano->agregarCarta(baraja->tomarCarta()));
		}
		Mano* dealerM = new Mano();
		Dealer* dealerCPU = new Dealer(dealerM);
	}







}
