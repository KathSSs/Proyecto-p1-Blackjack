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
};

