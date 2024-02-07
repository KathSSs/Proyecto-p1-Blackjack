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
