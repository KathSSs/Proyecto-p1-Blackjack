#ifndef MANO_H
#define MANO_H
#include "Mazo.h"
#include <sstream>
#include <fstream>
class Mano{

private:
	Carta* cartas[10];
	int cant;
	int tama; 
	Mazo* mazo; //le entra el mazo para saber con que mazo estan jugando 
public:

	Mano(Mazo* m);
	Mano();
	Mano(int cartUsadasArchi, Carta* cartasArchi[10]);//Metodo de archivos 
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

	//Metodos de archivos 
	void guardarMano(std::ofstream& file);
	static Mano* leerMano(std::ifstream& file);
	
};

#endif MANO_H