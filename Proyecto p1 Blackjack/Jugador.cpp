#include "Jugador.h"

Jugador::Jugador(Mano* m, std::string name):JugadorGenerico(m,name){}

Jugador::~Jugador(){}

Carta* Jugador::pedirCarta()
{
	return nullptr;
}

bool Jugador::sePaso()
{
	return false;
}
