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

std::string Carta::Mostrar() const{
    std::stringstream s;
    if (bocaAbajo) {
        s << "Carta boca abajo" << std::endl;
        s<< "  ----------------------  " << std::endl;
        s<< "  |\t" << "        " << "\t|" << std::endl;
        s<< "  |\t" << "        " << "\t|" << std::endl;
        s<< "  |\t" << "        " << "\t|" << std::endl;
        s<< "  |\t" <<  "Desconocida" << "  " << "\t|" << std::endl;
        s<< "  |\t" << "        " << "\t|" << std::endl;
        s<< "  |\t" << "        " << "\t|" << std::endl;
        s<< "  |\t" << "        " << "\t|" << std::endl;
        s<< "  ----------------------  " << std::endl;
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
        s<< "  ----------------------  " << std::endl;
        s<< "  |" << paloStr << "\t\t|" << std::endl;
        s<< "  |\t" << "        " << "\t|" << std::endl;
        s<< "  |\t" << "        " << "\t|" << std::endl;
        s<< "  |\t" << "    " << valor << "    " << "\t|" << std::endl;
        s<< "  |\t" << "        " << "\t|" << std::endl;
        s<< "  |\t" << "        " << "\t|" << std::endl;
        s<< "  |\t\t" << paloStr << std::endl;
        s<< "  ----------------------  " << std::endl; 
    }
}
bool Carta::estaBocaAbajo() {
    return bocaAbajo;
}

void Carta::setValor(int v) { valor = v; }
