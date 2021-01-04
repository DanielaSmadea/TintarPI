#ifndef ENTITY_H
#define ENTITY_H
#include "SFML/Graphics.hpp"

class entity
{
    public:
        entity();
        ~entity();
        sf::RectangleShape rect;
        sf::CircleShape circle;
        sf::Text text;
};

#endif // ENTITY_H
