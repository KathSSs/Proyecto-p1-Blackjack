#include <iostream>
#include "Juego.h"

int main() {
	
    int numJugadores;
    std::cout << "Ingrese el n�mero de jugadores: ";
    std::cin >> numJugadores;

    Juego juego(numJugadores);
    juego.jugar();

  


	return 0;
}