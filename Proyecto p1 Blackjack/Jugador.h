#ifndef JUGADOR_H
 #define JUGADOR_H
#include "JugadorGenerico.h"

class Jugador : public JugadorGenerico
{
private:
	std::string nickName;
public:
	Jugador(std::string name);
	Jugador(Mano* m, std::string name);
	~Jugador();
	Carta* pedirCarta();
	 bool sePaso();
	 int getPuntos();
	 std::string getName();
	 void setNickName(std::string);
	 void setMano(Mano* m);
	 std::string toString();
};
#endif JUGADOR_H
