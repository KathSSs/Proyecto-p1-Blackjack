#ifndef CARTA_H
#define CARTA_H
#include <iostream>
#include <string> 
#include <sstream>
#include <fstream>

enum Palo {
    ESPADAS = 1,
    CORAZONES,
    DIAMANTES,
    TREBOLES
};

enum ValorC {
    AS = 1, //comentar a camila 
    DOS = 2,
    TRES = 3,
    CUATRO = 4,
    CINCO = 5,
    SEIS = 6,
    SIETE = 7,
    OCHO = 8,
    NUEVE = 9,
    DIEZ = 10,
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
    void setValor(int );
    Palo getPalo() const;
    void voltear();
    bool estaBocaAbajo(); 
    std::string Mostrar() const; //metodo que muestra una sola carta dependiendo de su condición  
    void guardarCarta(std::ofstream& salida);
    static Carta* leerCarta(std::ifstream& entrada);

};

#endif CARTA_H
