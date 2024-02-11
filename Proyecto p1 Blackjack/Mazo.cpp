#include "Mazo.h"

Mazo::Mazo() : canCartas(52) {
    for (int i = 0; i < canCartas; i++) {
        cartas[i] = nullptr; 
    }
    inicializar();
}


Mazo::~Mazo() {
    // Liberar la memoria de cada carta
    for (int i = 0; i < canCartas; ++i) {
        delete cartas[i];
    }
}

void Mazo::inicializar() {
    /*int cantidad = 0; */
    // Crear el mazo completo con 52 cartas
    int pos = 0;
    for (int palo = ESPADAS; palo <= TREBOLES; ++palo) {
        for (int valor = AS; valor <= KING; ++valor) {
            cartas[pos++] = new Carta(valor, static_cast<Palo>(palo), false);
           /* cantidad++;*/
        }
    }
}

void Mazo::barajar() {
    std::random_device dev;
    std::mt19937 rng(dev());

    for (int i = canCartas - 1; i >= 0; --i) { 
        std::uniform_int_distribution<int> distribucion(0, i);
        int j = distribucion(rng);

        // Intercambiar cartas[i] y cartas[j] 
        Carta* tmp = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = tmp;
    }
}

Carta* Mazo::tomarCarta() {
    if (canCartas >= 0) {
        // Decrementar la cantidad de cartas disponibles
        canCartas--;
        return cartas[canCartas];
    }
    else {
        std::cout << "Error: El mazo está vacío." << std::endl;
        return nullptr;
    }
}


void Mazo::mostrarMazo() {
    for (int i = 0; i < canCartas; i++) {
        cartas[i]->Mostrar(); // Llamar al método Mostrar de cada carta
    }
}