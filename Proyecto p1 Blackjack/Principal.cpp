#include "Carta.h"
#include "Mazo.h"
int main() {

	Carta c; 
	Carta c2(AS, ESPADAS, false); 
	Mazo m;


	c.Mostrar();
	c2.Mostrar(); 
	std::cout << "MIEDO TERROR " << std::endl; 
	m.inicializar(); 
	m.barajar(); 
	for (int i = 0; i < 5; ++i) {
		Carta* carta = m.tomarCarta();
		carta->Mostrar();
	}


	return 0;
}