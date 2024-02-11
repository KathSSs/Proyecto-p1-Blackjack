#include "Mano.h"


Mano::Mano()
{
	inicio = nullptr;
	cartUsadas = 0;
}


Mano::~Mano()
{
	if (inicio != nullptr)delete inicio;
}

bool Mano::agregarCarta(Mazo* nuevaCarta)
{
	if (inicio == nullptr) {
		inicio = new NodoMano(nuevaCarta, inicio);
		cartUsadas++;
		return true;
	}
	else
		if (inicio != nullptr) {
			NodoMano* auxi = inicio;
			auxi = auxi->getSiguiente();
			NodoMano* nuevo = new NodoMano(nuevaCarta, nullptr);
			auxi->setNodoMano(nuevo);
			cartUsadas++;
			return true;
		}
		else return false;
}

Mazo* Mano::getMazo()
{
	return getMazo();
}

int Mano::getPuntos()
{
	NodoMano* auxi = inicio;
	int sumaPuntos = 0;
	if (auxi == nullptr)
		sumaPuntos += 0;
	else
		while (auxi != nullptr) {
			sumaPuntos += auxi->getCarta()->getValor();
			auxi = auxi->getSiguiente();
		}

	return sumaPuntos;
}

std::string Mano::toStringMano()
{
	NodoMano* auxi = inicio;
	std::stringstream s;
	while (auxi != nullptr) {
		auxi->getMazo()->tomarCarta()->Mostrar(); //Revisar
		auxi = auxi->getSiguiente();
	}
	return s.str();
}


Carta* Mano::ultimaCarta() {
	NodoMano* auxiliar = inicio;
	NodoMano* aux2;
	if (inicio!=nullptr) {
		aux2 = auxiliar;
		auxiliar = auxiliar->getSiguiente();
	
	}
	return aux2->getCarta();
}


void Mano::voltea3()
{
	NodoMano* auxVoltea = inicio;
	auxVoltea->getMazo()->voltea2();
}

Carta* Mano::getCartaMano()
{
	NodoMano* auxMano = inicio;
	return (Carta*)auxMano->getMazo();
	
	
}

bool Mano::esAs() {
	NodoMano* auxAs = inicio;
	if (auxAs != nullptr) {
		if (auxAs->getCarta()->getValor() == 1) {
			return true;
		}
		else {
			auxAs = auxAs->getSiguiente();
		}
	}
	else return false;
}
	
//void Mano::guardarMano(std::ofstream& file) {
//	file << cant << '\t';
//	for (int i = 0; i < cant; i++) {
//		 cartas[i]->guardarCarta(file);
//	}
//}
//
//Mano* Mano::leerMano(std::ifstream& file) {
//	Carta* cartasArchi[10];
//	std::string buffer;
//	int cartUsadasArchi=0;
//
//	while (std::getline(file, buffer)) {
//		std::istringstream linea{ buffer };
//		linea >> cartUsadasArchi;
//		for (int i = 0; i < cartUsadasArchi; i++) {
//			cartasArchi[i] = Carta::leerCarta(file);
//		}
//	}
//		return new Mano(cartUsadasArchi,cartasArchi);
//		file.close();
//	}

