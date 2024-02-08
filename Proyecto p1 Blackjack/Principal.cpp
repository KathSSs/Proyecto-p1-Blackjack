#include "Carta.h"
#include "Mazo.h"
#include "Mano.h"
int main() {
	int opci = 0;

	Carta c; 
	Carta c2(AS, ESPADAS, false); 
	Mazo m;
	Mano man;

	c.Mostrar();
	c2.Mostrar(); 
	std::cout << "MIEDO TERROR " << std::endl; 
	m.inicializar(); 
	m.barajar(); 
	//m.mostrarMazo(); metodo para comprobar que se hicieran las 52 cartas



	//for (int i = 0; i < 5; ++i) {
	//	//Carta* carta = m.tomarCarta();
	//	//carta->Mostrar();

	//
	//	//man.getPuntos();


	//}

	switch (opci!=3)
	{
	case 1: { //nuevo juego
		break;
	}
	case 2: { //cargar partida
		break;
	}
	case 3: { //salir
		break;
	}
	}
	
	

	return 0;
}