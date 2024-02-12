#ifndef JUGADOR_H
 #define JUGADOR_H
#include "JugadorGenerico.h"

class Jugador : public JugadorGenerico
{

public:
	//construcor parametrizado
	Jugador(Mano* m, std::string name);
	//constructor por defecto
	~Jugador();
	//metodo para sacar carta del mazo
	Carta* pedirCarta();
	//verifica que no pierda por exeder limite de puntos
	 bool sePaso();
	 //retorna los puntos
	 int getPuntos();
	 //Verifica la respueta del jugador
	 bool quiereCarta(); 
	 //cambia la mano
	 void setMano(Mano* m);
	 //retorna la mano del jugador
	 Mano* getMano(); 
	 //metod qeu agrega una carta nueva a la mano
	 void agregarCarta(Carta* nuevaCarta);
	 //recibe una carta
	 void recibirCarta(Carta*); 
	 //Archivos para leer los datos del jugador
	 JugadorGenerico* leerJugadorGenerico(std::ifstream& file);

};
#endif JUGADOR_H
