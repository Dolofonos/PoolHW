#include "Ball.h"
#include <cmath>

void Ball::addForce(sf::Vector2f force)
{
    m_speed = sf::Vector2f(force.x/m_mass,force.y/m_mass);
    isMoving = true;
}

void Ball::update()
{
    hitCheck();
    move(m_speed);
    m_speed = sf::Vector2f(m_speed.x * m_deceleration, m_speed.y * m_deceleration);
    float speed = sqrt(m_speed.x * m_speed.x + m_speed.y * m_speed.y);
    if (speed < 0.5)
    {
        m_speed.y = 0, m_speed.x = 0;
        isMoving = false;
    }
}

void Ball::move(sf::Vector2f distance)
{

}

void Ball::hitCheck()
{

}



