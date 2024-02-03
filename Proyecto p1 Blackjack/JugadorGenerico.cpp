#include "JugadorGenerico.h"

JugadorGenerico::JugadorGenerico()
{
	mano =	new Mano();
	nickName = "Sin definir";
}

JugadorGenerico::JugadorGenerico(Mano* m, std::string name) : mano{ m }, nickName{ name }{}

JugadorGenerico::~JugadorGenerico()
{
	delete mano;
}

Carta* JugadorGenerico::pedirCarta(Carta* nuevaCarta)
{
	mano->agregarCarta(nuevaCarta);
}

bool JugadorGenerico::sePaso()
{
	return (mano->getPuntos() > 21);
}

int JugadorGenerico::getPuntos()
{
	mano->getPuntos();
}

std::string JugadorGenerico::getName()
{
	return nickName;
}

void JugadorGenerico::setNickName(std::string name)
{
	nickName = name;
}
