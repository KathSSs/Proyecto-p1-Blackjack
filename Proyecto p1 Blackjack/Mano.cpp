#include "Mano.h"
Mano::Mano(Mazo* m) : mazo(m)
{   
	cartUsadas = 0;
	for (int i = 0; i < 10; i++) {
		this->cartas[i] = new Carta();
	}
}

Mano::Mano() {
	cartUsadas = 0;
	for (int i = 0; i < 10; i++) {
		this->cartas[i] = new Carta();
	}
	mazo = nullptr;
}

Mano::~Mano()
{
	for (int i = 0; i < 10; i++) {
		if (cartas[i] != nullptr)
			delete this->cartas[i];
	}
}

void Mano::agregarCarta(Carta* nuevaCarta) {
	if (cartUsadas < 10) {
		cartas[cartUsadas] = nuevaCarta;
		cartUsadas++;
	}
}


bool Mano::limpiar()
{
	for (int i = 0; i < cartUsadas; i++) {
		cartas[i] = nullptr; //podemos usarlo para la siguiente partida, por eso no se elimina el vector
		cartUsadas = 0;
	}
	if (cartas[0] == nullptr)return true;
	else return false;
}

int Mano::getPuntos()
{
	int sumaPuntosCartas = 0;
	for (int i = 0; i < cartUsadas; i++) {
		sumaPuntosCartas += cartas[i]->getValor();
	}
	return sumaPuntosCartas;
}



Mazo* Mano::getMazo() { return mazo; }

void Mano::voltea2()
{
	cartas[1]->voltear();
}
