#include "Mazo.h"

Mazo::Mazo() : cartas{nullptr}, canCartas{0}
{}
Mazo::~Mazo() { 
    if (cartas != nullptr) {
        delete[] cartas;
    }
}

void Mazo::inicializar() {
    // Crear el mazo completo con 52 cartas, espero en Dios
    canCartas = 52;
    cartas = new Carta[canCartas];
    int pos = 0;
    for (int palo = ESPADAS; palo <= TREBOLES; ++palo) {
        for (int valor = AS; valor <= KING; ++valor) {
            cartas[pos++] = Carta(valor, static_cast<Palo>(palo),false );
        }
    }
}

void Mazo::barajar() {
    std::random_device dev;
    std::mt19937 rng(dev());

    for (int i = canCartas - 1; i > 0; --i) {
        std::uniform_int_distribution<int> distribucion(0, i);
        int j = distribucion(rng);

        // Intercambiar cartas[i] y cartas[j] 
        Carta tmp = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = tmp;
    }
}
Carta* Mazo::tomarCarta() {
   //no es necesario barajar cada vez que se toma la carta, asi que lo borré
    if (canCartas > 0) {
        Carta* nuevaCarta = new Carta(cartas[canCartas - 1].getValor(), cartas[canCartas - 1].getPalo(), cartas[canCartas - 1].estaBocaAbajo());
        canCartas--;
        return nuevaCarta;
    }
    else {
        std::cerr << "Error: El mazo está vacío." << std::endl;
        return nullptr;
    }
    
}

void Mazo::mostrarMazo() {

    for (int i = 0; i < canCartas; i++) {
        cartas[i].Mostrar();
    }


}