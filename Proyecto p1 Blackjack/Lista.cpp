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


Lista::~Lista()
{
	Nodo* actual = inicio;

	while (actual != NULL) {
		inicio = inicio->next; //primero va a ser igual a la segunda posicion
		borrar(actual);
		actual = inicio; //Se asigna el valor de la primer posicion
	}
	actual = NULL;
	inicio = NULL;
}


Nodo* Lista::getInicio() {
	return inicio;
}

bool Lista::listaVacia() {
	return (inicio == nullptr);
}

Nodo* Lista::Buscar(Nodo* no) {
	if (getInicio() == nullptr) {
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
JugadorGenerico* Lista::sigJug() {
	Nodo* tmp = inicio;
	JugadorGenerico* jugnext = nullptr;
	jugnext = tmp->next->getDato();
	return jugnext;
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
std::string Lista:: toString() {

	std::stringstream s;
	Nodo* tmp = inicio;
	int pos = 0; 
	while (tmp != nullptr) {
			s << tmp->getDato()->toString() << std::endl;

			s << tmp->getDato()->getPuntos();
			
			
			tmp = tmp->next;
		
	}
	
		return s.str();
}

bool Lista::esAs() {
	Nodo* tmp = inicio;
	while (tmp != nullptr) {
		if (tmp->getDato()->getMano()->getCarta()->getValor() == 1) {
			return true;
		}
		else
			tmp = tmp->next;
		if (tmp->next == nullptr) {
			return false;
		}
	}
	
}



void Lista::valorDeAs(int opcion) {
	if (esAs()) {
		std::cout << "Desea usar su AS con valor de 11 o de 1 ?\n";
		std::cout << " (1) 11    (2) 1   Valor a escoger: ";
		std::cin >> opcion;

	}
		switch (opcion)
		{
		case 1: {
			Nodo* tmp = inicio;
			tmp->getDato()->getMano()->getCarta()->setValor(11);
			break; 
		}
		case 2: {
			Nodo* tmp = inicio;
			tmp->getDato()->getMano()->getCarta()->setValor(1);
			break;
		}
		default:
			break;
		}


}

int Lista::cuentaNodos()
{
	int contador = 0;
	Nodo* tmp = inicio; 
	while (tmp != nullptr) {
		tmp = tmp->next; 
		contador++;
	}
	return contador;
}

Jugador* Lista::getJugador(int in) {
	if (in < 0 || in >= cuentaNodos()) {
		std::cerr << "Índice de jugador fuera de rango." << std::endl;
		return nullptr;
	}

	Nodo* tmp = inicio;
	for (int i = 0; i < in; i++) {
		tmp = tmp->next;
	}
	return dynamic_cast<Jugador*>(tmp->getDato());
}

void Lista::guardarLista(std::ofstream& file)//guarda la lista de jugadores
{
	
	file.open("registros.txt", std::ios::app);

	if (!file.is_open()) { //hace verificación de si esta cerrado o abierto
		std::cout << "Error al abrir el archivo...\n";
	}
	Nodo* aux = inicio;
	while (aux != nullptr) {
		 aux->getDato()->guardarJugadorGenerico(file); //recurre al guardar de jugadorGenerico

		 aux= aux->next; //Va a la siguiente posición
	}
	file.close();
}



void Lista::leerLista(std::ifstream& file)
{
	
	file.open("registros.txt", std::ios::in);

	JugadorGenerico* jugadorArchi = nullptr;

	if (!file.is_open()) {
		std::cout << "Error al abrir el archivo...\n";
	}
	//revisar
	Nodo* auxiliarArchivo = inicio;
	while (auxiliarArchivo != nullptr) {
		while ((jugadorArchi = auxiliarArchivo->getDato()->leerJugadorGenerico(file)) != nullptr) {
			Insertar(jugadorArchi);
		}
		auxiliarArchivo = auxiliarArchivo->next;
	}
	file.close();
}