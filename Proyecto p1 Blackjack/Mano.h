#ifndef MANO_H
#define MANO_H
#include "Mazo.h"
#include <sstream>
#include <fstream>
class Mano{

private:
	//Almacena las cartas de cada persona
	Carta* cartas[10];
	int cant;
	int tama; 
	Mazo* mazo; //le entra el mazo para saber con que mazo estan jugando 
public:
	//constructor parametrizado
	Mano(Mazo* m);
	//constructor por defecto
	Mano();
	//constructor que recibe datos cuando se retorna la información de los archivos
	Mano(int cartUsadasArchi, Carta* cartasArchi[10]);//Metodo de archivos 
	//destructor
	~Mano();
	//agrega una carta a la mano
	void agregarCarta(Carta* nuevaCarta);
	//retorna el amzo qeu estan utilizando
	Mazo* getMazo(); 
	//Comprueba que se eliminan las cartas de la mano de la partida anterior
	bool limpiar(); 
	//retorna los puntos totales de los jugadores
	int getPuntos();
	//voltea la carta del dealer 
	void voltea2();
	//retorna la ultima carta
	Carta* ultimaCarta();
	//muestra las cartas que componen la mano
	std::string toStringMano();
	//retorna una carta
	Carta* getCarta(); 
	//verifica si la carta es tipo AS
	bool esAs(); 

	//Archivos de mano
	void guardarMano(std::ofstream& file);
	static Mano* leerMano(std::ifstream& file);
	
};

#endif MANO_H