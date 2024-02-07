#include "Lista.h"


void Lista::Insertar(JugadorGenerico* n) {

	if (inicio == nullptr) {
		inicio = new Nodo;
		inicio->dato = n;
		inicio->next = nullptr;
	}
	else {
	
		Nodo* tmp = inicio;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = new Nodo;
		tmp->next->dato = n;
		tmp->next->next = nullptr;
	}
}


Nodo* Lista::getInicio() {
	return inicio;
}

bool Lista::listaVacia() {
	return (inicio == nullptr);
}

Nodo* Lista::Buscar(Nodo* no) {
	if (!getInicio) {
		return nullptr; 
	}
	else {
		Nodo* tmp = inicio; 
		while (tmp != nullptr) {
			if (tmp->getDato() == no->getDato()) {
				return tmp;
			}
			else {
				tmp = tmp->next; 
			}
			return nullptr; 
		}
	}

}

void Lista::borrar(Nodo* m) {
	Nodo* tmp = Buscar(m);
	Nodo* aux = inicio; 

	if (tmp == inicio) {
		inicio->next = tmp->next; 
		delete aux; 
	}
	while (aux->next != tmp) {
		aux = aux->next; 
	}
	aux->next = tmp->next;
	delete tmp; 
}