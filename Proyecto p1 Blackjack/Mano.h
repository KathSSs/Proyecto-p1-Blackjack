#ifndef MANO_H
#define MANO_H
#include "Mazo.h"

//ESTAMOS SEGURAS DE QUE EL VECTOR DE MANO ES DE 52?
//PERO SI UN JUGADOR SOLO PUEDE TENER  CARTAS, PARA AHORRAR MEMORIA SERIA MEJOR 
class Mano{

private:
	Carta* cartas[10];
	int cartUsadas;

public:
	Mano();
	~Mano();
	void agregarCarta(Mazo* nuevaCarta);
	bool limpiar(); //aqui se puede cambiar a un bool para ver si se logra eliminar
	int getPuntos();


};

#endif MANO_H