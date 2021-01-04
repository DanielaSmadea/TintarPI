#ifndef PLAYER_H
#define PLAYER_H
#include "piesa.h"
#include <vector>

class player
{
    public:
        player();
        ~player();
        void addPiesa(piesa&);
        void initiateWithAllPieces(sf::RenderWindow&);
        void drawPieces(sf::RenderWindow&);
        std::vector<piesa> pieseDePus;
        std::vector<std::pair<piesa,bool>>piesePeTabla;  //piese pe tabla : bool pentru a vedea daca se afla in car piesa
        //setters & getters
        void setTurn(bool t){turn = t;}
        bool getTurn(){return turn;}

        void setNumber(int nr){number = nr;}
        int getNumber(){return number;}
    private:
        bool turn = false;
        int numarPiese;
        int number;


};

#endif // PLAYER_H
