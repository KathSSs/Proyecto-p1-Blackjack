#include "Dealer.h"

Dealer::Dealer(Mano* m, std::string name):JugadorGenerico(m,name){}

Dealer::~Dealer(){}

Carta* Dealer::pedirCarta()
{
	return nullptr;
}

bool Dealer::sePaso()
{
	return false;
}
