#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <sstream>
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
	std::string toString();
	//void guardaLista();
	//void cargarLista();

};

#endif
