#ifndef JUGADOR_H
 #define JUGADOR_H
#include "JugadorGenerico.h"

class Jugador : public JugadorGenerico
{
private:

public:
	Jugador(Mano* m, std::string name);
	~Jugador();
	 Carta* pedirCarta();
	 bool sePaso();
};
#endif JUGADOR_H
