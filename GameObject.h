#ifndef POOL_GAMEOBJECT_H
#define POOL_GAMEOBJECT_H
#include <SFML/Graphics.hpp>

class GameObject
{
private:
    sf::Vector2f position;
public:
    virtual void update() = 0;
    virtual void getDrawable() = 0;
};


#endif //POOL_GAMEOBJECT_H
