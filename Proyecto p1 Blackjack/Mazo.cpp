#include "Mazo.h"

Mazo::Mazo() : can{ 0 }, tam{ 52 } {
	//limpiar el vector 
	for (int i = 0; i < tam; i++) {
		cartas[i] = nullptr; 
	}
	inicializar(); //Aqui se llama a incializar
}
Mazo::~Mazo(){} //nada se destruye por dentro 


void Mazo::inicializar(){
	int pos= 0;
	for (int palo = 0; palo < 4; ++palo) {
		for (int valor = 0; valor < 13; ++valor) {
			cartas[pos++] = new Carta(valor, static_cast<Palo>(palo), false); 
		}
	}
	can = tam; // Actualizamos el contador de cartas en el mazo
}

void Mazo::barajar(){
	std::random_device rd;
	std::mt19937 g(rd());
	int cantidad = can; //Hice esto en caso que se este alterando can durante la resta del for 
	for (int i = cantidad - 1; i > 0; --i) {
		std::uniform_int_distribution<int> dist(0, i);
		int j = dist(g);
		Carta* temp = cartas[i];
		cartas[i] = cartas[j];
		cartas[j] = temp;
	}
}

Carta* Mazo::tomarCarta() {
	if (can > 0) {
		Carta* carta = cartas[can - 1];
		cartas[can - 1] = nullptr;
		can--;
		return carta;
	}
	else {
		return nullptr; // Indica que no hay cartas para tomar
	}
}


void Mazo::voltea2()
{
	cartas[1]->voltear();
}


std::string Mazo::toStringMazo() {
	std::stringstream s; 
	s << "MAZO COMPLETO ES EL SIGUIENTE" << std::endl;
	for (int i = 0; i < can; i++) {
		s << cartas[i]->Mostrar() << std::endl; 
	}
	return s.str(); 
}