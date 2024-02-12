#ifndef CARTA_H
#define CARTA_H
#include <iostream>
#include <string> 
#include <sstream>
#include <fstream>

enum Palo { //posible forma que tendra la carta
    ESPADAS = 1,
    CORAZONES,
    DIAMANTES,
    TREBOLES
};

enum ValorC {
    AS = 1, //Enumeración de posibles valores de la carata
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
    //Constrictor parametrizado
    Carta(int v, Palo p, bool abajo);
    //constructor por defecto
    Carta();
    //destructor
    ~Carta();
    //retorna el valro de la carta
    int getValor() const;
    //hace posble cambiar el valor de la cart
    void setValor(int );
    //retorna el palo
    Palo getPalo() const;
    //voltea la carta del dealer
    void voltear();
    //Para saber si esta arriba o abajo la carta actual
    bool estaBocaAbajo(); 
    //muestra la carta 
    std::string Mostrar() ; //metodo que muestra una sola carta dependiendo de su condición  

    //Archivos de carta
    void guardarCarta(std::ofstream& salida);
    static Carta* leerCarta(std::ifstream& entrada);

};

#endif 
