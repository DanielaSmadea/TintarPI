#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"
#include "entity.h"
#include "player.h"
#include "piesa.h"
#include "meniu.h"
#include <iostream>
using namespace std;
class game : public entity
{
    public:
        game();
        ~game();
        void run();
    private:
        void makeBoard();
        void handleMousePressed();


        void draw();
        void update();
        void processEvents();
        bool putPiece(player&);
        bool makeCar(player&);
        void iaPiesaDeLa(player&);
        void updatePieceIsInBox(player&);

        sf::RenderWindow window;
        vector<sf::RectangleShape> lines;
        vector<sf::RectangleShape> boxes;
        vector<bool> pieceIsInBox;
        class meniu Meniu;
        sf::Sprite background;
        sf::Texture backTexture;
        player p1,p2;
        piesa pies;

};

#endif // GAME_H
