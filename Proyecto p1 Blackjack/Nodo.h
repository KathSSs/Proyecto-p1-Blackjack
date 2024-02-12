#ifndef NODO_H
#define NODO_H
#include "JugadorGenerico.h"
#include "Jugador.h"

struct Nodo{ 
		//puntero al dato
		JugadorGenerico* dato;
		//puntero a la siguiente posición
		Nodo* next;
		//retorna el dato para poder acceder a sus metodos
		JugadorGenerico* getDato() { return dato; }

};
#endif NODO_H

