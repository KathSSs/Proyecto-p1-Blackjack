#ifndef JUGADORGENERICO_H
#define JUGADORGENERICO_H

#include "Mano.h"
class JugadorGenerico
{
protected:
	Mano* mano;
	std::string nickName;
public:
	JugadorGenerico();
	JugadorGenerico(Mano* m, std::string name);
	~JugadorGenerico();
	virtual Carta* pedirCarta()=0;
	virtual bool sePaso()=0;
};
#endif JUGADORGENERICO_H
