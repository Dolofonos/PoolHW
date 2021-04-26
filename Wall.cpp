#include "Wall.h"

Wall::Wall(sf::Vector2f _position, sf::Vector2f _size)
{
    position = _position;
    size = _size;
    drawable.setSize(size);
    drawable.setPosition(position);
}

Wall::Wall() : Wall(sf::Vector2f(0,0), sf::Vector2f(50,50))
{

}

void Wall::update()
{
    drawable.setPosition(position);
    drawable.setSize(size);
    drawable.setFillColor(sf::Color(100,140,80));
}
