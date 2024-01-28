#ifndef MAZO_H
#define	MAZO_H
#include <random>
#include "Carta.h"

class Mazo
{
private:
	Carta* cartas;
	int canCartas; 
public: 

	Mazo(); 
	~Mazo();
	void inicializar(); 
	void barajar();
	Carta* tomarCarta(); 
	
};
#endif MAZO_H
