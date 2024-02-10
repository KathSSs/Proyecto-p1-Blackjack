#ifndef JUGADORGENERICO_H
#define JUGADORGENERICO_H
#include "Mano.h"
#include "Mazo.h"
#include "Carta.h"
#include <fstream>

class JugadorGenerico
{
protected:
	Mano* mano;
	std::string nickName;
public:
	JugadorGenerico();
	JugadorGenerico(Mano* m, std::string name);
	~JugadorGenerico();
	void setName(std::string nam);
	std::string getName();
	virtual Carta* pedirCarta() = 0;
	virtual bool sePaso() = 0;
	virtual int getPuntos() =0;
	std::string toString();
	virtual Mano* getMano(); 

	void guardarJugadorGenerico(std::ofstream& file);
	JugadorGenerico* leerJugadorGenerico(std::ifstream& file);
};
#endif JUGADORGENERICO_H
