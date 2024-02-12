#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <fstream>
#include <sstream>
class Lista {

private:
	//apuntador a primera posici�n de la lista
	Nodo* inicio;
public:
	//construcotr por defecto
	Lista() : inicio{ nullptr } {}
	//destructor
	~Lista();
	//retorna el inicio de la lista
	Nodo* getInicio();
	//inserta un jugador a contenedor de tipo lista 
	void Insertar(JugadorGenerico*);
	//retorna al jugador, segun posici�n
	Jugador* getJugador(int);
	//nusca la exitencia de un nodo especifico
	Nodo* Buscar(Nodo*); 
	//borra la informaci�n de una persona
	void borrar(Nodo*); 
	//vacia la lista de los datos de la partida anterior
	bool listaVacia();
	//muestra la informaci�n de todos los jugadores
	std::string toString();
	//comprueba si la carta tomada es de tipo AS
	bool esAs();
	//Da opci�n al usuario de dar uno de los dos valores al AS
	void valorDeAs(int); 
	//cuenta lso nodos pra utilizarlo en partes especificas de otros metodos
	int cuentaNodos(); 
	//archivos de la lista
	void guardarLista(std::ofstream& file);
	void leerLista(std::ifstream& file);
	//Da la opci�n de pasar de turno y continuar con el siguiente en la ronda
	JugadorGenerico* sigJug();
};

#endif
