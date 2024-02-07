#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista {
public:
	Lista() : inicio{ nullptr } {}
	~Lista();
	Nodo* getInicio();
	void Insertar(Nodo);
	Nodo* Buscar(int);
	void borrar(Nodo);
	bool listaVacia(); 

private:
	Nodo* inicio;
};

#endif
