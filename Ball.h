#ifndef POOL_BALL_H
#define POOL_BALL_H
#include "GameObject.h"

class Ball : public GameObject
{
private:
    // PHYSIC CONSTANTS
    const float m_mass = 1;
    const float m_friction_value = 0.2;
    const float m_deceleration = m_mass * m_friction_value;
    const float m_elasticValue = 0.6;
    ///////////////////
    // BALL PROPERTIES
    float m_radius;
    bool isMoving;
    ///////////////////
    sf::Vector2f m_speed;

public:
    void addForce(sf::Vector2f force);
    void update() override;
    void move(sf::Vector2f distance);
    void hitCheck();

};


#endif //POOL_BALL_H
