#include "Meniu.h"

meniu::meniu(float w,float h)
{
width = w;
height = h;
visibility = true;
}
void meniu::init()
{
    font.loadFromFile("Resources/fondul.ttf");
    numarulDeElementeDinMeniulActual = 3;
    for(int i = 0;i < numarulDeElementeDinMeniulActual;i++)
    {
        Meniu[i].setCharacterSize(40);
        Meniu[i].setFont(font);
        Meniu[i].setFillColor(sf::Color::White);
        Meniu[i].setPosition(sf::Vector2f(width/1.3, height/(numarulDeElementeDinMeniulActual + 2) *(i+1)));
    }
elementulSelectat = 0;
Meniu[elementulSelectat].setFillColor(sf::Color::Red);

}
void meniu::moveUp()
{
    if(elementulSelectat - 1 >= 0)
    {
        Meniu[elementulSelectat].setFillColor(sf::Color::White);
        elementulSelectat--;
        Meniu[elementulSelectat].setFillColor(sf::Color::Red);
    }
    else
    {
        Meniu[elementulSelectat].setFillColor(sf::Color::White);
        elementulSelectat = numarulDeElementeDinMeniulActual-1;
        Meniu[elementulSelectat].setFillColor(sf::Color::Red);
    }
}
void meniu::moveDown()
{
    if(elementulSelectat + 1 < numarulDeElementeDinMeniulActual)
    {
        Meniu[elementulSelectat].setFillColor(sf::Color::White);
        elementulSelectat++;
        Meniu[elementulSelectat].setFillColor(sf::Color::Red);
    }
    else
    {
        Meniu[elementulSelectat].setFillColor(sf::Color::White);
        elementulSelectat = 0;
        Meniu[elementulSelectat].setFillColor(sf::Color::Red);
    }
}
void meniu::drawMainMenu(sf::RenderWindow& window)
{
    numarulDeElementeDinMeniulActual = 3;
    for(int i = 0; i < numarulDeElementeDinMeniulActual; i++)
        window.draw(Meniu[i]);
    Meniu[0].setString(" Play");
    Meniu[1].setString(" Options");
    Meniu[2].setString(" Exit");

}
