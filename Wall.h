#ifndef POOL_WALL_H
#define POOL_WALL_H
#include <SFML/Graphics.hpp>

class Wall
{
public:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::RectangleShape drawable;
    Wall(sf::Vector2f _position, sf::Vector2f _size);
    Wall();
    void update();
};


#endif //POOL_WALL_H
