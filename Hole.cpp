#include "Hole.h"

Hole::Hole(sf::Vector2f _position, float _radius) {
    position = _position;
    holeRadius = _radius;
    drawable.setRadius(holeRadius);
    drawable.setOrigin(holeRadius, holeRadius);
    drawable.setPosition(position);
}

Hole::Hole() : Hole(sf::Vector2f (0, 0), 30)
{

}

void Hole::update() {
    drawable.setPosition(position);
    drawable.setFillColor(sf::Color::Black);
}
