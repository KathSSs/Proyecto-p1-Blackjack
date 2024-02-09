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
	
public:
	JugadorGenerico();
	JugadorGenerico(Mano* m);
	~JugadorGenerico();
	virtual Carta* pedirCarta() = 0;
	virtual bool sePaso() = 0;
	virtual int getPuntos() =0;
	virtual std::string toString() = 0;
	virtual Mano* getMano(); 

	virtual void guardarJugadorGenerico(std::ofstream& file) = 0;;
	/*virtual void leerJugadorGenerico(std::ifstream& file)=0;*/
};
#endif JUGADORGENERICO_H
