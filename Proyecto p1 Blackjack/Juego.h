#ifndef JUEGO_H
#define JUEGO_H		
#include "Lista.h"#include <iostream>
#include <algorithm>
#include <random>
#include "Carta.h"
#include "Mazo.h"
#include "Jugador.h"
#include "Dealer.h"


class Juego
{
private: 
	Mazo* mazo;
	Jugador** jugadores;
	int numJugadores;
	Dealer* dealer;

public:
	Juego(int);
	~Juego();
	void jugar();
	
	
};


#endif JUEGO_H