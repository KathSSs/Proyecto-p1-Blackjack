#ifndef DEALER_H
#define DEALER_H
#include "JugadorGenerico.h"
class Dealer :
    public JugadorGenerico
{
public:
    //constructor parametrizado
    Dealer(Mano* m,std::string name);
    /*Dealer();*/
    //destructor
    ~Dealer();
    //voltea la segunda carta 
    void volteaSegunda();
    //Pide carta si cumple las condición de: puntos<16
    Carta* pedirCarta();
    //recibe una carta
    void recibirCarta(Carta*);
    //Encargado de verificar que puntaje no se exeda segun las reglas
    bool sePaso();
    //retorna los puntos
    int getPuntos();
    //retorna la mano con sus cartas
    Mano* getMano(); 
    //Para ulima ronda con lso jugadores
    bool debePedirCarta(); 
    //archivo para leer al jugador tipo dealer
    JugadorGenerico* leerJugadorGenerico(std::ifstream& file);
};
#endif 
