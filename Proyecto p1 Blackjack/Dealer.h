#ifndef DEALER_H
#define DEALER_H
#include "JugadorGenerico.h"
class Dealer :
    public JugadorGenerico
{
public:
    Dealer(Mano* m,std::string name);
    /*Dealer();*/
    ~Dealer();
    void volteaSegunda();
    Carta* pedirCarta();
    void recibirCarta(Carta*);
    bool sePaso();
    int getPuntos();
    Mano* getMano(); 
    bool debePedirCarta(); 
    JugadorGenerico* leerJugadorGenerico(std::ifstream& file);
};
#endif 
