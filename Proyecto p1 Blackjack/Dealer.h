#pragma once
#include "JugadorGenerico.h"
class Dealer :
    public JugadorGenerico
{
private:
    std::string name;
public:
 
    Dealer(Mano* m);
    ~Dealer();
    void volteaSegunda();
    Carta* pedirCarta();
    bool sePaso();
    int getPuntos();
    std::string getName();
    std::string toString();
    Mano* getMano(); 


};

