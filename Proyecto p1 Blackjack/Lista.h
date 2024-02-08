#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista {

private:
	Nodo* inicio;
public:
	Lista() : inicio{ nullptr } {}
	~Lista();
	Nodo* getInicio();
	void Insertar(JugadorGenerico*);
	/*JugadorGenerico* retornaJugador(int numJugador);*/
	Nodo* Buscar(Nodo* ); 
	void borrar(Nodo*); 
	bool listaVacia(); 
	//void guardaLista();
	//void cargarLista();

};

#endif
