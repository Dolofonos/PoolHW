#ifndef POOL_GAMECONTROLLER_H
#define POOL_GAMECONTROLLER_H
#include <iostream>
#include "Ball.h"
#include "Wall.h"
#include "Hole.h"
#include <SFML/Graphics.hpp>
class GameController
{
public:
    static size_t points_created;
    static Ball *balls;
    static size_t balls_count;
    static Wall *walls;
    static size_t walls_count;
    static Hole *holes;
    static size_t holes_count;
    static sf::RenderWindow *window;

    GameController(sf::RenderWindow *_window);
    GameController();

    static void update();
};


#endif //POOL_GAMECONTROLLER_H
