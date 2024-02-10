#include "JugadorGenerico.h"

JugadorGenerico::JugadorGenerico()
{
	mano = new Mano();
	nickName = " ";
	
}

JugadorGenerico::JugadorGenerico(Mano* m, std::string name) : mano{ m }, nickName{ name } {}

JugadorGenerico::~JugadorGenerico()
{
	delete mano;
}

void JugadorGenerico::setName(std::string name) { nickName = name; }

std::string JugadorGenerico::getName(){return nickName;}

std::string JugadorGenerico::toString()
{
	std::stringstream s;
	s << "\t" << getName() << std::endl;
	mano->toStringMano();

	return s.str();
	
}

Mano* JugadorGenerico::getMano() {
	return mano; 
}

void  JugadorGenerico::guardarJugadorGenerico(std::ofstream& file) {
	file << getName() << '\t';
	mano->guardarMano(file);
}

JugadorGenerico* JugadorGenerico::leerJugadorGenerico(std::ifstream& file) {
	std::string name="";
	getline(file, name, '\t');
	
		Mano* m = m->leerMano(file);
	
	return new JugadorGenerico(n, name);
}

//Carta* JugadorGenerico::pedirCarta()
//{
//	mano->agregarCarta(Carta* nuevaCarta);
//}


