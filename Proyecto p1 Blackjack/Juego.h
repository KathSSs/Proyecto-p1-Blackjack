#ifndef JUEGO_H
#define JUEGO_H		
#include "Lista.h"
#include "Mazo.h"
#include "Jugador.h"
#include "Dealer.h"

class Juego
{
private:
	Lista listaJugadores;
	Mazo* baraja;

public:
	Juego();
	~Juego();
	void jugar();
	/*void mostrarJugadores();*/ 
	void rondasJuego(Jugador*);
	void menu();
};


#endif JUEGO_H