#ifndef JUEGO_H
#define JUEGO_H		
#include "Lista.h"
#include "Mazo.h"
class Juego
{
private: 
	Lista listaJuagadores; 
	Mazo*  baraja;

public:
	Juego();
	~Juego();
	void jugar();
	void mostrarJugadores();

};


#endif JUEGO_H