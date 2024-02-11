#include <iostream>
#include "Juego.h"

int main() {
	int opcion = 0; 
	Juego partida1;
	Lista lis; 
	do {
		switch (opcion)
		{
		case 1: {
			partida1.jugar(); //jugar
			break;
		}
		case 2: { 
			lis.leerLista(); 
			//break; 
		}
		default:
			break;
		}
	} while (opcion <= 2);
	
  


	return 0;
}