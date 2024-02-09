#ifndef MANO_H
#define MANO_H
#include "Mazo.h"
#include <sstream>
#include <fstream>
class Mano{

private:
	Carta* cartas[10];
	int cartUsadas;
	Mazo* mazo; //le entra el mazo para saber con que mazo estan juagando 
public:
	Mano(Mazo* m);
	Mano();
	Mano(int cartUsadasArchi, Carta* cartasArchi[10]);
	~Mano();
	void agregarCarta(Carta* nuevaCarta);
	Mazo* getMazo(); 
	bool limpiar(); //Comprueba que se eliminan las cartas de la mano de la partida anterior
	int getPuntos();
	void voltea2();
	Carta* ultimaCarta();
	std::string toStringMano();
	Carta* getCarta(); 
	bool esAs(); 
	void guardarMano(std::ofstream& file);
	static Mano* leerMano(std::ifstream& file);
	
};

#endif MANO_H