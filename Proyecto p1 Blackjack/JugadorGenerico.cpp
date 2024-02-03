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

//Carta* JugadorGenerico::pedirCarta()
//{
//	mano->agregarCarta(Mazo* nuevaCarta);
//}

bool JugadorGenerico::sePaso()
{
	return (mano->getPuntos() > 21);
}

int JugadorGenerico::getPuntos()
{
	return mano->getPuntos();
}

std::string JugadorGenerico::getName()
{
	return nickName;
}

void JugadorGenerico::setNickName(std::string name)
{
	nickName = name;
}
