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
        std::cout << "  ----------------------  " << std::endl;
        std::cout << "  |\t" << "        " << "\t|" << std::endl;
        std::cout << "  |\t" << "        " << "\t|" << std::endl;
        std::cout << "  |\t" << "        " << "\t|" << std::endl;
        std::cout << "  |\t" <<  "Desconocida" << "  " << "\t|" << std::endl;
        std::cout << "  |\t" << "        " << "\t|" << std::endl;
        std::cout << "  |\t" << "        " << "\t|" << std::endl;
        std::cout << "  |\t" << "        " << "\t|" << std::endl;
        std::cout << "  ----------------------  " << std::endl;
    }
    else {
        std::string paloStr;
        switch (palo) {
        case Palo::ESPADAS:{
            paloStr = "Espadas";
            break;
        }
        case Palo::CORAZONES:{
            paloStr = "Corazones";
            break;
        }
        case Palo::DIAMANTES:{
            paloStr = "Diamantes";
            break;
        }
        case Palo::TREBOLES:{
            paloStr = "Treboles";
            break;
        }
        default: {
            paloStr = "Desconocido";
            break;}
        }
        std::cout << "  ----------------------  " << std::endl;
        std::cout << "  |" << paloStr << "\t\t|" << std::endl;
        std::cout << "  |\t" << "        " << "\t|" << std::endl;
        std::cout << "  |\t" << "        " << "\t|" << std::endl;
        std::cout << "  |\t" << "    " << valor << "    " << "\t|" << std::endl;
        std::cout << "  |\t" << "        " << "\t|" << std::endl;
        std::cout << "  |\t" << "        " << "\t|" << std::endl;
        std::cout << "  |\t\t" << paloStr << std::endl;
        std::cout << "  ----------------------  " << std::endl; 
    }
}
