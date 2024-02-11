#ifndef NODOMANO_H
#define NODOMANO_H
#include "Mazo.h"

class NodoMano
{
private:
	NodoMano* ptrMano;
	Mazo* ptrCart;
public:
	NodoMano(Mazo* nuevaCarta, NodoMano* inicio);
	virtual~NodoMano();
	void setNodoMano(NodoMano* nodoIni);
	Mazo* getMazo();
	Carta* getCarta();
	NodoMano* getSiguiente();

};
#endif NODOMANO_H