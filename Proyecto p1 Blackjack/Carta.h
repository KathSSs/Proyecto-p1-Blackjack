#ifndef CARTA_H
#define CARTA_H
#include <iostream>
#include <string> 

enum Palo {
    ESPADAS = 1,
    CORAZONES,
    DIAMANTES,
    TREBOLES
};

enum ValorC {
    AS = 1, //comentar a katy
    DOS = 2,
    TRES = 3,
    CUATRO = 4,
    CINCO = 5,
    SEIS = 6,
    SIETE = 7,
    OCHO = 8,
    NUEVE = 9,
    DIEZ = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13
};
class Carta
{
private:
    int valor; 
    Palo palo; 
    bool bocaAbajo; 
public:
    Carta(int v, Palo p, bool abajo);
    Carta();
    ~Carta();
    int getValor() const;
    Palo getPalo() const;
    void voltear();
    bool estaBocaAbajo(); 
    void Mostrar() const; //metodo de prueba de la clase 


};

#endif CARTA_H
