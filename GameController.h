#ifndef POOL_GAMECONTROLLER_H
#define POOL_GAMECONTROLLER_H
#include <iostream>
#include "GameObject.h"

class GameController
{
private:
    static size_t m_access_points_created;
    static GameObject *m_gameObjects;
    static size_t gameObjectsCount;
    static sf::RenderWindow *window;
public:
    GameController();

    static void update();
    static void draw();
};


#endif //POOL_GAMECONTROLLER_H
