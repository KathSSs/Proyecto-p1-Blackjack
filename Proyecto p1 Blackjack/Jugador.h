#ifndef JUGADOR_H
 #define JUGADOR_H
#include "JugadorGenerico.h"

class Jugador : public JugadorGenerico
{

public:
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
	 JugadorGenerico* leerJugadorGenerico(std::ifstream& file);

};
#endif JUGADOR_H
