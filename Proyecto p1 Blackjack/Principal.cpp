#include <iostream>
#include "Juego.h"
//
//Universidad Nacional
// Curso: Programaci�n 1
// 
//Estudiantes:
//Camila Fallas Jim�nez 
//Katherin Jara Arrollo
//
//Direcci�n del git: https://github.com/KathSSs/Proyecto-p1-Blackjack/tree/master


int main() {
	std::cout << "Recuerde que si el programa da errores\n   \tGANA LA CASA" << std::endl; 
	//inicializaci�n de la clase juego
	Juego p1;
	//llamada al metodo menu, que conforma las intrucciones y posibles acciones del jugador
	p1.menu(); 
	return 0;
}