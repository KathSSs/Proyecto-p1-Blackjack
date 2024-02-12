#include "Dealer.h"



Dealer::Dealer(Mano* m,std::string name):JugadorGenerico(m, name) { }


//Dealer::Dealer(): JugadorGenerico(mano= new Mano()) {}


Dealer::~Dealer() {
	delete mano; 
}


Carta* Dealer::pedirCarta() {
	if (sePaso()) {
		std::cout << "SE HA PASADO DE 21. No se pueden pedir más cartas." << std::endl;
		return nullptr;
	}

	if (mano->getPuntos() < 16) {
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
	
}

void Dealer::recibirCarta(Carta* carta) {
	if (mano != nullptr) {
		mano->agregarCarta(carta);
	}
	else {
		std::cerr << "Error: El puntero 'mano' es nullptr." << std::endl;
	}
}


bool Dealer::sePaso() {
	return (mano->getPuntos() > 21);
}


int Dealer::getPuntos() {
	return mano->getPuntos();
}

bool Dealer::debePedirCarta(){
	return mano->getPuntos() < 17;
}


void Dealer::volteaSegunda()
{
	mano->voltea2();
}

Mano* Dealer::getMano() {
	return mano;
}

JugadorGenerico* Dealer::leerJugadorGenerico(std::ifstream& file)//Cargando para leer jugador tipo dealer
{
	std::string name = "";
	getline(file, name, '\t');

	Mano* m = m->leerMano(file);
	m->getMazo()->leerMazo(file);
	return new Dealer(m, name);
}