#ifndef NODO_H
#define NODO_H
#include "JugadorGenerico.h"

struct Nodo{ 
		JugadorGenerico* dato;
		Nodo* next;
		JugadorGenerico* getDato() { return dato; }

};
#endif NODO_H

