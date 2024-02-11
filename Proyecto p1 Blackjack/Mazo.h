#ifndef MAZO_H
#define	MAZO_H
#include <random>
#include "Carta.h"

class Mazo
{
protected:
	Carta* cartas[52];
	int canCartas; 
public: 
	
	Mazo(); 
	~Mazo();
	void inicializar(); 
	void barajar();
	Carta* tomarCarta(); 
	void mostrarMazo(); 
	
};
#endif 
