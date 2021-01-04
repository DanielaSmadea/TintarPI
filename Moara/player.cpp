#include "player.h"

player::player()
{
}

player::~player()
{
    //dtor
}
void player::addPiesa(piesa& p)
{
    pieseDePus.push_back(p);
    numarPiese++;
}
void player::initiateWithAllPieces(sf::RenderWindow& window)
{
    piesa pies;
    int j = 0;
    for(int i=1; i<=9; i++)
    {
        j+=3;
        pies.createPiesa(number);
        pies.circle.setPosition(100 * number,window.getSize().y-200-pies.circle.getRadius()*j);
       
        addPiesa(pies);
    }

}
void player::drawPieces(sf::RenderWindow& window)
{
    int counter = 0;
    for(auto i:pieseDePus)
        i.draw(window);
    for(auto i:piesePeTabla)
        i.first.draw(window);
}
