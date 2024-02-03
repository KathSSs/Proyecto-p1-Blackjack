#include "JugadorGenerico.h"

JugadorGenerico::JugadorGenerico()
{
	mano = nullptr;
	nickName = "Sin definir";
}

JugadorGenerico::JugadorGenerico(Mano* m, std::string name) : mano{ m }, nickName{ name }{}

JugadorGenerico::~JugadorGenerico()
{
	delete mano;
}
