#ifndef MANO_H
#define MANO_H
#include "NodoMano.h"
#include <sstream>

//ESTAMOS SEGURAS DE QUE EL VECTOR DE MANO ES DE 52?
//PERO SI UN JUGADOR SOLO PUEDE TENER  CARTAS, PARA AHORRAR MEMORIA SERIA MEJOR 
class Mano{

private:
	NodoMano* inicio;
	int cartUsadas;
public:
	Mano();
	virtual ~Mano();
	bool agregarCarta(Mazo* nuevaCarta);
	int getSumaPuntos();
	std::string toString();


};

#endif MANO_H