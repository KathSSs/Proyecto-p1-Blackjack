#ifndef JUGADORGENERICO_H
#define JUGADORGENERICO_H
#include "Mano.h"
#include "Mazo.h"
#include "Carta.h"
#include <fstream>
//clase padre de relación de herencia
class JugadorGenerico
{
protected:

	Mano* mano;
	std::string nickName;
public:
	//Constructor por defecto
	JugadorGenerico();
	//Constructor parametrizado
	JugadorGenerico(Mano* m, std::string name);
	//destructor
	~JugadorGenerico();
	//cambia el nombre del jugador
	void setName(std::string nam);
	//retorna el nombre del jugador
	std::string getName();
	//metodo virtual puro (Es una clase abstracta)
	virtual Carta* pedirCarta() = 0;
	//metodo virtual puro (Es una clase abstracta)
	virtual bool sePaso() = 0;
	//metodo virtual puro (Es una clase abstracta)
	virtual int getPuntos() =0;
	//muestra los datos del jugador
	std::string toString();
	//retorna la mano del jugador
	virtual Mano* getMano(); 
	//Archivo de guarda para ambos tipo de jugadore
	void guardarJugadorGenerico(std::ofstream& file);
	//metodo virtual puro para leer archivo (Es clase abstracta)
	 virtual  JugadorGenerico* leerJugadorGenerico(std::ifstream& file)=0;
};
#endif JUGADORGENERICO_H
