#ifndef JUGADOR_H
 #define JUGADOR_H
#include "JugadorGenerico.h"

class Jugador : public JugadorGenerico
{

public:
	Jugador(std::string name);
	Jugador(Mano* m, std::string name);
	~Jugador();
	Carta* pedirCarta();
	 bool sePaso();
	 int getPuntos();
	 bool quiereCarta(); 
	 void setMano(Mano* m);
	 Mano* getMano(); 
	 void agregarCarta(Carta* nuevaCarta);
	 void recibirCarta(Carta*); 

};
#endif JUGADOR_H
