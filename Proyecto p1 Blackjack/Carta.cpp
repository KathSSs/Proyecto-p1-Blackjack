#include "Carta.h"

Carta::Carta(int v, Palo p, bool abajo) :
	valor{ v }, palo{ p }, bocaAbajo{ abajo } {}

Carta::Carta(): valor(AS), palo(ESPADAS), bocaAbajo(true) {}

Carta::~Carta() {}
int Carta::getValor() const {
	return valor;
}
Palo Carta::getPalo() const { return palo; }
void Carta::voltear() { bocaAbajo = !bocaAbajo; }

void Carta::Mostrar() const{
    if (bocaAbajo) {
        std::cout << "Carta boca abajo" << std::endl;
    }
    else {
        std::string paloStr;
        switch (palo) {
        case Palo::ESPADAS:
            paloStr = "Espadas";
            break;
        case Palo::CORAZONES:
            paloStr = "Corazones";
            break;
        case Palo::DIAMANTES:
            paloStr = "Diamantes";
            break;
        case Palo::TREBOLES:
            paloStr = "Treboles";
            break;
        default:
            paloStr = "Desconocido";
            break;
        }

        std::cout << "Valor: " << valor << ", Palo: " << paloStr << std::endl;
    }
}
