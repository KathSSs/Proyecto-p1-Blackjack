#include "Mano.h"

Mano::Mano(Mazo* m) : mazo(m), cant(0), tama(10) {
	for (int i = 0; i < tama; ++i) {
		cartas[i] = nullptr;
	}
}



Mano::Mano(): Mano(nullptr) {} // Constructor por defecto


Mano::Mano(int cartUsadasArchi, Carta* cartasArchi[10])
{
	cant = cartUsadasArchi; //Se usa aqui cant??
	for (int i = 0; i < 10; i++) {
		cartas[i] = cartasArchi[i];
	}
}


Mano::~Mano()
{
	for (int i = 0; i < cant; ++i) {
		delete cartas[i];
	}
}

void Mano::agregarCarta(Carta* nuevaCarta) {
	if (cant < tama) {
		cartas[cant++] = nuevaCarta;
	}
	else {
		std::cout << "No se pueden agregar mas cartas, la mano esta llena." << std::endl;
	}
}


bool Mano::limpiar()
{
	for (int i = 0; i < cant; i++) {
		cartas[i] = nullptr; //podemos usarlo para la siguiente partida, por eso no se elimina el vector
		cant = 0;
	}
	if (cartas[0] == nullptr)return true;
	else return false;
}

int Mano::getPuntos()
{
	int sumaPuntosCartas = 0;
	for (int i = 0; i < cant; i++) {
		sumaPuntosCartas += cartas[i]->getValor();
	}
	return sumaPuntosCartas;
}

Carta* Mano::ultimaCarta() {
	if (cant > 0) {
		return cartas[cant - 1];
	}
	else {
		return nullptr;
	}
}


Mazo* Mano::getMazo() { return mazo; }

void Mano::voltea2()
{
	cartas[1]->voltear();
}

std::string Mano::toStringMano()
{
	std::stringstream s;
	for (int i = 0; i < cant; i++) {
		s <<"  " << cartas[i]->Mostrar()<< "  ";
	}
	return s.str();
}

Carta* Mano::getCarta()
{
	for (int i = 0; i < cant; i++) {
		return cartas[i];
	}
}


bool Mano::esAs() {
		
			if (getCarta()->getValor() == 1) {
				return true;
			}
			else{
				return false;
			}
}
	
void Mano::guardarMano(std::ofstream& file) {
	file << cant << '\t';
	for (int i = 0; i < cant; i++) {
		 cartas[i]->guardarCarta(file);
	}
}

Mano* Mano::leerMano(std::ifstream& file) {
	Carta* cartasArchi[10];
	std::string buffer;
	int cartUsadasArchi=0;

	while (std::getline(file, buffer)) {
		std::istringstream linea{ buffer };
		linea >> cartUsadasArchi;
		for (int i = 0; i < cartUsadasArchi; i++) {
			cartasArchi[i] = Carta::leerCarta(file);
		}
	}
		return new Mano(cartUsadasArchi,cartasArchi);
		file.close();
	}

