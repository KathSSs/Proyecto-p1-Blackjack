#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <fstream>
#include <sstream>
class Lista {

private:
	Nodo* inicio;
public:
	Lista() : inicio{ nullptr } {}
	~Lista();
	Nodo* getInicio();
	void Insertar(JugadorGenerico*);
	Jugador* getJugador(int);
	Nodo* Buscar(Nodo*); 
	void borrar(Nodo*); 
	bool listaVacia();
	std::string toString();
	
	bool esAs();
	void valorDeAs(int); 
	int cuentaNodos(); 
	void guardarLista(std::ofstream& file);
	void leerLista(std::ifstream& file);

	JugadorGenerico* sigJug();
};

#endif
