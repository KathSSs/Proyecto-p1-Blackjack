#include "Mano.h"
Mano::Mano(Mazo* m) : mazo(m)
{   

		cartUsadas = 0;
		for (int i = 0; i < 10; i++) {
			cartas[i] = mazo->tomarCarta(); // Inicializar con cartas del mazo
		}
	}



Mano::Mano() {
	cartUsadas = 0;
	//mazo = nullptr;
	for (int i = 0; i < 10; i++) {
		cartas[i] = nullptr; // Inicializar todas las cartas como nulas
	}
}

Mano::Mano(int cartUsadasArchi, Carta* cartasArchi[10])
{
	cartUsadas = cartUsadasArchi;
	for (int i = 0; i < 10; i++) {
		cartas[i] = cartasArchi[i];
	}
}


Mano::~Mano()
{
	for (int i = 0; i < 10; i++) {
		if (cartas[i] != nullptr)
			delete this->cartas[i];
	}
}

void Mano::agregarCarta(Carta* nuevaCarta) {
	if (cartUsadas < 10) {
		cartas[cartUsadas] = nuevaCarta;
		cartUsadas++;
	}
}


bool Mano::limpiar()
{
	for (int i = 0; i < cartUsadas; i++) {
		cartas[i] = nullptr; //podemos usarlo para la siguiente partida, por eso no se elimina el vector
		cartUsadas = 0;
	}
	if (cartas[0] == nullptr)return true;
	else return false;
}

int Mano::getPuntos()
{
	int sumaPuntosCartas = 0;
	for (int i = 0; i < cartUsadas; i++) {
		sumaPuntosCartas += cartas[i]->getValor();
	}
	return sumaPuntosCartas;
}

Carta* Mano::ultimaCarta() {
	if ( cartUsadas== 0) {
		return nullptr; 
	}
	return cartas[cartUsadas - 1]; 
}


Mazo* Mano::getMazo() { return mazo; }

void Mano::voltea2()
{
	cartas[1]->voltear();
}

std::string Mano::toStringMano()
{
	std::stringstream s;
	for (int i = 0; i < cartUsadas; i++) {
		s <<"  " << cartas[i]->Mostrar()<< "  ";
	}
	return s.str();
}

Carta* Mano::getCarta()
{
	for (int i = 0; i < cartUsadas; i++) {
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
	file << cartUsadas << '\t';
	for (int i = 0; i < cartUsadas; i++) {
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

