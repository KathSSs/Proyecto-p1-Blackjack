#include "Dealer.h"

Dealer::Dealer(Mano* m, std::string name):JugadorGenerico(m){}

Dealer::~Dealer(){}


Carta* Dealer::pedirCarta() {
	if (sePaso()) {
		std::cout << "SE HA PASADO DE 21. No se pueden pedir m�s cartas." << std::endl;
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


bool Dealer::sePaso() {
	return (mano->getPuntos() > 21);
}


int Dealer::getPuntos() {
	return mano->getPuntos();
}





void Dealer::volteaSegunda()
{
	mano->voltea2();
}

