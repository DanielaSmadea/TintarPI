#include "piesa.h"

piesa::piesa()
{
    circle.setRadius(20);
    moveUp = true;
    moveDown = true;
    moveRight = true;
    moveLeft = true;
}
piesa::~piesa()
{
    //dtor
}
void piesa::createPiesa(int numberPlayer)
{
    if(numberPlayer == 1)
        circle.setFillColor(sf::Color::Red);
    else
        circle.setFillColor(sf::Color::Blue);
}
void piesa::draw(sf::RenderWindow& window)
{
    window.draw(circle);
}
