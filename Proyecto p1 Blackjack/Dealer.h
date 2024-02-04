#pragma once
#include "JugadorGenerico.h"
class Dealer :
    public JugadorGenerico
{
private:

public:
    Dealer(Mano* m, std::string name);
    ~Dealer();
    void volteaSegunda();
    Carta* pedirCarta();
    bool sePaso();
    int getPuntos();
    std::string getName();
    void setNickName(std::string);


};

