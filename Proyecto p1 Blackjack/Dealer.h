#ifndef DEALER_H
#define DEALER_H
#include "JugadorGenerico.h"
class Dealer :
    public JugadorGenerico
{
private:
    std::string name="Dealer";
public:
    Dealer(Mano* m);
    Dealer();
    ~Dealer();
    void volteaSegunda();
    Carta* pedirCarta();
    void recibirCarta(Carta*);
    bool sePaso();
    int getPuntos();
    Mano* getMano(); 
    bool debePedirCarta(); 

};
#endif 
