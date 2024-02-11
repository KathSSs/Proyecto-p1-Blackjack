#ifndef MANO_H
#define MANO_H
#include "NodoMano.h"
#include <sstream>
#include <fstream>
class Mano{

private:
	NodoMano* inicio;
	int cartUsadas;
public:
	Mano();
	Mano(Mazo*);
	virtual ~Mano();
	bool agregarCarta(Mazo* nuevaCarta);
	

	////Mazo* getMazo(); 
	Mazo* getMazo();
	int getPuntos();
	void voltea3();
	Carta* ultimaCarta();
	std::string toStringMano();
	Carta* getCartaMano(); 
	bool esAs(); 


	//Metodos de archivos 
	/*void guardarMano(std::ofstream& file);
	static Mano* leerMano(std::ifstream& file);*/
	
};

#endif MANO_H