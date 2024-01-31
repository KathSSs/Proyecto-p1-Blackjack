#include "Mano.h"
Mano::Mano()
{
	cartUsadas = 0;

	for (int i = 0; i < 52; i++) {
		this->cartas[i] = new Carta();
	}
}

Mano::~Mano()
{
	for (int i = 0; i < 52; i++) {
		if (cartas[i] != nullptr)
			delete cartas[i];
	}
}

void Mano::agregarCarta(Mazo* nuevaCarta)
{
	if (cartUsadas < 52) {
		cartas[cartUsadas] = nuevaCarta->tomarCarta();
		cartUsadas++;
	}
}

bool Mano::limpiar()
{
	for (int i = 0; i < cartUsadas; i++) {
		cartas[i] = nullptr; //podemos usarlo para la siguiente partida, por eso no se elimina el vector
	}
}

int Mano::getPuntos()
{
	int sumaPuntosCartas = 0;
	for (int i = 0; i < cartUsadas; i++) {
		sumaPuntosCartas += cartas[i]->getValor();
	}
	return sumaPuntosCartas;
}
