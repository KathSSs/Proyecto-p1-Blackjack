#ifndef JUGADORGENERICO_H
#define JUGADORGENERICO_H
#include "Mano.h"
#include "Mazo.h"
#include "Carta.h"

class JugadorGenerico
{
protected:
	Mano* mano;
	std::string nickName;
public:
	JugadorGenerico();
	JugadorGenerico(Mano* m, std::string name);
	~JugadorGenerico();
	/*Carta* pedirCarta();*/
	 bool sePaso();
	 int getPuntos();
	 std::string getName();
	 void setNickName(std::string name);

};
#endif JUGADORGENERICO_H
