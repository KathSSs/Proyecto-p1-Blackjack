#include "Juego.h"

Juego::Juego(int numJug) : numJugadores(numJug) {
    mazo = new Mazo();
    mazo->inicializar();
    mazo->barajar();

    jugadores = new Jugador * [numJugadores];
    for (int i = 0; i < numJugadores; ++i) {
        std::string nombre;
        std::cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        std::cin >> nombre;
        jugadores[i] = new Jugador(nombre);
    }
}
    Juego::~Juego() {
        delete mazo;
        for (int i = 0; i < numJugadores; ++i) {
            delete jugadores[i];
        }
        delete[] jugadores;
        delete dealer;
    }


    void Juego::jugar() {

        // Repartir cartas iniciales
        for (int i = 0; i < numJugadores; ++i) {
            jugadores[i]->recibirCarta(mazo->tomarCarta());
            jugadores[i]->recibirCarta(mazo->tomarCarta());
        }
        dealer->recibirCarta(mazo->tomarCarta());
        dealer->recibirCarta(mazo->tomarCarta());

        // Mostrar manos iniciales
        std::cout << "Mano del dealer: " << dealer->getMano() << std::endl;
        for (int i = 0; i < numJugadores; ++i) {
            std::cout << "Mano de " << jugadores[i]->getName()<< ": " << jugadores[i]->getMano() << std::endl;
        }

        // Turno de los jugadores
        for (int i = 0; i < numJugadores; ++i) {
            while (jugadores[i]->quiereCarta()) {
                jugadores[i]->recibirCarta(mazo->tomarCarta());
                std::cout << "Mano de " << jugadores[i]->getName() << ": " << jugadores[i]->getMano() << std::endl;
            }
        }

        // Turno del dealer
        while (dealer->debePedirCarta()) {
            dealer->recibirCarta(mazo->tomarCarta());
        }
        std::cout << "Mano del dealer: " << dealer->getMano() << std::endl;

        // Determinar ganadores
        for (int i = 0; i < numJugadores; ++i) {
            if (jugadores[i]->getPuntos() > 21) {
                std::cout << jugadores[i]->getName() << " se pasó de 21. Pierde." << std::endl;
            }
            else if (dealer->getPuntos() > 21 || jugadores[i]->getPuntos() > dealer->getPuntos()) {
                std::cout << jugadores[i]->getName() << " gana." << std::endl;
            }
            else if (jugadores[i]->getPuntos() == dealer->getPuntos()) {
                std::cout << jugadores[i]->getName() << " empata con el dealer." << std::endl;
            }
            else {
                std::cout << jugadores[i]->getName() << " pierde." << std::endl;
            }
        }
    }
