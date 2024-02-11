#ifndef MAZO_H
#define	MAZO_H
#include <random>
#include "Carta.h"

class Mazo
{
protected:
	Carta* cartas[52]; 
	int can; 
	int tam;
public: 
	Mazo(); 
	~Mazo();
	void inicializar(); 
	void barajar();
	Carta* tomarCarta(); 
	std::string toStringMazo(); 
	
};
#endif 
