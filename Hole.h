#ifndef POOL_HOLE_H
#define POOL_HOLE_H


#include <SFML/Graphics/CircleShape.hpp>

class Hole
{
public:
    sf::CircleShape drawable;
    sf::Vector2f position;
    float holeRadius;
    Hole(sf::Vector2f _position, float _radius);
    Hole();
    void update();
};


#endif //POOL_HOLE_H
