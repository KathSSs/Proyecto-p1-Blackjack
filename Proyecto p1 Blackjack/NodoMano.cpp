#include "NodoMano.h"

NodoMano::NodoMano(Mazo* nuevaCarta, NodoMano* inicio)
{
	ptrCart = nuevaCarta;
	ptrMano = inicio;
}

NodoMano::~NodoMano() {}

void NodoMano::setNodoMano(NodoMano* inicio)
{
	ptrMano = inicio;
}

Mazo* NodoMano::getMazo()
{
	return ptrCart;
}

Carta* NodoMano::getCarta()
{
	return (Carta*)ptrCart;
}


NodoMano* NodoMano::getSiguiente()
{
	return ptrMano;
}

