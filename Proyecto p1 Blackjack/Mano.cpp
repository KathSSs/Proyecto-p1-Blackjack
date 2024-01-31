#include "Mano.h"

Mano::Mano()
{
	inicio = nullptr;
	cartUsadas = 0;
}

Mano::~Mano()
{
	if(inicio!=nullptr)delete inicio;
}

bool Mano::agregarCarta(Mazo* nuevaCarta)
{
	if (inicio == nullptr) {
		inicio = new NodoMano(nuevaCarta, inicio);
		cartUsadas++;
		return true;
	}
	else
		if (inicio != nullptr) {
			NodoMano* auxi = inicio;
			auxi = auxi->getSiguiente();
			NodoMano* nuevo = new NodoMano(nuevaCarta, nullptr);
			auxi->setNodoMano(nuevo);
			cartUsadas++;
			return true;
		}
		else return false;
}

int Mano::getSumaPuntos()
{
	NodoMano* auxi = inicio;
	int sumaPuntos=0;
	if (auxi == nullptr)
		sumaPuntos+=0;
	else
		while (auxi != nullptr) {
			sumaPuntos += auxi->getCarta()->tomarCarta()->getValor();
			auxi = auxi->getSiguiente();
		}

	return sumaPuntos;
}

std::string Mano::toString()
{
	NodoMano* auxi=inicio;
	//std::stringstream s;
	while (auxi != nullptr) {
		auxi->getCarta()->tomarCarta()->Mostrar(); //Revisar
		auxi = auxi->getSiguiente();
	}
	//return s.str;
}
