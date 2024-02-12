#ifndef JUEGO_H
#define JUEGO_H		
#include "Lista.h"
#include "Mazo.h"
#include "Jugador.h"
#include "Dealer.h"
//controladora del juego
class Juego
{
private:
	Lista listaJugadores;
	Mazo* baraja;

public:
	//Constructor por defecto, inicializa datos importantes
	Juego();
	//destructor del juego
	~Juego();
	//contine la logico del juego y las acciones a realizar en orden
	void jugar();
	/*void mostrarJugadores();*/ 
	//despliega opciones en un sub-menu para el usuario poder realizar acciones
	void rondasJuego(Jugador*);
	//Primer menu deplegado cuando el usuario ingresa, dandole las posibles acciones a realizar
	void menu();
	
};


#endif JUEGO_H