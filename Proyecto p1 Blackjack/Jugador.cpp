#include "Jugador.h"

Jugador::Jugador(std::string name)
{
	nickName = name;
}

Jugador::Jugador(Mano* m, std::string name):JugadorGenerico(m, name){}

Jugador::~Jugador(){}

Carta* Jugador::pedirCarta() {
	if (sePaso()) {
		std::cout << "SE HA PASADO DE 21. No se pueden pedir más cartas." << std::endl;
		return nullptr;
	}
	Carta* nuevaCarta = mano->getMazo()->tomarCarta();

	if (nuevaCarta != nullptr) {
		mano->agregarCarta(nuevaCarta);
		std::cout << "Carta recibida: ";
		nuevaCarta->Mostrar();  
		std::cout << std::endl;
		return nuevaCarta;
	}
	else {
		std::cerr << "Error: No hay cartas disponibles en el mazo." << std::endl;
		return nullptr;
	}
}

bool Jugador::sePaso() {
	return (mano->getPuntos()>21);
}
int Jugador::getPuntos() {
	return mano->getPuntos();
}

void Jugador::setMano(Mano* m)
{
	 mano = m; 
}

Mano* Jugador::getMano() {
	return mano;
}

void Jugador::agregarCarta(Carta* nuevaCarta) {
	mano->agregarCarta(nuevaCarta);
}

void Jugador::recibirCarta(Carta* carta) {
	mano->agregarCarta(carta); // Agregar la carta recibida a la mano del jugador
}

bool Jugador::quiereCarta() {
	char opcion;
	std::cout << "¿Desea pedir una carta más? (S/N): ";
	std::cin >> opcion;
	return (opcion == 'S' || opcion == 's');
}
