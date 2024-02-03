#ifndef MANO_H
#define MANO_H
#include "Mazo.h"

class Mano{

private:
	Carta* cartas[10];
	int cartUsadas;

public:
	Mano();
	~Mano();
	void agregarCarta(Mazo* nuevaCarta);
	bool limpiar(); //Comprueba que se eliminan las cartas de la mano de la partida anterior
	int getPuntos();


};

#endif MANO_H