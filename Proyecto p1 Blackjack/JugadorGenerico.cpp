#include "JugadorGenerico.h"

JugadorGenerico::JugadorGenerico()
{
	mano = new Mano();
	
}

JugadorGenerico::JugadorGenerico(Mano* m) : mano{ m }{}

JugadorGenerico::~JugadorGenerico()
{
	delete mano;
}

//Carta* JugadorGenerico::pedirCarta()
//{
//	mano->agregarCarta(Carta* nuevaCarta);
//}


