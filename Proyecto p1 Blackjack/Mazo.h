#ifndef MAZO_H
#define	MAZO_H
#include <random>
#include "Carta.h"

class Mazo
{
protected:
	//vector que contiene todas las cartas de la baraja
	Carta* cartas[52]; 
	int can; 
	int tam;
public: 
	//Constructor por defecto
	Mazo();
	//destrucctor
	~Mazo();
	void inicializar(); 
	//baraja aleatoriamente todas las cartas
	void barajar();
	//Para tomar una carta del mazo
	Carta* tomarCarta(); 
	//muestra la información del mazo
	std::string toStringMazo(); 

	//Metodos de archivos 
	void guardarMazo(std::ofstream& file);
	static Mazo* leerMazo(std::ifstream& file);
};
#endif 
