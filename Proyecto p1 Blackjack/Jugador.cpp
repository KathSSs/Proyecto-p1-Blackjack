#include "Jugador.h"

Jugador::Jugador(std::string name)
{
	nickName = name;
}

Jugador::Jugador(Mano* m, std::string name):JugadorGenerico(m){}

Jugador::~Jugador(){}

Carta* Jugador::pedirCarta() {
	if (sePaso()) {
		std::cout << "SE HA PASADO DE 21. No se pueden pedir m�s cartas." << std::endl;
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
std::string Jugador::getName() {
	return nickName;
}
void Jugador::setNickName(std::string name) {
	nickName = name;
}

void Jugador::setMano(Mano* m)
{
	 mano = m; 
}

std::string Jugador::toString()
{
	std::stringstream s;
	s << "\t" << nickName << std::endl;
	mano->toStringMano();

	return s.str();
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
	std::cout << "�Desea pedir una carta m�s? (S/N): ";
	std::cin >> opcion;
	return (opcion == 'S' || opcion == 's');
}
void  Jugador::guardarJugadorGenerico(std::ofstream& file) {
	file << getName() << '\t';
	mano->guardarMano(file);
}

Jugador* Jugador::leerJugadorGenerico(std::ifstream& file) {
	std::string name = " ";
	getline(file, name, '\t');
	Mano* m = m->leerMano(file);
	
	return new Jugador(m,name);
}