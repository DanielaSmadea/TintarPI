#ifndef MENIU_H
#define MENIU_H
#include<SFML/Graphics.hpp>
#define maximElementeMeniu 4
class meniu
{
    public:
        meniu(float w=0, float h=0);
        int elementulSelectat;
        int numarulDeElementeDinMeniulActual;
        void drawMainMenu(sf::RenderWindow &window);
        void init();
        void moveUp();
        void moveDown();
        void setWidth(float x){width = x;}
        void setHeight(float y){height = y;}
        float getWidth(){return width;}
        bool getVisibility(){return visibility;}
        void setVisibility(bool value){visibility = value;}
    private:
        sf::Font font;
        sf::Text Meniu[maximElementeMeniu];
        float width;
        bool visibility;
        float height;

};

#endif // MENIU_H
