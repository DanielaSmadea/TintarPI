#ifndef PIESA_H
#define PIESA_H
#include "SFML/Graphics.hpp"
#include "entity.h"

class piesa : public entity
{
    public:
        piesa();
        ~piesa();
        void createPiesa(int playerNumber);
        void draw(sf::RenderWindow&);
    private:
        bool moveUp;
        bool moveDown;
        bool moveRight;
        bool moveLeft;
};

#endif // PIESA_H
