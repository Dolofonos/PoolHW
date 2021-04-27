#ifndef POOL_BALL_H
#define POOL_BALL_H
#include <SFML/Graphics.hpp>
class Ball
{
private:
    // PHYSIC CONSTANTS
    const float deceleration = 0.99;
    const float elasticValue = 0.7;
    float radius;
    ///////////////////


public:
    void add_force(sf::Vector2f force);
    void update();
    void hit_check();
    Ball(sf::Vector2f _position, float _radius);
    Ball();
    sf::CircleShape drawable;
    sf::Vector2f speed;
///////////////////
// BALL PROPERTIES
    int printScoreNumber;
    sf::Vector2f position;
    bool is_moving;
    bool is_goal;
};


#endif //POOL_BALL_H
